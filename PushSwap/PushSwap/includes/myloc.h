#ifndef MYLOC_H
# define MYLOC_H

# include <stdlib.h>

extern int		g_mlcnt;

int				myAloc(void **ptr, size_t size);
void			myFree(void **ptr);

#endif