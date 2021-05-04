/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpark <gpark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 14:08:32 by gpark             #+#    #+#             */
/*   Updated: 2021/05/04 14:12:44 by gpark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*new;
	size_t	idx;

	idx = 0;
	new = (void*)malloc(count * size);
	if (!new)
		return (NULL);
	while (idx < size * count)
	{
		*((unsigned char*)new + idx) = 0;
		idx++;
	}
	return (new);
}
