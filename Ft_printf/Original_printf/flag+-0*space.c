#include <stdio.h>
int main()
{
	int i1 = 123456;
	int i2 = -123456;
	int *ptr_i1 = &i1;
	char s1[10] = "abcdef";
	char s2[10] = "ghijkl";
	printf("%d %d\n", i1, i2);
	printf("%+d %+d | what solo plus works\n", i1, i2);
	printf("% d % d | what solo space works\n", i1, i2);
	printf("%-d %-d | what solo minus works\n", i1, i2);
	printf("%4d %4d | if num over width\n\n", i1, i2);
	printf("%12d %12d | + and width\n", i1, i2);
	printf("%+12d %+12d | + and width\n", i1, i2);
	printf("%-12d %-12d | - and width\n", i1, i2);
	printf("%012d %012d | 0 and width\n", i1, i2);
	printf("%+012d %+012d | + and 0 and width\n", i1, i2);
	printf("%+-12d %+-12d | + and - and width\n", i1, i2);
	printf("% 012d % 012d | + and 0 and width\n", i1, i2);
	printf("% -12d % -12d | space and - and width\n", i1, i2);
	//printf("abc%-n\n", ptr_i1);
	//printf("%+s %+s | what solo plus works\n", s1, s2);
	//printf("% s % s | what solo space works\n", s1, s2);
	printf("%-s %-s | what solo minus works\n", s1, s2);
	printf("%12s %12s | pad and minus works\n", s1, s2);
	printf("%-12s %-12s | what pad solo minus works\n", s1, s2);
	//printf("%+012s %+012s | + and 0 and width\n", s1, s2);
	//printf("%+-12s %+-12s | + and - and width\n", s1, s2);
	//printf("% 012s % 012s | + and 0 and width\n", s1, s2);
	//printf("% -12s % -12s | space and - and width\n", s1, s2);
	//printf("%-012d %-012d | - and 0 and width\n", i1, i2); //zero is ignored when flag '-'
	//printf("%0s\n", s1); //0 and ' ' cant'be used in string
}
