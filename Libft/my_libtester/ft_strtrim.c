/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpark <gpark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 00:06:20 by gpark             #+#    #+#             */
/*   Updated: 2021/05/05 00:47:29 by gpark            ###   ########.fr       */
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

size_t		find_point(char const *s1, char const *set, size_t dir)
{
	size_t	idx;

	idx = dir ? 0 : ft_strlen(s1) - 1;
	dir = dir ? 1 : -1;
	while (*(s1 + idx))
	{
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

	from = find_point(s1, set, 1);
	to = find_point(s1, set, 0);
	printf("%zu %zu\n", from, to);
	if (from > to)
		return (NULL);
	if (!(new = (char*)malloc(sizeof(char) * (to - from + 2))))
		return (NULL);
	ft_memcpy(new, s1 + from, to - from + 1);
	*(new + to - from + 1) = 0;
	return (new);
}

#define TRIM_SET_PLACEHOLDER " \n\t"

int main()
{

	char	*s1 = " Hello \t";
	char	*s2 = "Hello";
	char	*ret = ft_strtrim(s1, TRIM_SET_PLACEHOLDER);
	printf("%s\n", ret);
	if (!strcmp(ret, s2))
		printf("good\n");
}
