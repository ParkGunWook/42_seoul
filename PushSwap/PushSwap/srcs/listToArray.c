#include "myloc.h"
#include "utils.h"

static void	ft_swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

static void	sortArray(t_array *arr)
{
	size_t		i;
	size_t		j;
	int			minval;
	int			mindex;

	i = 0;
	while (i < arr->size)
	{
		minval = *(arr->array + i);
		mindex = i;
		j = i + 1;
		while (j < arr->size)
		{
			if (minval > *(arr->array + j))
			{
				minval = *(arr->array + j);
				mindex = j;
			}
			j++;
		}
		ft_swap(arr->array + i, arr->array + mindex);
		i++;
	}
}

t_array	*listToSortedArray(t_stack *aStack, int size)
{
	t_array		*ret;
	t_node		*cur;
	int			i;

	myAloc((void **)&ret, sizeof(t_array));
	if (ret == NULL)
		return (NULL);
	myAloc((void **)&(ret->array), sizeof(int) * size);
	i = 0;
	cur = aStack->list->tail;
	while (i < size)
	{
		*(ret->array + i) = cur->content;
		cur = cur->prev;
		i++;
	}
	ret->size = size;
	sortArray(ret);
	return (ret);
}

void	freeSortedArray(t_array **sortedArray)
{
	myFree((void **)&((*sortedArray)->array));
	myFree((void **)sortedArray);
}
