/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpark <gpark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 01:02:15 by gpark             #+#    #+#             */
/*   Updated: 2021/05/06 11:06:17 by gpark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

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
		printf("idx : %zu\n", idx);
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
			if (!(ret[ret_idx++] = ft_substr(s, prev + 1, cur - prev - 1)) || ret_idx == 3)
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

int 			main()
{
	// char s1[100] = "";
	char s2[100] = "11ababe11abae11ee";
	char s3[100] = "ababe11abae11ee1";
	char **new = ft_split(NULL, 0);
	for(int i=0;i<0;i++)
		printf("%s\n", new[i]);
	printf("\n");
	new = ft_split(s2, '1');
	printf("s2 done\n");
	for(int i=0;i<4;i++)
		printf("%s\n", new[i]);
	printf("\n");
	new = ft_split(s3, '1');
	printf("s3 done\n");
	for(int i=0;i<4;i++)
		printf("%s\n", new[i]);
	printf("\n");
}
