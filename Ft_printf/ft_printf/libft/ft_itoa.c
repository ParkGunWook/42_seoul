/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpark <gpark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 03:03:31 by gpark             #+#    #+#             */
/*   Updated: 2021/05/05 03:45:29 by gpark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	int_len(int n)
{
	size_t		n_len;

	n_len = 0;
	while (n)
	{
		n /= 10;
		n_len++;
	}
	return (n_len);
}

char			*zero_case(char *new)
{
	if (!(new = (char*)malloc(sizeof(char) * 2)))
		return (NULL);
	new[0] = '0';
	new[1] = 0;
	return (new);
}

void			put_number(unsigned int pos_n, char *new, size_t n_len)
{
	int		idx;

	idx = 0;
	while (pos_n)
	{
		new[n_len - idx - 2] = (char)('0' + pos_n % 10);
		pos_n /= 10;
		idx++;
	}
	new[n_len - 1] = 0;
}

char			*ft_itoa(int n)
{
	size_t			n_len;
	char			*new;
	unsigned int	pos_n;

	new = NULL;
	if (n == 0)
		return (zero_case(new));
	n_len = int_len(n);
	if (n < 0)
	{
		if (!(new = (char*)malloc(sizeof(char) * (n_len + 2))))
			return (NULL);
		n_len = n_len + 2;
		new[0] = '-';
		pos_n = (unsigned int)(n * -1);
	}
	else
	{
		if (!(new = (char*)malloc(sizeof(char) * (n_len++ + 1))))
			return (NULL);
		pos_n = (unsigned int)(n);
	}
	put_number(pos_n, new, n_len);
	return (new);
}
