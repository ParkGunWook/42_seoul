#include "utils.h"
#include "myloc.h"

int main(int argc, char **argv) 
{
	t_list	*list;
	t_stack	*aStack;
	t_node	*temp;
	t_stack	*bStack;

	if (argc == 0)
		return (0);
	list = parser(argv + 1);
	aStack = initStack('a');
	while (1)
	{
		temp = popBack(list);
		if (temp == NULL)
			break ;
		addBackNode(aStack->list, temp);
		aStack->size++;
	}
	clearList(&list);
	bStack = initStack('b');
	mainSort(aStack, bStack);
	clearStack(&aStack);
	clearStack(&bStack);
	return (0);
}
