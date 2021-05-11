#include "libprint.h"

int main()
{
	int d = 1234;
	int d2 = -1234;
	printf("normal 		: %d\n", d);
	ft_printf("normal 		: %d\n", d);
	printf("0	  		: %010d\n", d);
	ft_printf("0	  		: %010d\n", d);
	printf("-      		: %-10d\n", d);
	ft_printf("-      		: %-10d\n", d);
	//printf("#      		: %#10d\n", d); //Noworks
	printf("+      		: %+10d\n", d);
	ft_printf("+      		: %+10d\n", d);
	printf("space  		: % 10d\n", d);
	ft_printf("space  		: % 10d\n", d);

	//printf("0 -    		: %0-10d\n", d);
	printf("0 +	    	: %0+10d\n", d);
	ft_printf("0 +	    	: %0+10d\n", d);
	printf("0 space		: %0 10d\n", d);
	ft_printf("0 space		: %0 10d\n", d);
	//printf("0 #			: %0#10d\n", d);

	//printf("- 0    		: %-010d\n", d);
	printf("- +	    	: %-+10d\n", d);
	ft_printf("- +	    	: %-+10d\n", d);
	printf("- space		: %- 10d\n", d);
	ft_printf("- space		: %- 10d\n", d);
	//printf("- #			: %-#10d\n", d);

	printf("space 0		: % 010d\n", d);
	ft_printf("space 0		: % 010d\n", d);
	printf("space -    	: % -10d\n", d);
	ft_printf("space -    	: % -10d\n", d);
	//printf("space #		: % #10d\n", d);
	//printf("space +		: % +10d\n", d);

	printf("+ 0    		: %+010d\n", d);
	ft_printf("+ 0    		: %+010d\n", d);
	printf("+ -	    	: %+-10d\n", d);
	ft_printf("+ -	    	: %+-10d\n", d);
	//printf("+ #			: %+#10d\n", d);
	//printf("+ space		: %+ 10d\n", d);


	printf("normal 		: %d\n", d2);
	ft_printf("normal 		: %d\n", d2);
	printf("0	  		: %010d\n", d2);
	ft_printf("0	  		: %010d\n", d2);
	printf("-      		: %-10d\n", d2);
	ft_printf("-      		: %-10d\n", d2);
	//printf("#      		: %#10d\n", d); //Noworks
	printf("+      		: %+10d\n", d2);
	ft_printf("+      		: %+10d\n", d2);
	printf("space  		: % 10d\n", d2);
	ft_printf("space  		: % 10d\n", d2);

	//printf("0 -    		: %0-10d\n", d2);
	printf("0 +	    	: %0+10d\n", d2);
	ft_printf("0 +	    	: %0+10d\n", d2);
	printf("0 space		: %0 10d\n", d2);
	ft_printf("0 space		: %0 10d\n", d2);
	//printf("0 #			: %0#10d\n", d2);

	//printf("- 0    		: %-010d\n", d2);
	printf("- +	    	: %-+10d\n", d2);
	ft_printf("- +	    	: %-+10d\n", d2);
	printf("- space		: %- 10d\n", d2);
	ft_printf("- space		: %- 10d\n", d2);
	//printf("- #			: %-#10d\n", d2);

	printf("space 0		: % 010d\n", d2);
	ft_printf("space 0		: % 010d\n", d2);
	printf("space -    	: % -10d\n", d2);
	ft_printf("space -    	: % -10d\n", d2);
	//printf("space #		: % #10d\n", d2);
	//printf("space +		: % +10d\n", d2);

	printf("+ 0    		: %+010d\n", d2);
	ft_printf("+ 0    		: %+010d\n", d2);
	printf("+ -	    	: %+-10d\n", d2);
	ft_printf("+ -	    	: %+-10d\n", d2);
	//printf("+ #			: %+#10d\n", d2);
	//printf("+ space		: %+ 10d\n", d2);

	printf("w      		: %10d\n", d);
	ft_printf("w      		: %10d\n", d);
	printf("p      		: %.10d\n", d);
	ft_printf("p      		: %.10d\n", d);
	printf("p      		: %.2d\n", d);
	ft_printf("p      		: %.2d\n", d);
	printf("w < p  		: %10.15d\n", d);
	ft_printf("w < p  		: %10.15d\n", d);
	printf("w > p  		: %15.10d\n", d);
	ft_printf("w > p  		: %15.10d\n", d);
	printf("w < p +		: %+10.15d\n", d);
	ft_printf("w < p +		: %+10.15d\n", d);
	printf("w > p +		: %+15.10d\n", d);
	ft_printf("w > p +		: %+15.10d\n", d);
	printf("0 + w + p	: %010.15d\n", d);
	ft_printf("0 + w + p	: %010.15d\n", d);
	printf("0 + w + p	: %015.10d\n", d);
	ft_printf("0 + w + p	: %015.10d\n", d);

	printf("w      		: %10d\n", d2);
	ft_printf("w      		: %10d\n", d2);
	printf("p      		: %.10d\n", d2);
	ft_printf("p      		: %.10d\n", d2);
	printf("p      		: %.2d\n", d2);
	ft_printf("p      		: %.2d\n", d2);
	printf("w < p  		: %10.15d\n", d2);
	ft_printf("w < p  		: %10.15d\n", d2);
	printf("w > p  		: %15.10d\n", d2);
	ft_printf("w > p  		: %15.10d\n", d2);
	printf("w < p +		: %+10.15d\n", d2);
	ft_printf("w < p +		: %+10.15d\n", d2);
	printf("w > p +		: %+15.10d\n", d2);
	ft_printf("w > p +		: %+15.10d\n", d2);
	printf("0 + w < p	: %010.15d\n", d2);
	ft_printf("0 + w < p	: %010.15d\n", d2);
	printf("0 + w > p	: %015.10d\n", d2);
	ft_printf("0 + w > p	: %015.10d\n", d2);
	int cnt = printf("%.0d%.d\n", 0, 0);
	printf("%d\n", cnt);
}
