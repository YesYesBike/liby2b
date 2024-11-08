#ifndef	__Y2B_LIB__
#define	__Y2B_LIB__

#include <ctype.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* 
 * ARG macros were provided from plan9port libc.h
 * 
 * Check out the license
 * https://github.com/9fans/plan9port/blob/master/src/lib9/LICENSE
 *
 * */
extern char *argv0;
#define ARGBEGIN	for ((argv0?0:(argv0=*argv)),argv++,argc--;\
					*argv && **argv == '-' && argv[0][1];\
					argv++,argc--) {\
					char _argc = 0;\
					char *_args, *_argt;\
					_args = &argv[0][1];\
					if (_args[0] == '-' && _args[1] == '\0') {\
						argc--; argv++; break;\
					}\
					while ((_argc=*_args) && ++_args)\
					switch (_argc)
#define ARGEND		}
#define ARGC()		_argc
#define	ARGF()		(_argt=_args, _args="",\
					(*_argt? _argt: argv[1]? (argc--, *++argv): 0))

#define nelem(x)	(sizeof(x)/sizeof((x)[0]))
#define buf_clear()	while(getchar() != '\n')

/* error */
void err_exit(char *fmt, ...);


/* string */
char *str_copy(char *restrict dst, size_t size, const char *restrict src);


#endif	/* __Y2B_LIB__ */
