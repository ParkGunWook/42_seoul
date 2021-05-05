/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpark <gpark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 01:02:15 by gpark             #+#    #+#             */
/*   Updated: 2021/05/05 17:52:01 by gpark            ###   ########.fr       */
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
			printf("cur : %d\n", cur);
			split_count++;
			prev = cur;
		}
		else if (*(s + cur + 1) == 0 && *(s + cur) != c)
		{	printf("last cur : %d\n", cur);
			split_count++;
		}cur++;
	}
	return (split_count);
}

static int		free_all(char **ret, size_t idx)
{
	free(ret[idx]);
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
			if (prev + 1 == cur && prev != 0 && prev++ && ++cur)
				continue;
			printf("%d %d\n", prev, cur);
			if (!(ret[ret_idx++] = ft_substr(s, prev + 1, cur - prev - 1)))
				return (free_all(ret, ret_idx));
			prev = cur;
		}
		else if (*(s + cur + 1) == 0 && *(s + cur) != c)
		{
			if (!(ret[ret_idx++] = ft_substr(s, prev + 1, cur - prev)))
			{
				return (free_all(ret, ret_idx));
			}
			printf("hello : %s\n", ret[ret_idx - 1]);
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

	ret = NULL;
	idx = skip_delimiter(s, c);
	split_count = count_split(s + idx, c);
	printf("%zu\n", split_count);
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
	for(int i=0;i<1;i++)
		printf("%s\n", new[i]);
	printf("\n");
	new = ft_split(s2, '1');
	for(int i=0;i<4;i++)
		printf("%s\n", new[i]);
	printf("\n");
	new = ft_split(s3, '1');
	for(int i=0;i<4;i++)
		printf("%s\n", new[i]);
	printf("\n");
}
