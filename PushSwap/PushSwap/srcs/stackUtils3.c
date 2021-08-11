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
	write(1, "rra\n", 4);
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
	write(1, "rrb\n", 4);
}

void			rrr(t_stack *aStack, t_stack *bStack)
{
	write(1, "rrr\n", 4);
	if (bStack->name != 'b')
		return ;
	if (bStack->size <= 1)
		return ;
	if (bStack->list->head == bStack->list->tail)
		return ;
	bStack->list->tail = bStack->list->head;
	bStack->list->head = bStack->list->head->next;
	if (aStack->name != 'a')
		return ;
	if (aStack->size <= 1)
		return ;
	if (aStack->list->head == aStack->list->tail)
		return ;
	aStack->list->tail = aStack->list->head;
	aStack->list->head = aStack->list->head->next;
}

void			clearStack(t_stack **st)
{
	clearList(&((*st)->list));
	myFree((void **)st);
}

int				isStackSorted(t_stack *st, int sortType, int n)
{
	t_node		*cur;

	cur = st->list->tail;
	while (cur != st->list->head && cur != NULL && --n > 0)
	{
		if (sortType == DESC)
		{
			if (cur->prev->content > cur->content)
				return (0);
		}
		else
		{
			if (cur->prev->content < cur->content)
				return (0);
		}
		cur = cur->prev;
	}
	return (1);
}
