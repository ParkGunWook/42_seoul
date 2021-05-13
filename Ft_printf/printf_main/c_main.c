#include "libprint.h"

int main()
{
	int		tab[7] = {-135, -12, -1, 0, 1, 13, 198};
	int		cnt;
	cnt = printf("%c\n", 'a');
	ft_printf("%c\n", 'a');
	printf("cnt : %d\n", cnt);
	cnt = printf("%-10.cdone\n", 'a');
	ft_printf("%-10.cdone\n", 'a');
	printf("cnt : %d\n", cnt);
	for(int i=0; i<7;i++)
	{
		printf("-->|%-4.c|<--\n", tab[i]);
		ft_printf("-->|%-4.c|<--\n", tab[i]);
	}
	ft_printf("%10c\n", 'a');
	printf("%10c\n", 'a');
	ft_printf("%10.c\n",  'a');
	printf("%10.c\n",  'a');
	ft_printf("%--10cdone--\n", 'a');
	printf("%--10cdone--\n", 'a');
	ft_printf("%---10cdone---\n", 'a');
	printf("%---10cdone---\n", 'a');
	ft_printf("%----10cdone----\n", 'a');
	printf("%----10cdone----\n", 'a');
	ft_printf("%*c\n", 10, '*');
	printf("%*c\n", 10, '*');
	ft_printf("%*cminft\n", INT32_MIN, '*');
	printf("%*cminre\n", INT32_MIN, '*');
	ft_printf("%*cdone-\n", -10, '*');
	printf("%*cdone-\n", -10, '*');
	ft_printf("%-*cdone--\n", -10, '*');
	printf("%-*cdone--\n", -10, '*');
	ft_printf("%-10c\n%10c\n", 'a', 'b');
	printf("%-10c\n%10c\n", 'a', 'b');
	//ft_printf("last : %-2147483648c\n", 'a');
	//printf("last : %-2147483648c\n", 'a');
	printf("%010.1%\n");
	ft_printf("%010.1%\n");
}
