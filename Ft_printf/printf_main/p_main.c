#include "libprint.h"

int main()
{
	int d = 1234;
	int *p = &d;
	printf("normal 		: %p\n", p);
	ft_printf("normal 		: %p\n", p);
	printf("-      		: |%-16p|\n", p);
	ft_printf("-      		: |%-16p|\n", p);
	printf("-      		: |%-16.p|\n", p);
	ft_printf("-      		: |%-16.p|\n", p);

	p = 0;
	int cnt = printf("%p\n", p);
	printf("%d\n", cnt);
	cnt = ft_printf("%p\n", p);
	ft_printf("%d\n", cnt);
}
