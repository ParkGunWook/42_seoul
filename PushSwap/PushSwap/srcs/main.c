#include "utils.h"
#include "myloc.h"

static	int	getError(void)
{
	write(2, "Error\n", 6);
	return (0);
}

static void	pushToStack(t_stack *aStack, t_list *list)
{
	t_node	*temp;

	while (1)
	{
		temp = popBack(list);
		if (temp == NULL)
			break ;
		addBackNode(aStack->list, temp);
		aStack->size++;
	}
}

int	main(int argc, char **argv)
{
	t_list	*list;
	t_stack	*aStack;
	t_stack	*bStack;

	if (argc <= 1)
		return (getError());
	list = parser(argv + 1);
	if (list == NULL)
		return (getError());
	aStack = initStack('a');
	bStack = initStack('b');
	if (aStack == NULL || bStack == NULL)
		return (getError());
	pushToStack(aStack, list);
	clearList(&list);
	mainSort(aStack, bStack);
	clearStack(&aStack);
	clearStack(&bStack);
	return (0);
}
