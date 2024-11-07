#ifndef	__Y2B_LIB__
#define	__Y2B_LIB__

#include <ctype.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* 
 * ARGBEGIN/ARGEND macro was provided from plan9port and rewritten.
 * 
 * Check out the license
 * https://github.com/9fans/plan9port/blob/master/src/lib9/LICENSE
 *
 * */

#define ARGBEGIN	for (;argv[1] && argv[1][0] == '-' && argv[1][1]; argc--, argv++) {\
						char _arg = 0;\
						char *_args = &argv[1][1];\
						if (_args[0] == '-' && _args[1] == '\0') {\
							argc--; argv++; break;\
						}\
						while ((_arg=*_args) && _args++)\
							switch (_arg)
#define ARGEND		}

#define buf_clear()	while(getchar() != '\n')

/* error */
void err_exit(char *fmt, ...);


/* string */
char *str_copy(char *restrict dst, size_t size, char *restrict src);


#endif	/* __Y2B_LIB__ */
