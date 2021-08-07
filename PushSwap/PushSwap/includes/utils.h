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
	char			name;
	size_t			size;
}					t_stack;

t_list				*initList();
int					addBack(t_list *tList, int value);
t_node				*popBack(t_list *list);
void				traverseAll(t_list *list);
void				clearList(t_list **list);
void				addBackNode(t_list *tList, t_node *curNode);

t_stack				*initStack(char name);
int					sa(t_stack *aStack);
int					sb(t_stack *bStack);
int					ss(t_stack *aStack, t_stack *bStack);
int					pa(t_stack *aStack, t_stack *bStack);
int					pb(t_stack *aStack, t_stack *bStack);
void				ra(t_stack *aStack);
void				rb(t_stack *bStack);
void				rr(t_stack *aStack, t_stack *bStack);
void				rra(t_stack *aStack);
void				rrb(t_stack *bStack);
void				rrr(t_stack *aStack, t_stack *bStack);
void				clearStacks(t_stack **aStack, t_stack **bStack);

# endif
