/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ntoa_flag.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpark <gpark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 03:03:31 by gpark             #+#    #+#             */
/*   Updated: 2021/05/11 20:49:21 by gpark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libprint.h"

static char		integer_to_base(int idx)
{
	if (idx >= 10)
		return ('a' + idx - 10);
	else
		return ('0' + idx);
}

static size_t	int_len(int n, int base, t_format *format_spec)
{
	size_t		n_len;

	n_len = 0;
	while (n)
	{
		n /= base;
		n_len++;
	}
	format_spec->size[STR] = n_len;
	return (n_len);
}

static char		*zero_case(char *new, t_format *format_spec)
{
	size_t len;

	len = format_spec->precision == 0 ? 0 : 1;
	if (format_spec->flags[SPACE_FLAG] || format_spec->flags[PLUS_FLAG])
	{
		if (!(new = (char*)malloc(sizeof(char) * len + 2)))
			return (NULL);
		new[0] = format_spec->flags[SPACE_FLAG] ? ' ' : '+';
		new[1] = len == 0 ? 0 : '0';
		new[2] = 0;
		format_spec->size[STR] = len + 1;
	}
	else
	{
		if (!(new = (char*)malloc(sizeof(char) * len + 1)))
			return (NULL);
		new[0] = len == 0 ? 0 : '0';
		new[1] = 0;
		format_spec->size[STR] = len;
	}
	return (new);
}

static void		put_number(int pos_n, int base, char *new, size_t n_len)
{
	int		idx;

	idx = 0;
	while (pos_n)
	{
		new[n_len - idx - 2] = integer_to_base(pos_n % base);
		pos_n /= base;
		idx++;
	}
	new[n_len - 1] = 0;
}

char			*ft_ntoa_flag(int n, int base, t_format *format_spec)
{
	size_t			n_len;
	char			*new;

	new = NULL;
	if (n == 0)
		return (zero_case(new, format_spec));
	n_len = int_len(n, base, format_spec) + 1;
	if (n < 0 || format_spec->flags[PLUS_FLAG] ||
	format_spec->flags[SPACE_FLAG])
	{
		if (!(new = (char*)malloc(sizeof(char) * (++n_len))))
			return (NULL);
		if (n < 0)
			new[0] = '-';
		else
			new[0] = format_spec->flags[PLUS_FLAG] ? '+' : ' ';
	}
	else
	{
		if (!(new = (char*)malloc(sizeof(char) * (n_len + 1))))
			return (NULL);
	}
	n = n < 0 ? n * -1 : n;
	put_number(n, base, new, n_len);
	return (new);
}
