#include "myloc.h"
#include "utils.h"

int			pa(t_stack *aStack, t_stack *bStack)
{
	t_node	*temp;

	if (aStack->name != 'a' || bStack->name != 'b')
		return (0);
	if (bStack->size == 0)
		return (0);
	temp = popBack(bStack->list);
	if (temp == NULL)
		return (0);
	addBackNode(aStack->list, temp);
	aStack->size++;
	bStack->size--;
	return (1);
}

int			pb(t_stack *aStack, t_stack *bStack)
{
	t_node	*temp;

	if (aStack->name != 'a' || bStack->name != 'b')
		return (0);
	if (aStack->size == 0)
		return (0);
	temp = popBack(aStack->list);
	if (temp == NULL)
		return (0);
	addBackNode(bStack->list, temp);
	aStack->size--;
	bStack->size++;
	return (1);
}

void		ra(t_stack *aStack)
{
	if (aStack->name != 'a')
		return ;
	if (aStack->size <= 1)
		return ;
	if (aStack->list->head == aStack->list->tail)
		return ;
	aStack->list->head = aStack->list->tail;
	aStack->list->tail = aStack->list->tail->prev;
}

void		rb(t_stack *bStack)
{
	if (bStack->name != 'b')
		return ;
	if (bStack->size <= 1)
		return ;
	if (bStack->list->head == bStack->list->tail)
		return ;
	bStack->list->head = bStack->list->tail;
	bStack->list->tail = bStack->list->tail->prev;
}

void		rr(t_stack *aStack, t_stack *bStack)
{
	ra(aStack);
	rb(bStack);
}
