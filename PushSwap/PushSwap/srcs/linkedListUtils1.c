#include "utils.h"
#include "myloc.h"

t_list 		*initList()
{
	t_list	*tList;

	printf("startInit\n");
	tList = NULL;
	myAloc((void *)&tList, sizeof(t_list));
	if (tList == NULL)
		return NULL;
	tList->head = NULL;
	tList->tail = NULL;
	printf("%p : endInit\n", tList);
	return (tList);
}

int		addBack(t_list *tList, int value)
{
	t_node	*curNode;

	curNode = NULL;
	myAloc((void *)&curNode, sizeof(t_node));
	if (curNode == NULL)
		return (1);
	curNode->content = value;
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
	return (1);
}

t_node		*popBack(t_list *list)
{
	t_node	*node;

	if (list->head == list->tail)
	{
		if (list->head == NULL)
			return NULL;
		list->head = NULL;
		list->tail = NULL;
		return (list->head);
	}
	node = (list->tail);
	list->tail->prev->next = list->head;
	list->tail->next->prev = list->tail->prev;
	list->tail = list->tail->prev;
	return (node);
}

void		clearList(t_list **list)
{
	t_node		**temp;
	t_node		**toFree;

	int cnt = 0;
	toFree = &((*list)->head);
	while ((*toFree) != NULL)
	{
		printf("ToFree data : %d %p\n", (*toFree)->content, *toFree);
		temp = &((*toFree)->next);
		printf("Next data : %d %p\n", (*temp)->content, *temp);
		myFree((void *)toFree);
		*toFree = *temp;
		if (cnt == 0){
			printf("%p\n", (*list)->head);
			printf("%p\n", *toFree);
		}
		if (cnt == 10)
			break;
		cnt++;
	}
	myFree((void *)list);
}
