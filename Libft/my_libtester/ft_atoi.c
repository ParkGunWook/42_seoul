/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpark <gpark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 21:26:45 by gpark             #+#    #+#             */
/*   Updated: 2021/05/04 15:53:08 by gpark            ###   ########.fr       */
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
	return (idx);
}

int				ft_atoi(const char *str)
{
	int		ret;
	int		minus;
	size_t	idx;

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
		if ('0' <= *(str + idx) && *(str + idx) <= '9')
		{
			ret *= 10;
			ret += (int)(*(str + idx) - '0') * minus;
			idx++;
		}
		else
			break ;
	}
	return (ret);
}

int		main(void)
{
	printf("%d\n%d\n", ft_atoi("  	-2147483648"), atoi("  	-2147483648"));
	printf("%d\n%d\n", ft_atoi(" 12144 a 5145"), atoi(" 12144 a 5145"));
	printf("%d\n%d\n", ft_atoi(" -12144 a 5145"), atoi(" -12144 a 5145"));
	printf("%d\n%d\n", ft_atoi(" 12ab144 a 5145"), atoi(" 12ab144 a 5145"));
}
