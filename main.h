#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdlib.h>

typedef struct handls {
	char *p;
	void (*va_items)(va_list arg);
} handls;

int _printf(const char *format, ...);

#endif
