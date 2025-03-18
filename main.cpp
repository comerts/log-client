/*
 * main.cpp
 *
 *  Created on: Oct 20, 2011
 *      Author: root
 */

#include <stdio.h>
//#include <sys/signal.h>
#include <error.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <signal.h>
#include <syslog.h>
#include <stdlib.h>

#include "func.h"
#include "sys_conf.h"

static void daemonize(void);
static void sig_handler(int signo);

int main(int argc, char* argv[])
{
    bool isDaemon = false;

    if (argc < 2)
    {
        printf("Usage: %s <log_string> [-d]\r\n", argv[0]);
        syslog(LOG_ERR, "Usage: %s <log_string> [-d]", argv[0]);
        return EPERM;
    }
    else if (argc == 3)
    {
        if (strcmp(argv[2], "-d") == 0)
        {
            isDaemon = true;
        }
        else
        {
            printf("Usage: %s <log_string> [-d]\r\n", argv[0]);
            syslog(LOG_ERR, "Usage: %s <log_string> [-d]", argv[0]);
            closelog();
            return EPERM;
        }
    }

    if (isDaemon)
    {
        daemonize();
    }

    struct sigaction new_action;
    struct sigaction old_action;

    /* Set up the structure to specify the new action. */
    new_action.sa_handler = sig_handler;
    (void)sigemptyset(&new_action.sa_mask);
    new_action.sa_flags = 0;

    sigaction(SIGINT, NULL, &old_action);
    if (old_action.sa_handler != SIG_IGN)
    {
        sigaction(SIGINT, &new_action, NULL);
    }

    sigaction(SIGTERM, NULL, &old_action);
    if (old_action.sa_handler != SIG_IGN)
    {
        sigaction(SIGTERM, &new_action, NULL);
    }

//	NetCom netCom;

    static unsigned int log_counter = 0;

	while(true)
	{
	    SendLogStringFormat("Log: %s %d", argv[1], log_counter++);

	    sleep(MAIN_LOOP_SLEEP_TIME);
	}
	return 0;
}

static void daemonize(void)
{
    if (daemon(0, 0) != 0)
    {
        perror("daemon");
        syslog(LOG_ERR, "daemon: %m");
        exit(EXIT_FAILURE);
    }
}

static void sig_handler(int signo)
{
    printf("Caught signal %d\r\n", signo);
    syslog(LOG_INFO, "Caught signal %d\r\n", signo);
    switch (signo)
    {
        case SIGINT:
        case SIGTERM:

            closelog();
            exit(EXIT_SUCCESS);
            break;
        default:
            break;
    }
}
