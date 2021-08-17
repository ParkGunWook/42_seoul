#include "utils.h"
#include "myloc.h"

static	void	multiPa(t_stack *aStack, t_stack *bStack, int size)
{
	while (size--)
		pa(aStack, bStack);
}

static	void	nextBRecurse(t_stack *aStack, t_stack *bStack, int counts[4])
{
	if (isStackSorted(aStack, ASC, counts[PUSH] - counts[RA]) == 0)
		sortA(aStack, bStack, counts[PUSH] - counts[RA]);
	recoverStack(aStack, bStack, counts[RA], counts[RB]);
	if (isStackSorted(aStack, ASC, counts[RA]) == 0)
		sortA(aStack, bStack, counts[RA]);
	if (isStackSorted(bStack, DESC, counts[RB]) == 0)
		sortB(aStack, bStack, counts[RB]);
	else
		multiPa(aStack, bStack, counts[RB]);
}

static	void	endBRecurse(t_stack *aStack, t_stack *bStack, int size)
{
	t_node		*bTop;

	bTop = bStack->list->tail;
	if (size == 3)
	{
		sortBThree(aStack, bStack);
		return ;
	}
	else if (size == 2)
	{
		if (bTop->content < bTop->prev->content)
			sb(bStack);
		pa(aStack, bStack);
		pa(aStack, bStack);
		return ;
	}
	else if (size == 1)
	{
		pa(aStack, bStack);
	}
}

static	void	moveStack(t_stack *aStack, t_stack *bStack, int pivots[2], int counts[4])
{
	t_node		*bTop;

	bTop = bStack->list->tail;
	if (bTop->content < pivots[0])
	{
		counts[RB]++;
		rb(bStack);
	}
	else
	{
		counts[PUSH]++;
		pa(aStack, bStack);
		if (aStack->list->tail->content < pivots[1])
		{
			counts[RA]++;
			ra(aStack);
		}
	}
}

void	sortB(t_stack *aStack, t_stack *bStack, int size)
{
	int		counts[4];
	int		pivots[4];

	getPivots(pivots, bStack, size);
	//printf("Bsort with size : %d\n", size);
	//traverseAll(aStack->list);
	//traverseAll(bStack->list);
	//printf("pivot %d %d\n", pivots[0], pivots[1]);
	//printf("\n");
	ft_memset(counts, 0, sizeof(int) * 4);
	if (isStackSorted(bStack, DESC, size))
	{
		multiPa(aStack, bStack, size);
		return ;
	}
	if (size <= 3)
	{
		endBRecurse(aStack, bStack, size);
		return ;
	}
	counts[3] = size;
	while (counts[3]-- > 0)
		moveStack(aStack, bStack, pivots, counts);
	nextBRecurse(aStack, bStack, counts);
}
