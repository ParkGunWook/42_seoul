#include "libprint.h"

int main()
{
	char str[15] = "hi im ekwon";
	//char str2[10] = "efg";
	printf("a%.03sa\n", str);
	ft_printf("a%.03sa\n", str);
	printf("re : %10.04s\n", str);
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
