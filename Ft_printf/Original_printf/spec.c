#include <stdio.h>

int main()
{
	char c = 'c';
	char string[] = "hello, world";
	char string2[10] = {'a', 'b', 35, 29, 8, 27, '\0'};
	int minus_integer = -1;
	int integer = 123;
	int ret_num = 0;
	unsigned int ui = 4000000000;
	int *pointer = &integer;
	double pi = 3.141592;
	printf("%c\n", c);
	ret_num = printf("%s\n", string);
	printf("ret_num : %d\n", ret_num);
	printf("%s123\n", string2);
	printf("%p %p\n", &c, string);
	printf("%d %d\n", integer, minus_integer);
	ret_num = printf("%i %i\n", integer, minus_integer);
	printf("ret_num : %d\n", ret_num);
	printf("%u %u %u\n", integer, ui, minus_integer);
	printf("%x\n", integer);
	ret_num = printf("%X\n", integer);
	printf("ret_num : %d\n", ret_num);
	ret_num = printf("%%\n");
	printf("ret_num : %d\n", ret_num);
	printf("Bonus\n");
	printf("abcabc%n\n", pointer);
	printf("%d\n", *pointer);
	printf("abc%nabc\n", pointer);
	printf("%d\n", *pointer);
	ret_num = printf("%nabcabc\n", pointer);
	printf("%d\n", *pointer);
	printf("ret_num : %d\n", ret_num);
	printf("%s%n\n", string, pointer);
	printf("%d\n", *pointer);
	printf("%f\n", pi);
	//printf("%g\n", integer);
	printf("%g\n", pi);
	printf("%e\n", pi);
	ret_num = printf("");
	printf("ret_num : %d\n", ret_num);
	ret_num = printf(NULL);
	printf("ret_num : %d\n", ret_num);
}
