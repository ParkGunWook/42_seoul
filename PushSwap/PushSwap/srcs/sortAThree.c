#include "utils.h"
#include "myloc.h"

static	void	caseOne(t_stack *aStack)
{
	t_node		*aTail;

	aTail = aStack->list->tail;
	if (aTail->content < aTail->prev->prev->content)
	{
		sa(aStack);
		return ;
	}
	sa(aStack);
	ra(aStack);
	sa(aStack);
	rra(aStack);

}

static	void	caseTwo(t_stack *aStack)
{
	sa(aStack);
	ra(aStack);
	sa(aStack);
	rra(aStack);
	sa(aStack);
}

static	void	caseThree(t_stack *aStack)
{
	ra(aStack);
	sa(aStack);
	rra(aStack);
	sa(aStack);
}

static	void	caseFour(t_stack *aStack)
{
	ra(aStack);
	sa(aStack);
	rra(aStack);
}

void			sortAThree(t_stack *aStack)
{
	t_node		*aTail;

	aTail = aStack->list->tail;
	if (aTail->content > aTail->prev->content &&
	aTail->prev->content < aTail->prev->prev->content)
		caseOne(aStack);
	else if (aTail->content > aTail->prev->content &&
	aTail->prev->content > aTail->prev->prev->content)
		caseTwo(aStack);
	else if (aTail->content < aTail->prev->content &&
	aTail->prev->content > aTail->prev->prev->content)
	{
		if (aTail->content > aTail->prev->prev->content)
		{
			caseThree(aStack);
			return ;
		}
		caseFour(aStack);
	}
}
