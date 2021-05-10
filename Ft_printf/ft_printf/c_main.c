#include "libprint.h"

int main()
{
	ft_printf("%c\n", 'a');
	printf("%c\n", 'a');
	ft_printf("%10c\n", 'a');
	printf("%10c\n", 'a');
	ft_printf("%-10c\n", 'a');
	printf("%-10c\n", 'a');
	ft_printf("%-10c123\n%10c\n", 'a', 'b');
	printf("%-10c123\n%10c\n", 'a', 'b');
}
