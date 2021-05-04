/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpark <gpark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 21:26:45 by gpark             #+#    #+#             */
/*   Updated: 2021/05/04 19:58:15 by gpark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t	space_skipper(const char *str)
{
	size_t	idx;

	idx = 0;
	while (*(str + idx))
	{
		if (*(str + idx) == 32 || (9 <= *(str + idx) && *(str + idx) <= 13))
			idx++;
		else
			break ;
	}
	printf("idx : %zu\n", idx);
	return (idx);
}

int				ft_atoi(const char *str)
{
	int		ret;
	int		minus;
	size_t	idx;

	idx = space_skipper(str);
	ret = 0;
	if (*(str + idx) == '-' || *(str + idx) == '+')
	{
		if (*(str + idx) == '-')
			minus = -1;
		idx++;
	}
	while (*(str + idx))
	{
		if ('0' <= *(str + idx) && *(str + idx) <= '9')
		{
			ret *= 10;
			ret += (int)(*(str + idx) - '0') * minus;
			idx++;
			printf("%d\n", ret);
		}
		else
			break ;
	}
	return (ret);
}
