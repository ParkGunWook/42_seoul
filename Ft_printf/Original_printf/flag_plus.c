#include <stdio.h>

int main()
{
	double d = 123.456;
	printf("%+-15f\n", d);
	printf("%+015f\n", d);
	printf("%+#15f\n", d);
	//printf("%+ 15f\n", d);
	printf("%++10f\n", d);
}
