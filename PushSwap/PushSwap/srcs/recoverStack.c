#include "utils.h"
#include "myloc.h"

void	recoverStack(t_stack *aStack, t_stack *bStack, int raCnt, int rbCnt)
{
	while (raCnt > 0 || rbCnt > 0)
	{
		if (raCnt > 0 && rbCnt)
			rrr(aStack, bStack);
		else if (raCnt > 0)
			rra(aStack);
		else if (rbCnt > 0)
			rrb(bStack);
		raCnt--;
		rbCnt--;
	}
}
