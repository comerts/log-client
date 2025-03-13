#ifndef CONF_H_
#define CONF_H_

#define LOCAL_ADDR						"127.0.0.1"

#define INTERNAL_LOG_PORT				32222

#define DELAY_500_MS					500000
#define DELAY_200_MS					200000
#define DELAY_100_MS					100000
#define DELAY_50_MS						50000
#define DELAY_10_MS						10000

#define LOCAL_LOG_SIZE					512
#define LOG_BUF_SIZE					256
#define LOG_COUNT_CHECK					100
#define MTR_LOG_COUNT_CHECK				100
#define LOG_FILE_MAX_SIZE				0x3FFFF
#define MTR_LOG_FILE_MAX_SIZE			0x1FFFF

#define PRINT_LINE()					printf("\n%s:%s->%d\n", __FILE__, __FUNCTION__, __LINE__)
#define PRINT_LINE_WITHDELAY()			{printf("\n%s:%s->%d\n", __FILE__, __FUNCTION__, __LINE__);usleep(DELAY_50_MS);}
#define PRINT_LINE_IMM()				{printf("\n%s->%d\n", __FUNCTION__, __LINE__);fflush(stdout);}
#define PRINT_LINE_IMMEDIATE()			{printf("\n%s:%s->%d\n", __FILE__, __FUNCTION__, __LINE__);fflush(stdout);}
#define PRINT_MSG(str)					printf("\n<%s>\t%s:%s->%d\n", str, __FILE__, __FUNCTION__, __LINE__)
#define PRINT_WARNING(str)				printf("\nI_WARN_U: %s\t%s:%s->%d\n", str, __FILE__, __FUNCTION__, __LINE__)
#define PRINT_ERROR(str)				printf("\nFATAL ERROR: %s\t%s:%s->%d\n", str, __FILE__, __FUNCTION__, __LINE__)

#define INSMOD_PATH						"/sbin/insmod"

#define LOG_FILE_OLD                    "/var/log/log_previous"
#define LOG_FILE_CURRENT                "/var/log/log_current"
#define MTR_LOG_FILE_OLD                "/var/log/mtr_log_previous"
#define MTR_LOG_FILE_CURRENT            "/var/log/mtr_log_current"

#endif /*CONF_H_*/
