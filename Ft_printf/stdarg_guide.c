#include <stdarg.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void foo(char *fmt, ...)
{
	va_list ap;
	int d;
	char c, *s;

	va_start(ap, fmt);
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
		default:
			break;
		}
	}
	va_end(ap);
}

int main()
{
	char s1[10] = "sdcsdc";

	foo(s1, "first", "fo", 'a', "second", 2, 'b');
}
