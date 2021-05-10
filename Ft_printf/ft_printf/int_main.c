#include "libprint.h"

int main()
{
	int d = 1234;
	int d2 = -4321;
	ft_printf("ft : %d\n", d);
	printf("re : %d\n", d);
	ft_printf("ft : %010d\n", d2);
	printf("re : %010d\n", d2);
	ft_printf("ft : %-10d\n", d);
	printf("re : %-10d\n", d);
	ft_printf("ft : %010d\n", d);
	printf("re : %010d\n", d);
	ft_printf("ft : %-10d123\n%10d\n", d, d2);
	printf("re : %-10d123\n%10d\n", d, d2);
}
