/*
 * main.cpp
 *
 *  Created on: Oct 20, 2011
 *      Author: root
 */

#include <errno.h>
#include <stdio.h>
#include <sys/signal.h>
#include <error.h>
#include <string.h>
#include <unistd.h>

#include "func.h"
#include "sys_conf.h"

int main(int argc, char* argv[])
{
    if (argc < 2)
    {
        printf("Usage: %s <log_string>\r\n", argv[0]);
        return 1;
    }

//	NetCom netCom;

	while(true)
	{
	    SendLogStringFormat("Log: %s", argv[1]);

	    sleep(MAIN_LOOP_SLEEP_TIME);
	}
	return 0;
}

