#include "utils.h"
#include "myloc.h"

void		traverseAll(t_list *list)
{
	t_node		*cur;
	int 		cnt;

	printf("start Traversal\n");
	if (list == NULL)
		return ;
	cnt = 0;
	cur = list->head;
	if (cur == NULL)
		return ;
	while (cur != list->tail)
	{
		printf("%d ", cur->content);
		cur = cur->next;
		cnt++;
	}
	printf("%d\n", cur->content);
	return ;
}

void		rtraverseAll(t_list *list)
{
	t_node		*cur;
	int 		cnt;

	printf("start rTraversal\n");
	if (list == NULL)
		return ;
	cnt = 0;
	cur = list->tail;
	if (cur == NULL)
		return ;
	while (cur != list->head)
	{
		printf("%d ", cur->content);
		cur = cur->prev;
		cnt++;
	}
	printf("%d\n", cur->content);
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
