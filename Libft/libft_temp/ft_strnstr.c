/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpark <gpark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 02:37:24 by gpark             #+#    #+#             */
/*   Updated: 2021/05/04 17:52:54 by gpark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	find_from_str(char *haystack, char *needle)
{
	int		i;

	while (*(needle + i) != 0)
	{
		if (*(haystack + i) != *(needle + i))
			return (0);
		i++;
	}
	return (1);
}

char		*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	idx;

	idx = 0;
	if (*needle == 0)
		return (haystack);
	while (*(haystack + idx) != 0 && idx < len)
	{
		if (find_from_str(haystack + idx, needle) == 1)
		{
			return (haystack + idx);
		}
		idx++;
	}
	return (0);
}
