/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   myloc.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpark <gpark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 13:37:50 by gpark             #+#    #+#             */
/*   Updated: 2021/06/10 21:15:59 by gpark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"
#include "myloc.h"

int		my_aloc(void **ptr, size_t size)
{
	*ptr = malloc(size);
	if (!(*ptr))
		return (0);
	g_mlcnt++;
	return (size);
}

void	my_free(void **ptr)
{
	free(*ptr);
	g_mlcnt--;
	*ptr = 0;
}
