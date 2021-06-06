/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpark <gpark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 02:37:24 by gpark             #+#    #+#             */
/*   Updated: 2021/05/04 20:27:26 by gpark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	find_from_str(char *haystack, char *needle)
{
	int		i;

	i = 0;
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
	size_t	needle_size;

	idx = 0;
	if (*needle == 0)
		return (char*)(haystack);
	needle_size = ft_strlen(needle);
	while (*(haystack + idx) != 0 && idx + needle_size <= len)
	{
		if (find_from_str((char*)(haystack + idx), (char*)needle))
			return (char*)(haystack + idx);
		idx++;
	}
	return (0);
}
