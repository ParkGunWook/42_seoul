#include "utils.h"
#include "myloc.h"

static	void	caseOne(t_stack *aStack)
{
	ra(aStack);
	sa(aStack);
}

static	void	caseFour(t_stack *aStack)
{
	sa(aStack);
	ra(aStack);
}

void			sortThree(t_stack *aStack)
{
	t_node		*aHead;

	aHead = aStack->list->head;
	if (aHead->content < aHead->next->content && \
		aHead->next->content < aHead->next->next->content && \
		aHead->content < aHead->next->next->content)
		caseOne(aStack);
	else if (aHead->content < aHead->next->content && \
		aHead->next->content > aHead->next->next->content && \
		aHead->content < aHead->next->next->content)
		rra(aStack);
	else if (aHead->content > aHead->next->content && \
		aHead->next->content < aHead->next->next->content && \
		aHead->content < aHead->next->next->content)
		ra(aStack);
	else if (aHead->content < aHead->next->content && \
		aHead->next->content > aHead->next->next->content && \
		aHead->content > aHead->next->next->content)
		caseFour(aStack);
	else if (aHead->content > aHead->next->content && \
		aHead->next->content < aHead->next->next->content && \
		aHead->content < aHead->next->next->content)
		sa(aStack);
}
