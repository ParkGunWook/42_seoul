#include "utils.h"
#include "myloc.h"

int 		myAloc(void **ptr, size_t size)
{
	*ptr = malloc(size);
	if (!(*ptr))
		return (0);
	//g_mlcnt++;
	return (size);
}

void 		myFree(void **ptr)
{
	free(*ptr);
	//g_mlcnt--;
	*ptr = 0;
}
