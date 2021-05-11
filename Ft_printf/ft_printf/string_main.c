#include "libprint.h"

int main()
{
	char str[10] = "abcd";
	//char str2[10] = "efg";
	printf("re : %s\n", str);
	ft_printf("ft : %s\n", str);
	printf("re : %10s\n", str);
	ft_printf("ft : %10s\n", str);
	printf("re : %-10s\n", str);
	ft_printf("ft : %-10s\n", str);
	printf("re : |%.*s|\n", -4, str);
	ft_printf("ft : |%.*s|\n", -4,  str);
	printf("re : |%.*s|\n", 4, str);
	ft_printf("ft : |%.*s|\n", 4,  str);
	printf("re : |%.*s|\n", 3, str);
	ft_printf("ft : |%.*s|\n", 3,  str);

	char *a = (char*)malloc(sizeof(char)* 0);
	printf("%s\n", a);
}
