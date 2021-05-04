/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpark <gpark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 23:30:09 by gpark             #+#    #+#             */
/*   Updated: 2021/05/04 21:07:40 by gpark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	while (*(src + i) != 0 && i + 1 < dstsize)
	{
		*(dst + i) = *(src + i);
		i++;
	}
	if ((dst + i) != 0)
		*(dst + i) = 0;
	while (*(src + i) != 0)
	{
		i++;
	}
	return (i);
}
