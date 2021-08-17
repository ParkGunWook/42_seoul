#include "utils.h"
#include "myloc.h"

int	myAloc(void **ptr, size_t size)
{
	*ptr = malloc(size);
	if (!(*ptr))
		return (0);
	return (size);
}

void	myFree(void **ptr)
{
	free(*ptr);
	*ptr = 0;
}
