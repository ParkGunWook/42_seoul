/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpark <gpark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 02:58:26 by gpark             #+#    #+#             */
/*   Updated: 2021/05/04 22:18:51 by gpark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	idx;

	i = 0;
	while (*(dst + i) != 0 && i < dstsize)
		i++;
	idx = 0;
	while (i + 1 < dstsize && *(src + idx) != 0)
	{
		*(dst + i) = *(src + idx);
		i++;
		idx++;
	}
	if (i != dstsize)
		*(dst + i) = 0;
	while (*(src + idx) != 0)
	{
		idx++;
		i++;
	}
	return (i);
}
