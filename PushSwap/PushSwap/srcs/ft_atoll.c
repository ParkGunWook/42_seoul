/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpark <gpark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 21:26:45 by gpark             #+#    #+#             */
/*   Updated: 2021/05/04 20:27:50 by gpark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "myloc.h"
#include "utils.h"

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
	return (idx);
}

long long	ft_atoll(const char *str)
{
	long long	ret;
	long long	minus;
	size_t		idx;

	idx = space_skipper(str);
	ret = 0;
	minus = 1;
	if (*(str + idx) == '-' || *(str + idx) == '+')
	{
		if (*(str + idx) == '-')
			minus = -1;
		idx++;
	}
	while (*(str + idx))
	{
		ret *= 10;
		ret += ((long long)(*(str + idx) - '0')) * minus;
		idx++;
	}
	return (ret);
}
