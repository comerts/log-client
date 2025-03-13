/*
 * defs.h
 *
 *  Created on: Nov 2, 2011
 *      Author: root
 */

#ifndef DEFS_H_
#define DEFS_H_


#include <stdio.h>
#define PRINT_LINE_NOW() printf("")	//{printf("%s:%d\n", __FUNCTION__, __LINE__); fflush(stdout);}
#define PRINT_STR(str) {printf("%s ( %s:%d )\n", str, __FILE__, __LINE__); fflush(stdout);}

#endif /* DEFS_H_ */
