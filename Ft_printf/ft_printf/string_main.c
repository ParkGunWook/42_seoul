#include "libprint.h"

int main()
{
	char str[10] = "abcd";
	char str2[10] = "efg";
	ft_printf("ft : %s\n", str);
	printf("re : %s\n", str);
	ft_printf("ft : %10s\n", str);
	printf("re : %10s\n", str);
	ft_printf("ft : %-10s\n", str);
	printf("re : %-10s\n", str);
	ft_printf("ft : %-10s123\n%10s\n", str, str2);
	printf("re : %-10s123\n%10s\n", str, str2);
}
