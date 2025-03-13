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

#if 0
extern "C"
{
//add declaration of strlcat, strlcpy, declarations of which indexer cannot find.
extern size_t strlcat(char *__restrict dst, const char *__restrict src,
                      size_t n) __THROW __nonnull ((1, 2));
extern size_t strlcpy(char *__restrict dst, const char *__restrict src,
                      size_t n) __THROW __nonnull ((1, 2));
}
#endif

#endif /* FUNC_H_ */
