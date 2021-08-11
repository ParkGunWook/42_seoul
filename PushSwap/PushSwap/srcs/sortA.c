#include "utils.h"
#include "myloc.h"

static	void		nextARecurse(t_stack *aStack, t_stack *bStack, int counts[4])
{
	recoverStack(aStack, bStack, counts[RA], counts[RB]);
	if (isStackSorted(aStack, ASC, counts[RA]) == 0)
		sortA(aStack, bStack, counts[RA]);
	sortB(aStack, bStack, counts[RB]);
	sortB(aStack, bStack, counts[PUSH] - counts[RB]);
}

static	void		endARecurse(t_stack *aStack, int size)
{
	t_node		*aTop;

	aTop = aStack->list->tail;
	if (size == 3)
		sortAThree(aStack);
	else if (size == 2 && aTop->prev->content < aTop->content)
		sa(aStack);
}

static	void		moveStack(t_stack *aStack, t_stack *bStack, int pivots[2], int counts[4])
{
	t_node		*aTop;

	aTop = aStack->list->tail;
	if (aTop->content > pivots[1])
	{
		counts[RA]++;
		ra(aStack);
	}
	else
	{
		counts[PUSH]++;
		pb(aStack, bStack);
		if (bStack->list->tail->content > pivots[0])
		{
			if (counts[3] > 0 && aTop->content > pivots[1])
			{
				counts[3]--;
				counts[RA]++;
				rr(aStack, bStack);
			}
			else
				rb(bStack);
			counts[RB]++;
		}
	}
}

void				sortA(t_stack *aStack, t_stack *bStack, int size)
{
	int		counts[4];
	int		pivots[2];

	getPivots(pivots, aStack, size);
	/*printf("Asort with size %d\n", size);
	traverseAll(aStack->list);
	traverseAll(bStack->list);
	printf("\n");
	printf("pivot %d %d\n", pivots[0], pivots[1]);
	printf("\n");*/
	ft_memset(counts, 0, sizeof(int) * 4);
	if (isStackSorted(aStack, ASC, size))
		return ;
	if (size <= 3)
	{
		endARecurse(aStack, size);
		return ;
	}
	counts[3] = size;
	while (counts[3]-- > 0)
		moveStack(aStack, bStack, pivots, counts);
	nextARecurse(aStack, bStack, counts);
}
