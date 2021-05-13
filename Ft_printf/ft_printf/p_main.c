#include "libprint.h"

int main()
{
	int d = 1234;
	int *p = &d;
	printf("normal 		: %p\n", p);
	//ft_printf("normal 		: %p\n", p);
	printf("-      		: %-10p\n", p);
	//ft_printf("-      		: %-10p\n", p);
	printf("%#p\n", p);

	p = 0;
	int cnt = printf("%p\n", p);
	printf("%d\n", cnt);
	//ft_printf("|%-4.*p|\n", -4, 0);
}
