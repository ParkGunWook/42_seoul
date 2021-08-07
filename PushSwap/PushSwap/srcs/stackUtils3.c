#include "myloc.h"
#include "utils.h"

void			rra(t_stack *aStack)
{
	if (aStack->name != 'a')
		return ;
	if (aStack->size <= 1)
		return ;
	if (aStack->list->head == aStack->list->tail)
		return ;
	aStack->list->tail = aStack->list->head;
	aStack->list->head = aStack->list->head->next;
}

void			rrb(t_stack *bStack)
{
	if (bStack->name != 'b')
		return ;
	if (bStack->size <= 1)
		return ;
	if (bStack->list->head == bStack->list->tail)
		return ;
	bStack->list->tail = bStack->list->head;
	bStack->list->head = bStack->list->head->next;
}

void			rrr(t_stack *aStack, t_stack *bStack)
{
	rra(aStack);
	rrb(bStack);
}

void			clearStacks(t_stack **aStack, t_stack **bStack)
{
	clearList(&((*aStack)->list));
	clearList(&((*bStack)->list));
	myFree((void **)aStack);
	myFree((void **)bStack);
}
