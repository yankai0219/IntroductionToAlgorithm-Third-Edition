
/*
* CopyRight(C) Yankai
*/
#ifndef _COMMON_H_
#define _COMMON_H_

#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>


#define _MYDEBUG_ 1
#if _MYDEBUG_
#define DEBUG(fmt,...) printf("YK %s:%d "fmt"",__FILE__,__LINE__,##__VA_ARGS__)
#else
#define DEBUG(fmt,...)
#endif
#endif
