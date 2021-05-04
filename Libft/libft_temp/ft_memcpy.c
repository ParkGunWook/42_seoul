/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpark <gpark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 17:08:08 by gpark             #+#    #+#             */
/*   Updated: 2021/05/03 18:20:28 by gpark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	idx;

	idx = 0;
	while (idx < n)
	{
		if (dst + idx == src + idx)
			return (dst);
		idx++;
	}
	idx = 0;
	while (idx < n)
	{
		*((unsigned char*)(dst + idx)) = *((unsigned char*)(src + idx));
		idx++;
	}
	return (dst);
}
