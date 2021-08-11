#include "myloc.h"
#include "utils.h"

void	mainSort(t_stack *aStack, t_stack *bStack)
{
	t_node *aHead;

	aHead = aStack->list->head;
	if (aStack->size == 5)
		sortFive(aStack, bStack);
	else if (aStack->size == 3)
		sortThree(aStack);
	else if (aStack->size == 2 && aHead->content > aHead->next->content)
		sa(aStack);
	else
		sortA(aStack, bStack, aStack->size);
}
