/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpark <gpark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 23:30:09 by gpark             #+#    #+#             */
/*   Updated: 2021/06/14 15:52:57 by gpark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "myloc.h"
#include "utils.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	if (!dst && !src)
		return (0);
	i = 0;
	while (*(src + i) != 0 && i + 1 < dstsize)
	{
		*(dst + i) = *(src + i);
		i++;
	}
	if (dstsize != 0)
		*(dst + i) = 0;
	while (*(src + i) != 0)
	{
		i++;
	}
	return (i);
}
