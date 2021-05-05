/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpark <gpark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 17:08:08 by gpark             #+#    #+#             */
/*   Updated: 2021/05/05 18:56:38 by gpark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	idx;

	if (dst == 0 && src == 0)
		return (dst);
	idx = 0;
	while (idx < n)
	{
		*((unsigned char*)(dst + idx)) = *((unsigned char*)(src + idx));
		idx++;
	}
	return (dst);
}
