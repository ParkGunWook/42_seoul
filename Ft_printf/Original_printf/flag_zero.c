#include <stdio.h>

int main()
{
	int k = 123;
	double d = 123.456;
	printf("%d\n", k);
	printf("%005d\n", k);
	printf("%0#10f\n", d);
	printf("%0+10d\n", k);
	//printf("%-0d", k);
}
