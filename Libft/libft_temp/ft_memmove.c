/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpark <gpark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 15:38:47 by gpark             #+#    #+#             */
/*   Updated: 2021/05/04 20:20:49 by gpark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	void	original_memmove(void *dst, const void *src, size_t len)
{
	size_t	idx;

	idx = 0;
	while (idx < len)
	{
		*((unsigned char*)(dst + idx)) = *((unsigned char*)src + idx);
		idx++;
	}
}

static	void	reverse_memmove(void *dst, const void *src, size_t len)
{
	size_t idx;

	idx = len;
	while (idx != 0)
	{
		idx--;
		*((unsigned char*)dst + idx) = *((unsigned char*)src + idx);
	}
}

void			*ft_memmove(void *dst, const void *src, size_t len)
{
	if (!dst && !src)
		return (dst);
	if (dst > src)
		reverse_memmove(dst, src, len);
	else
		original_memmove(dst, src, len);
	return (dst);
}
