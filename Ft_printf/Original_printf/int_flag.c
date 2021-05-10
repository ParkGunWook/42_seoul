#include <stdio.h>

int main()
{
	int d = 1234;
	int d2 = -1234;
	printf("normal 		: %d\n", d);
	printf("0	  		: %010d\n", d);
	printf("-      		: %-10d\n", d);
	//printf("#      		: %#10d\n", d); //Noworks
	printf("+      		: %+10d\n", d);
	printf("space  		: % 10d\n", d);

	//printf("0 -    		: %0-10d\n", d);
	printf("0 +	    	: %0+10d\n", d);
	printf("0 space		: %0 10d\n", d);
	//printf("0 #			: %0#10d\n", d);

	//printf("- 0    		: %-010d\n", d);
	printf("- +	    	: %-+10d\n", d);
	printf("- space		: %0 10d\n", d);
	//printf("- #			: %-#10d\n", d);

	printf("space 0		: % 010d\n", d);
	printf("space -    	: % -10d\n", d);
	//printf("space #		: % #10d\n", d);
	//printf("space +		: % +10d\n", d);

	printf("+ 0    		: %+010d\n", d);
	printf("+ -	    	: %+-10d\n", d);
	//printf("+ #			: %+#10d\n", d);
	//printf("+ space		: %+ 10d\n", d);

	printf("w      		: %10d\n", d);
	printf("p      		: %.10d\n", d);
	printf("w < p  		: %10.15d\n", d);
	printf("w > p  		: %15.10d\n", d);
	printf("0 + w + p	: %010.15d\n", d);
	printf("0 + w + p	: %015.10d\n", d);


	printf("normal 		: %d\n", d2);
	printf("-      		: %-10d\n", d2);
	printf("+      		: %+10d\n", d2);
	printf("space  		: % 10d\n", d2);
	printf("0 +    		: %0+10d\n", d2);
	printf("w      		: %10d\n", d2);
	printf("p      		: %.10d\n", d2);
	printf("w + p  		: %10.15d\n", d2);
	printf("w + p  		: %15.10d\n", d2);
	printf("0 + w + p	: %010.15d\n", d2);
	printf("0 + w + p	: %015.10d\n", d2);
	printf("- wi   		: %-10d\n", d2);
}
