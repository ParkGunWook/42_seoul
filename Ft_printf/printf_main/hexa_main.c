#include "libprint.h"

int main()
{
	/*int x = 1234;
	int x2 = -1;
	printf("normal 		: %x\n", x);
	ft_printf("normal 		: %x\n", x);
	printf("0	  		: %010x\n", x);
	ft_printf("0	  		: %010x\n", x);
	printf("-      		: %-10x\n", x);
	ft_printf("-      		: %-10x\n", x);
	printf("#      		: %#10x\n", x);
	ft_printf("#      		: %#10x\n", x);
	//printf("#      		: %#10x\n", x); //Noworks

	printf("0  #  		: %0#10x\n", x);
	ft_printf("0 #   		: %0#10x\n", x);
	printf("- #    		: %-#10x\n", x);
	ft_printf("- #    		: %-#10x\n", x);

	printf("w      		: %10x\n", x);
	ft_printf("w      		: %10x\n", x);
	printf("p      		: %.10x\n", x);
	ft_printf("p      		: %.10x\n", x);
	printf("p      		: %.2x\n", x);
	ft_printf("p      		: %.2x\n", x);
	printf("w #    		: %10x\n", x);
	ft_printf("w #    		: %10x\n", x);
	printf("p #    		: %.10x\n", x);
	ft_printf("p #    		: %.10x\n", x);

	printf("w < p  		: %10.15x\n", x);
	ft_printf("w < p  		: %10.15x\n", x);
	printf("w > p  		: %15.10x\n", x);
	ft_printf("w > p  		: %15.10x\n", x);
	printf("w < p #		: %#10.15x\n", x);
	ft_printf("w < p #		: %#10.15x\n", x);
	printf("w > p #		: %#15.10x\n", x);
	ft_printf("w > p #		: %#15.10x\n", x);

	printf("normal 		: %x\n", x2);
	ft_printf("normal 		: %x\n", x2);
	printf("0	  		: %010x\n", x2);
	ft_printf("0	  		: %010x\n", x2);
	printf("-      		: %-10x\n", x2);
	ft_printf("-      		: %-10x\n", x2);

	printf("0  #  		: %0#10x\n", x2);
	ft_printf("0 #   		: %0#10x\n", x2);
	printf("- #    		: %-#10x\n", x2);
	ft_printf("- #    		: %-#10x\n", x2);
	//printf("+ #			: %+#10x\n", x2);
	//printf("+ space		: %+ 10x\n", x2);

	printf("w      		: %10x\n", x2);
	ft_printf("w      		: %10x\n", x2);
	printf("p      		: %.10x\n", x2);
	ft_printf("p      		: %.10x\n", x2);
	printf("p      		: %.2x\n", x2);
	ft_printf("p      		: %.2x\n", x2);
	printf("w #    		: %10x\n", x);
	ft_printf("w #    		: %10x\n", x);
	printf("p #    		: %.10x\n", x);
	ft_printf("p #    		: %.10x\n", x);

	printf("w < p  		: %10.15x\n", x2);
	ft_printf("w < p  		: %10.15x\n", x2);
	printf("w > p  		: %15.10x\n", x2);
	ft_printf("w > p  		: %15.10x\n", x2);
	printf("w < p #		: %#10.15x\n", x);
	ft_printf("w < p #		: %#10.15x\n", x);
	printf("w > p #		: %#15.10x\n", x);
	ft_printf("w > p #		: %#15.10x\n", x);
	int cnt = printf("%.0x%.x\n", x, x2);
	printf("%d\n", cnt);*/
	int x3 = 1;
	printf("-->|%#*.*x|<--\n", -4, 2, x3);
	ft_printf("-->|%#*.*x|<--\n", -4, 2, x3);
	printf("-->|%0*.*d|<--\n", -4, -4, x3);
	ft_printf("-->|%0*.*d|<--\n", -4, -4, x3);
}
