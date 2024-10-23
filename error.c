#include "liby2b.h"

void err_exit(char *fmt, ...)
{
	va_list ap;
	va_start(ap, fmt);
	vfprintf(stderr, fmt, ap);
	va_end(ap);

	fflush(stderr);

	exit(EXIT_FAILURE);
}
