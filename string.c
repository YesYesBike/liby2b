#include "liby2b.h"

/* 
 * provided from plan9port ed.c
 * 
 * strcpy, strcpy_s
 *
 * */
char *str_copy(char *restrict dst, size_t size, char *restrict src)
{
	char *p1, *p2;
	p1 = src;
	p2 = dst;

	while (*p2++ = *p1++) {
		if (p2 >= dst+size)
			p2--;
	}

	return dst;
}
