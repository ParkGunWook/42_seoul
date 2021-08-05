#ifndef UTILS_H
# define UTILS_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct		s_list
{
	int 			content;
	struct s_list	*next;
	struct s_list	*prev;
}					t_list;

t_list 		*initList(int value);
void		addBack(t_list *head, t_list **back, t_list *tList);
void 		removeBack(t_list **head, t_list **back);
void		traverseAll(t_list *front, t_list *back);
t_list		*popBack(t_list **head, t_list **back);

# endif


