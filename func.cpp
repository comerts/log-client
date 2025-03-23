/*
 * func.cpp
 *
 *  Created on: Nov 3, 2011
 *      Author: root
 */

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/signal.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

#include <net/if.h>
#include <net/route.h>		// struct rtentry
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <net/if_arp.h>
#include <linux/sockios.h>
#include <sys/ioctl.h>

#include <stdarg.h>
#include <errno.h>
#include <time.h>

#include "netset.h"
#include "conf.h"

#include "func.h"

int DirectOutput2LogFile()
{
	static int _stdoutBackup = -1;
	if(-1 == _stdoutBackup)
	{
		_stdoutBackup = dup(1);
	}
	int fd = open("/tmp/serialLog_2.txt", O_RDWR | O_APPEND | O_CREAT, 0666);
	if(fd < 0)
	{
		perror("open failed");
		return -1;
	}
	int retval = dup2(fd, 1);
	if(retval < 0)
	{
		perror("dup2");
		return -1;
	}
	return 0;
}

void PrintBuffer(const uint8_t* buf, uint32_t bufSize)
{
#if 0
	for(uint32_t i=0;i<bufSize; i++)
	{
		printf("%02x ", static_cast<uint8_t>(buf[i]) );
	}
	printf("\n");
	fflush(stdout);
#else
	(void) buf;
	(void) bufSize;
#endif
}

pthread_t startThread(threadFunc func, void* arg)
{
	sched_param sched;
	pthread_attr_t threadAttr;
	pthread_t thread;

	if( (pthread_attr_init(&threadAttr) != 0) )
	{
		perror("pthread_attr_init");
		exit(1);
	}
	if( (pthread_attr_setschedpolicy(&threadAttr, SCHED_RR) != 0) )
	{
		perror("pthread_attr_setschedpolicy");
		exit(1);
	}
	sched.sched_priority = 66;
	if( (pthread_attr_setschedparam(&threadAttr, &sched) != 0) )
	{
		perror("pthread_attr_setschedparam");
		exit(1);
	}
	if( (pthread_create( &thread, &threadAttr, func, reinterpret_cast<void*>(arg) ) != 0) )
	{
		perror("pthread_create - cfg_listening_socket");
		exit(1);
	}
	return thread;
}

void BlockAllSignals()
{
	sigset_t signal_set;
	sigfillset( &signal_set );
	sigdelset(&signal_set, SIGKILL);
	sigdelset(&signal_set, SIGSTOP);
	if(pthread_sigmask( SIG_BLOCK, &signal_set, NULL )<0){
		printf("Block all signals failed: %s-%d\n", strerror(errno), errno);
	}
}

void SendLog(const char* buf)
{
	int logFd;
	struct sockaddr_in logServerAddr;
	log_packet_t* log_pack = (log_packet_t*)malloc(sizeof(log_packet_t));

	log_pack->degree = LOG_PACK_DEGREE_WRITE_SEND;
	log_pack->type = LOG_PACK_TYPE_ALPHA;

	strcpy( log_pack->log_array, "[log-client]" );
	strncat(log_pack->log_array, buf, LOG_BUF_SIZE - 1);
	log_pack->log_array_len = strlen( log_pack->log_array );

	logServerAddr.sin_family = AF_INET;
	logServerAddr.sin_port = htons(INTERNAL_LOG_PORT);
	logServerAddr.sin_addr.s_addr = inet_addr(LOCAL_ADDR);

	if((logFd  = socket(AF_INET, SOCK_DGRAM, 0) ) < 0)
	{
		perror("socket open error");
		exit(1);
	}
	sendto(logFd, (char*)log_pack, sizeof(log_packet_t), 0, (const struct sockaddr*)&logServerAddr, sizeof(logServerAddr));
	free(log_pack);
	close(logFd);
}

void SendLogStringFormat(const char* format, ...)
{
	va_list args;
	va_start (args, format);

	char* logPack = new char[LOG_BUF_SIZE];
	vsnprintf (logPack, LOG_BUF_SIZE, format, args);
	SendLog(logPack);
	delete[] logPack;
	va_end (args);
}

void PRINT_NOW()
{
#if 0
	time_t now = time(NULL);
	printf(" %s\n", ctime(&now));
	fflush(stdout);
#endif
}

