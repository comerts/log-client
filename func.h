/*
 * func.h
 *
 *  Created on: Nov 3, 2011
 *      Author: root
 */

#ifndef FUNC_H_
#define FUNC_H_

#include <stdint.h>
#include <pthread.h>

typedef void*(*threadFunc)(void*);

extern void PrintBuffer(const uint8_t* buf, uint32_t bufSize);
extern pthread_t startThread(threadFunc func, void* arg);
extern void BlockAllSignals();
extern int DirectOutput2LogFile();
extern void getFiles(char* bootFile);
extern void SendLog(const char* buf);
extern void SendLogStringFormat(const char* format, ...);
extern void PRINT_NOW();

#endif /* FUNC_H_ */
