#ifndef UTILS_H
# define UTILS_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

# define DESC		0
# define ASC		1

# define PUSH		0
# define RA			1
# define RB			2

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

typedef struct 		s_array
{
	int				*array;
	size_t			size;
}					t_array;


t_list				*initList();
int					addBack(t_list *tList, int value);
t_node				*popBack(t_list *list);
void				traverseAll(t_list *list);
void				rtraverseAll(t_list *list);
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
int					isStackSorted(t_stack *st, int sortType, int n);
void				clearStack(t_stack **st);

t_list				*parser(char **argv);
char				*ft_substr(char const *s, unsigned int start, size_t len);
int					ft_strlen(const char *str);
char				*ft_itoa(int n);
long long			ft_atoll(const char *str);
size_t				ft_strlcpy(char *dst, const char *src, size_t dstsize);
void				*ft_memset(void *b, int c, size_t len);

t_array				*listToSortedArray(t_stack *aStack, int size);
void				freeSortedArray(t_array **sortedArray);

void				mainSort(t_stack *aStack, t_stack *bStack);
void				sortThree(t_stack *aStack);
void				sortFive(t_stack *aStack, t_stack *bStack);
void				sortA(t_stack *aStack, t_stack *bStack, int size);
void				sortB(t_stack *aStack, t_stack *bStack, int size);
void				getPivots(int pivots[], t_stack *st, int size);
void				recoverStack(t_stack *aStack, t_stack *bStack, int raCnt, int rbCnt);
void				sortAThree(t_stack *aStack);
void				sortBThree(t_stack *aStack, t_stack *bStack);

# endif
