#ifndef UTILS_H
# define UTILS_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct		s_list
{
	struct s_node	*head;
	struct s_node	*tail;
}					t_list;

typedef struct		s_node
{
	int 			content;
	struct s_node	*next;
	struct s_node	*prev;
}					t_node;


typedef struct		s_stack
{
	struct s_list	*list;
	size_t			size;
}					t_stack;

t_list				*initList();
int					addBack(t_list *tList, int value);
t_node				*popBack(t_list *list);
void				traverseAll(t_list *list);
void				clearList(t_list **list);

# endif
