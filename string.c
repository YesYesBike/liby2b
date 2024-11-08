#include "liby2b.h"

/* 
 * provided from plan9port ed.c
 * 
 * strcpy, strcpy_s
 *
 * */
char *str_copy(char *restrict dst, size_t size, const char *restrict src)
{
	const char *p1 = src;
	char *p2 = dst;

	while (*p2++ = *p1++) {
		if (p2 >= dst+size)
			p2--;
	}

	return dst;
}
