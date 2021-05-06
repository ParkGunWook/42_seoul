/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpark <gpark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 01:02:15 by gpark             #+#    #+#             */
/*   Updated: 2021/05/06 11:06:49 by gpark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	skip_delimiter(char const *s, char c)
{
	size_t		idx;

	idx = 0;
	while (*(s + idx))
	{
		if (*(s + idx) != c)
		{
			break ;
		}
		idx++;
	}
	return (idx);
}

static size_t	count_split(char const *s, char c)
{
	size_t	split_count;
	int		cur;
	int		prev;

	split_count = 1;
	cur = 0;
	prev = -1;
	while (*(s + cur))
	{
		if (*(s + cur) == c)
		{
			if (prev + 1 == cur && prev != 0 && prev++ && ++cur)
				continue ;
			split_count++;
			prev = cur;
		}
		else if (*(s + cur + 1) == 0 && *(s + cur) != c)
			split_count++;
		cur++;
	}
	return (split_count);
}

static int		free_all(char **ret, size_t idx)
{
	while (1)
	{
		free(ret[idx]);
		if (idx == 0)
			break ;
		idx--;
	}
	free(ret);
	return (0);
}

static int		split_str(char const *s, char c, char **ret)
{
	size_t	ret_idx;
	int		cur;
	int		prev;

	prev = -1;
	cur = 0;
	ret_idx = 0;
	while (*(s + cur))
	{
		if (*(s + cur) == c)
		{
			if (prev + 1 == cur && prev != -1 && prev++ && ++cur)
				continue;
			if (!(ret[ret_idx++] = ft_substr(s, prev + 1, cur - prev - 1)))
				return (free_all(ret, ret_idx));
			prev = cur;
		}
		else if (*(s + cur + 1) == 0 && *(s + cur) != c)
		{
			if (!(ret[ret_idx++] = ft_substr(s, prev + 1, cur - prev)))
				return (free_all(ret, ret_idx));
		}
		cur++;
	}
	return (1);
}

char			**ft_split(char const *s, char c)
{
	size_t		split_count;
	size_t		idx;
	char		**ret;

	if (!s)
		return (NULL);
	ret = NULL;
	idx = skip_delimiter(s, c);
	split_count = count_split(s + idx, c);
	if (!(ret = (char**)malloc(sizeof(char*) * split_count)))
		return (NULL);
	if (split_str(s + idx, c, ret))
	{
		*(ret + split_count - 1) = 0;
		return (ret);
	}
	else
		return (NULL);
}
