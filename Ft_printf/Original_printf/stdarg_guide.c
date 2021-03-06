#include <stdarg.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void foo(char *fmt, char *fmt2, ...)
{
	va_list ap;
	int d;
	char c, *s;
	double f;
	va_start(ap, fmt2);
	while(*fmt)
	{
		switch (*fmt++)
		{
		case 's':
			s = va_arg(ap, char *);
			printf("string %s\n", s);
			break;
		case 'd':
			d = va_arg(ap, int);
			printf("int %d\n", d);
			break;
		case 'c':
			c = va_arg(ap, int);
			printf("char %c\n", c);
			break;
		case 'f':
			f = va_arg(ap, double);
			printf("double %f\n", f);
			break;
		default:
			break;
		}
	}
	va_end(ap);
}

int main()
{
	char s1[10] = "sdcsdcf";

	foo(s1, "abc", "first", 1, 'a', "second", 2, 'b', 0.31939);
}
