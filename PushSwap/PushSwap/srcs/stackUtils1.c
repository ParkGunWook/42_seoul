#include "myloc.h"
#include "utils.h"

t_stack			*initStack(char name)
{
	t_stack		*stack;

	myAloc((void **)&stack, sizeof(t_stack));
	if (stack == NULL)
		return (NULL);
	stack->list = initList();
	if (stack->list == NULL)
	{
		myFree((void **)&stack);
		return (NULL);
	}
	stack->name = name;
	stack->size = 0;
	return (stack);
}

int				sa(t_stack *aStack)
{
	t_node	*firstNode;
	t_node	*secondNode;

	if (aStack->name != 'a' || aStack->size <= 1)
		return (0);
	firstNode = popBack(aStack->list);
	secondNode = popBack(aStack->list);
	if (firstNode == NULL || secondNode == NULL)
		return (0);
	write(1, "sa\n", 3);
	addBackNode(aStack->list, firstNode);
	addBackNode(aStack->list, secondNode);
	return (1);
}

int				sb(t_stack *bStack)
{
	t_node	*firstNode;
	t_node	*secondNode;

	if (bStack->name != 'b' || bStack->size <= 1)
		return (0);
	firstNode = popBack(bStack->list);
	secondNode = popBack(bStack->list);
	if (firstNode == NULL || secondNode == NULL)
		return (0);
	write(1, "sb\n", 3);
	addBackNode(bStack->list, firstNode);
	addBackNode(bStack->list, secondNode);
	return (1);
}

int				ss(t_stack *aStack, t_stack *bStack)
{
	int		ret;

	ret = sa(aStack);
	if (ret == 0)
		return (ret);
	ret = sb(bStack);
	if (ret == 0)
		return (ret);
	write(1, "ss\n", 3);
	return (ret);
}

