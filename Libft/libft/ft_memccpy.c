/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpark <gpark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 18:12:47 by gpark             #+#    #+#             */
/*   Updated: 2021/05/15 19:05:19 by gpark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t	idx;

	idx = 0;
	while (idx < n)
	{
		*((unsigned char*)(dst + idx)) = *((unsigned char*)(src + idx));
		if (*((unsigned char*)(src + idx)) == (unsigned char)c)
			return (dst + idx + 1);
		idx++;
	}
	return (NULL);
}
