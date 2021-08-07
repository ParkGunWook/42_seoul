#include "utils.h"
#include "myloc.h"

void		traverseAll(t_list *list)
{
	t_node		*cur;
	int 		cnt;

	cnt = 0;
	cur = list->head;
	printf("start Traversal\n");
	if (cur == NULL)
		return ;
	while (cur != list->tail)
	{
		printf("%d : %d\n",cnt+1, cur->content);
		cur = cur->next;
		cnt++;
		if (cnt == 10)
			break;
	}
	printf("%d : %d\n",cnt+1, cur->content);
	return ;
}

void		addBackNode(t_list *tList, t_node *curNode)
{
	if (tList->head == NULL)
	{
		tList->head = curNode;
		tList->tail = curNode;
	}
	else
	{
		tList->tail->next = curNode;
		tList->head->prev = curNode;
		curNode->prev = tList->tail;
		curNode->next = tList->head;
		tList->tail = curNode;
	}
}
