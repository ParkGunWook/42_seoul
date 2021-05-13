#include "libprint.h"

int main()
{
	int i = 1234;
	int i2 = -1234;
	printf("normal 		: %i\n", i);
	ft_printf("normal 		: %i\n", i);
	printf("0	  		: %010i\n", i);
	ft_printf("0	  		: %010i\n", i);
	printf("-      		: %-10i\n", i);
	ft_printf("-      		: %-10i\n", i);
	//printf("#      		: %#10i\n", i); //Noworks
	printf("+      		: %+10i\n", i);
	ft_printf("+      		: %+10i\n", i);
	printf("space  		: % 10i\n", i);
	ft_printf("space  		: % 10i\n", i);

	//printf("0 -    		: %0-10i\n", i);
	printf("0 +	    	: %0+10i\n", i);
	ft_printf("0 +	    	: %0+10i\n", i);
	printf("0 space		: %0 10i\n", i);
	ft_printf("0 space		: %0 10i\n", i);
	//printf("0 #			: %0#10i\n", i);

	//printf("- 0    		: %-010i\n", i);
	printf("- +	    	: %-+10i\n", i);
	ft_printf("- +	    	: %-+10i\n", i);
	printf("- space		: %- 10i\n", i);
	ft_printf("- space		: %- 10i\n", i);
	//printf("- #			: %-#10i\n", i);

	printf("space 0		: % 010i\n", i);
	ft_printf("space 0		: % 010i\n", i);
	printf("space -    	: % -10i\n", i);
	ft_printf("space -    	: % -10i\n", i);
	//printf("space #		: % #10i\n", i);
	//printf("space +		: % +10i\n", i);

	printf("+ 0    		: %+010i\n", i);
	ft_printf("+ 0    		: %+010i\n", i);
	printf("+ -	    	: %+-10i\n", i);
	ft_printf("+ -	    	: %+-10i\n", i);
	//printf("+ #			: %+#10i\n", i);
	//printf("+ space		: %+ 10i\n", i);


	printf("normal 		: %i\n", i2);
	ft_printf("normal 		: %i\n", i2);
	printf("0	  		: %010i\n", i2);
	ft_printf("0	  		: %010i\n", i2);
	printf("-      		: %-10i\n", i2);
	ft_printf("-      		: %-10i\n", i2);
	//printf("#      		: %#10i\n", i); //Noworks
	printf("+      		: %+10i\n", i2);
	ft_printf("+      		: %+10i\n", i2);
	printf("space  		: % 10i\n", i2);
	ft_printf("space  		: % 10i\n", i2);

	//printf("0 -    		: %0-10i\n", i2);
	printf("0 +	    	: %0+10i\n", i2);
	ft_printf("0 +	    	: %0+10i\n", i2);
	printf("0 space		: %0 10i\n", i2);
	ft_printf("0 space		: %0 10i\n", i2);
	//printf("0 #			: %0#10i\n", i2);

	//printf("- 0    		: %-010i\n", i2);
	printf("- +	    	: %-+10i\n", i2);
	ft_printf("- +	    	: %-+10i\n", i2);
	printf("- space		: %- 10i\n", i2);
	ft_printf("- space		: %- 10i\n", i2);
	//printf("- #			: %-#10i\n", i2);

	printf("space 0		: % 010i\n", i2);
	ft_printf("space 0		: % 010i\n", i2);
	printf("space -    	: % -10i\n", i2);
	ft_printf("space -    	: % -10i\n", i2);
	//printf("space #		: % #10i\n", i2);
	//printf("space +		: % +10i\n", i2);

	printf("+ 0    		: %+010i\n", i2);
	ft_printf("+ 0    		: %+010i\n", i2);
	printf("+ -	    	: %+-10i\n", i2);
	ft_printf("+ -	    	: %+-10i\n", i2);
	//printf("+ #			: %+#10i\n", i2);
	//printf("+ space		: %+ 10i\n", i2);

	printf("w      		: %10i\n", i);
	ft_printf("w      		: %10i\n", i);
	printf("p      		: %.10i\n", i);
	ft_printf("p      		: %.10i\n", i);
	printf("p      		: %.2i\n", i);
	ft_printf("p      		: %.2i\n", i);
	printf("w < p  		: %10.15i\n", i);
	ft_printf("w < p  		: %10.15i\n", i);
	printf("w > p  		: %15.10i\n", i);
	ft_printf("w > p  		: %15.10i\n", i);
	printf("w < p +		: %+10.15i\n", i);
	ft_printf("w < p +		: %+10.15i\n", i);
	printf("w > p +		: %+15.10i\n", i);
	ft_printf("w > p +		: %+15.10i\n", i);
	printf("0 + w + p	: %010.15i\n", i);
	ft_printf("0 + w + p	: %010.15i\n", i);
	printf("0 + w + p	: %015.10i\n", i);
	ft_printf("0 + w + p	: %015.10i\n", i);

	printf("w      		: %10i\n", i2);
	ft_printf("w      		: %10i\n", i2);
	printf("p      		: %.10i\n", i2);
	ft_printf("p      		: %.10i\n", i2);
	printf("p      		: %.2i\n", i2);
	ft_printf("p      		: %.2i\n", i2);
	printf("w < p  		: %10.15i\n", i2);
	ft_printf("w < p  		: %10.15i\n", i2);
	printf("w > p  		: %15.10i\n", i2);
	ft_printf("w > p  		: %15.10i\n", i2);
	printf("w < p +		: %+10.15i\n", i2);
	ft_printf("w < p +		: %+10.15i\n", i2);
	printf("w > p +		: %+15.10i\n", i2);
	ft_printf("w > p +		: %+15.10i\n", i2);
	printf("0 + w < p	: %010.15i\n", i2);
	ft_printf("0 + w < p	: %010.15i\n", i2);
	printf("0 + w > p	: %015.10i\n", i2);
	ft_printf("0 + w > p	: %015.10i\n", i2);
	int cnt = printf("%.0i%.i", 0, 0);
	printf("%i\n", cnt);
}
