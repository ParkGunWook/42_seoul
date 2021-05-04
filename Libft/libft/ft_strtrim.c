/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpark <gpark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 00:06:20 by gpark             #+#    #+#             */
/*   Updated: 2021/05/05 01:01:41 by gpark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_set(const char c, char const *set)
{
	size_t	idx;

	idx = 0;
	while (*(set + idx))
	{
		if (c == *(set + idx))
			return (1);
		idx++;
	}
	return (0);
}

size_t		find_point(char const *s1, char const *set, int dir)
{
	size_t	idx;

	idx = dir ? 0 : ft_strlen(s1) - 1;
	dir = dir ? 1 : -1;
	while (*(s1 + idx))
	{
		if (idx == 0 && dir == -1)
			return (0);
		if (!is_set(*(s1 + idx), set))
		{
			break ;
		}
		idx += dir;
	}
	return (idx);
}

char		*ft_strtrim(char const *s1, char const *set)
{
	size_t	from;
	size_t	to;
	char	*new;

	if (!s1)
		return (NULL);
	from = find_point(s1, set, 1);
	to = find_point(s1, set, 0);
	if (from >= to)
	{
		if (!(new = (char*)malloc(sizeof(char) * (1))))
			return (NULL);
		*(new) = 0;
		return (new);
	}
	if (!(new = (char*)malloc(sizeof(char) * (to - from + 2))))
		return (NULL);
	ft_memcpy(new, s1 + from, to - from + 1);
	*(new + to - from + 1) = 0;
	return (new);
}
