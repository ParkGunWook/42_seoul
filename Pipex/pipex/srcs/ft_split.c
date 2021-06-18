/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpark <gpark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 01:02:15 by gpark             #+#    #+#             */
/*   Updated: 2021/06/18 21:20:12 by gpark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int				free_split(char **ret)
{
	int		idx;

	idx = 0;
	while (ret[idx])
	{
		free(ret[idx]);
		idx++;
	}
	free(ret);
	return (0);
}

static void		get_next_point(const char *s, int *s_idx, int *i, int *next_s)
{
	char c;

	if (s[*i] == '\"' || s[*i] == '\'')
	{
		if (s[*i] == '\"')
			c = '\"';
		else
			c = '\'';
		(*s_idx)++;
		(*i)++;
		while (s[*i] && s[*i] != c)
			(*i)++;
		(*next_s) = (*i);
		(*next_s)++;
		while (s[*next_s] && s[*next_s] == ' ')
			(*next_s)++;
	}
	else
	{
		while (s[*i] && s[*i] != ' ')
			(*i)++;
		(*next_s) = (*i);
		while (s[*next_s] && s[*next_s] == ' ')
			(*next_s)++;
	}
}

static int		recursplit(const char *s, char ***ret, int s_idx, int split_idx)
{
	int		i;
	int		next_s;

	if (ft_strlen(s) == s_idx)
	{
		printf("split_idx :%d\n", split_idx);
		*ret = malloc(sizeof(char*) * split_idx + 1);
		if (!(*ret))
			return (0);
		ret[split_idx] = 0;
		return (1);
	}
	i = s_idx;
	next_s = 0;
	get_next_point(s, &s_idx, &i, &next_s);
	printf("s_idx : %d i : %d next_s %d\n", s_idx, i, next_s);
	recursplit(s, ret, next_s, split_idx + 1);
	printf("s_idx : %d i : %d next_s %d\n", s_idx, i, next_s);
	(*ret)[split_idx] = ft_substr(s, s_idx, i - s_idx);
	printf("sub str %s\n", (*ret)[split_idx]);
	if (!((*ret)[split_idx]))
	{
		free_split(*ret);
		return (0);
	}
	return (1);
}

char			**ft_split(char const *s, char c)
{
	int		i;
	char	**ret;

	i = 0;
	while (s[i] == c)
		i++;
	recursplit(s, &ret, i, 0);
	i = 0;
	while (ret[i])
	{
		printf("%s\n", ret[i]);
		i++;
	}
	return (ret);
}
