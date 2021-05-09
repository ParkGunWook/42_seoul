#include <stdio.h>

int main()
{
	double d = 123.456;
	printf("%#-10f\n", d);
	printf("%#010f\n", d);
	printf("%##10f\n", d);
	printf("%# 10f\n", d);
	printf("%#+10f\n", d);
}
