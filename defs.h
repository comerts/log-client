/*
 * defs.h
 *
 *  Created on: Mar 23, 2025
 *      Author: comerts
 */

#ifndef DEFS_H_
#define DEFS_H_


#include <stdio.h>
#define PRINT_LINE_NOW() printf("")	//{printf("%s:%d\n", __FUNCTION__, __LINE__); fflush(stdout);}
#define PRINT_STR(str) {printf("%s ( %s:%d )\n", str, __FILE__, __LINE__); fflush(stdout);}

#endif /* DEFS_H_ */
