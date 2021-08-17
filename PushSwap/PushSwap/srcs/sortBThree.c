#include "utils.h"
#include "myloc.h"

static	void	caseOne(t_stack *aStack, t_stack *bStack)
{
	t_node		*bTail;

	bTail = bStack->list->tail;
	if (bTail->content > bTail->prev->prev->content)
	{
		pa(aStack, bStack);
		sb(bStack);
		pa(aStack, bStack);
		pa(aStack, bStack);
		return ;
	}
	pa(aStack, bStack);
	sb(bStack);
	pa(aStack, bStack);
	sa(aStack);
	pa(aStack, bStack);
}

static	void	caseTwo(t_stack *aStack, t_stack *bStack)
{
	pa(aStack, bStack);
	ra(aStack);
	sb(bStack);
	pa(aStack, bStack);
	pa(aStack, bStack);
	rra(aStack);
}

static	void	caseThree(t_stack *aStack, t_stack *bStack)
{
	sb(bStack);
	pa(aStack, bStack);
	pa(aStack, bStack);
	pa(aStack, bStack);
}

static	void	caseFour(t_stack *aStack, t_stack *bStack)
{
	pa(aStack, bStack);
	ra(aStack);
	pa(aStack, bStack);
	pa(aStack, bStack);
	rra(aStack);
}

void	sortBThree(t_stack *aStack, t_stack *bStack)
{
	t_node		*bTail;

	bTail = bStack->list->tail;
	if (isStackSorted(bStack, DESC, 3))
	{
		pa(aStack, bStack);
		pa(aStack, bStack);
		pa(aStack, bStack);
	}
	else if (bTail->content > bTail->prev->content && \
		bTail->prev->content < bTail->prev->prev->content)
		caseOne(aStack, bStack);
	else if (bTail->content < bTail->prev->content && \
		bTail->prev->content < bTail->prev->prev->content)
		caseTwo(aStack, bStack);
	else if (bTail->content < bTail->prev->content && \
		bTail->prev->content > bTail->prev->prev->content)
	{
		if (bTail->content > bTail->prev->prev->content)
		{
			caseThree(aStack, bStack);
			return ;
		}
		caseFour(aStack, bStack);
	}
}
