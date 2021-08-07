#include "utils.h"
#include "myloc.h"

t_list 			*initList()
{
	t_list	*tList;

	tList = NULL;
	myAloc((void *)&tList, sizeof(t_list));
	if (tList == NULL)
		return NULL;
	tList->head = NULL;
	tList->tail = NULL;
	return (tList);
}

int				addBack(t_list *tList, int value)
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

t_node			*popBack(t_list *list)
{
	t_node	*node;

	if (list->head == list->tail)
	{
		if (list->head == NULL)
			return (NULL);
		myAloc((void **)&node, sizeof(t_node));
		if (node == NULL)
			return (NULL);
		node->content = list->head->content;
		myFree((void **)&(list->head));
		list->tail = NULL;
		return (node);
	}
	node = (list->tail);
	list->tail->prev->next = list->head;
	list->tail->next->prev = list->tail->prev;
	list->tail = list->tail->prev;
	return (node);
}

static	void	clearNodes(t_list *list, t_node **curNode)
{
	if (*curNode == list->tail)
	{
		myFree((void **)curNode);
		return ;
	}
	else
	{
		clearNodes(list, &((*curNode)->next));
		myFree((void **)curNode);
	}
}

void			clearList(t_list **list)
{
	if ((*list)->head != NULL)
		clearNodes(*list, &(*list)->head);
	myFree((void **)list);
}
