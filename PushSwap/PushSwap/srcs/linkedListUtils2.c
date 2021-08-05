#include "utils.h"
#include "myloc.h"

void		traverseAll(t_list *front, t_list *back)
{
	int cnt = 0;
	printf("start Traversal\n");
	if (front == NULL)
		return ;
	while (front != back)
	{
		printf("%d : %d\n",cnt+1, front->content);
		front = front->next;
		cnt++;
		if (cnt == 10)
			break;
	}
	printf("%d : %d\n",cnt+1, front->content);
	return ;
}
