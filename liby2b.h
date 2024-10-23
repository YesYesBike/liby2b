#ifndef	__Y2B_LIB__
#define	__Y2B_LIB__

#include <ctype.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* ARGBEGIN/ARGEND macro was provided from plan9port and rewritten.
 * 
 * Check out the license
 * https://github.com/9fans/plan9port/blob/master/src/lib9/LICENSE
 *
 * */

//TODO: replace isprint()
#define ARGBEGIN	for (;argv[1] && argv[1][0] == '-' && argv[1][1]; argc--, argv++) {\
						int _arg = 0;\
						char *_args = &argv[1][1];\
						if (_args[0] == '-' && _args[1] == '\0') {\
							argc--; argv++; break;\
						}\
						while ((_arg=*_args) && isprint(_arg) && _args++)\
							switch (_arg)
#define ARGEND		}

/* error */
void err_exit(char *fmt, ...);


/* string */


#endif	/* __Y2B_LIB__ */