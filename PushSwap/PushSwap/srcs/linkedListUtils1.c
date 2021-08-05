#include "utils.h"
#include "myloc.h"

t_list 		*initList(int value)
{
	t_list	*tList;

	myAloc((void *)&tList, sizeof(tList));
	if (tList == NULL)
		return (NULL);
	tList->content = value;
	tList->next = NULL;
	tList->prev = NULL;
	return (tList);
}

void		addBack(t_list *head, t_list **back, t_list *tList)
{
	if (head == *back)
	{
		head->next = tList;
		head->prev = tList;
		tList->prev = head;
		tList->next = head;
		(*back) = tList;
		return ;
	}
	head = (*back)->next;
	tList->next = head;
	tList->prev = (*back);
	(*back)->next = tList;
	head->prev = tList;
	(*back) = tList;
}

void 		removeBack(t_list **head, t_list **back)
{
	t_list	*temp;

	if ((*head) == (*back))
	{
		printf("One size case\n");
		myFree((void *)head);
		(*head) = NULL;
		(*back) = NULL;
		return ;
	}
	temp = (*back);
	(*back)->prev->next = (*head);
	(*back)->next->prev = temp->prev;
	(*back) = temp->prev;
	myFree((void *)(&temp));
}

t_list		*popBack(t_list **head, t_list **back)
{
	t_list	*temp;

	if ((*head) == (*back))
	{
		(*head) = NULL;
		(*back) = NULL;
		return (*back);
	}
	temp = (*back);
	(*back)->prev->next = temp->next;
	(*back)->next->prev = temp->prev;
	(*back) = temp->prev;
	return (temp);
}
