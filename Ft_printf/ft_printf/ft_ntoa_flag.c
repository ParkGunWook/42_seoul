/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ntoa_flag.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpark <gpark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 03:03:31 by gpark             #+#    #+#             */
/*   Updated: 2021/05/23 00:11:58 by gpark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libprint.h"

static size_t	base_len(long long n, long long base, t_format *format_spec)
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
		if (!(new = (char*)malloc(sizeof(char) * (len + 1))))
			return (NULL);
		new[0] = len == 0 ? 0 : '0';
		if (len != 0)
			new[1] = 0;
		format_spec->size[STR] = len;
	}
	return (new);
}

static void		put_number(long long pos_n, long long base,
				char *new, t_format *format_spec)
{
	int			idx;

	idx = 0;
	while (pos_n)
	{
		new[format_spec->size[STR] - idx - 2] =
		base_to_base(pos_n % base, format_spec);
		pos_n /= base;
		idx++;
	}
	new[format_spec->size[STR] - 1] = 0;
}

char			*ft_ntoa_flag(long long n, long long base,
				t_format *format_spec)
{
	char			*new;

	new = NULL;
	if (n == 0)
		return (zero_case(new, format_spec));
	format_spec->size[STR] = base_len(n, base, format_spec) + 1;
	if ((n < 0 || format_spec->flags[PLUS_FLAG] ||
	format_spec->flags[SPACE_FLAG]))
	{
		if (!(new = (char*)malloc(sizeof(char) *
		(++format_spec->size[STR] + 1))))
			return (NULL);
		if (n < 0)
			new[0] = '-';
		else
			new[0] = format_spec->flags[PLUS_FLAG] ? '+' : ' ';
	}
	else
	{
		if (!(new = (char*)malloc(sizeof(char) * (format_spec->size[STR] + 1))))
			return (NULL);
	}
	n = n < 0 ? n * -1 : n;
	put_number(n, base, new, format_spec);
	return (new);
}

char			*ft_ptoa_flag(unsigned long long n, unsigned long long base,
				t_format *format_spec)
{
	char			*new;

	new = NULL;
	if (n == 0 &&
	S_HEXADECIMAL <= format_spec->type && format_spec->type <= L_HEXADECIMAL)
		return (zero_case(new, format_spec));
	if (n == 0)
		format_spec->size[STR] = format_spec->precision == 0 ? 3 : 4;
	else
		format_spec->size[STR] = ptr_base_len(n, base, format_spec) + 3;
	if (!(new = (char*)malloc(sizeof(char) * (format_spec->size[STR] + 1))))
		return (NULL);
	new[0] = '0';
	new[1] = format_spec->type == L_HEXADECIMAL ? 'X' : 'x';
	if (format_spec->precision != 0 && n == 0)
		new[2] = '0';
	put_pointer(n, base, new, format_spec);
	return (new);
}
