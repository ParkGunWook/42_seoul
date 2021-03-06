/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_format_spec.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpark <gpark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 17:40:19 by gpark             #+#    #+#             */
/*   Updated: 2021/05/14 12:00:51 by gpark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libprint.h"

static int		get_specifier(char c)
{
	if (c == 'c' || c == 'i' || c == 'd')
		return (c == 'c' ? CHAR : INT);
	else if (c == 's' || c == 'p')
		return (c == 's' ? STRING : POINTER);
	else if (c == 'u')
		return (UNSIGNED_INT);
	else if (c == 'x' || c == 'X')
		return (c == 'x' ? S_HEXADECIMAL : L_HEXADECIMAL);
	else if (c == '%' || c == 'n')
		return (c == '%' ? PERCENT : COUNTER);
	else if (c == 'f' || c == 'g')
		return (c == 'f' ? FLOAT : GRANULATED_FLOAT);
	else if (c == 'e')
		return (EXPONENTIAL);
	else if (c == '0' || c == '-' || c == '+' || c == ' ' || c == '#')
		return (FLAG);
	else if (('0' <= c && c <= '9') || c == '*')
		return (WIDTH);
	else if (c == '.')
		return (PRECISION);
	else if (c == 'l' || c == 'h')
		return (LENGTH);
	return (0);
}

static void		get_format(const char *str, t_format *format_spec, va_list ap)
{
	size_t	i;
	size_t	n;
	int		spec;

	i = 0;
	while (*(str + i))
	{
		spec = get_specifier(*(str + i));
		if (CHAR <= spec && spec <= EXPONENTIAL)
		{
			format_spec->type = spec;
			format_spec->spec_size += 1;
			return ;
		}
		else if (FLAG <= spec && spec <= LENGTH)
			n = ft_update_options(str + i, format_spec, spec, ap);
		if (n == 0 || spec == 0)
			return ;
		i += n;
		format_spec->spec_size += n;
	}
	return ;
}

int				ft_printf_format_spec(const char *str,
							t_format *format_spec, va_list ap)
{
	int		type;

	get_format(str, format_spec, ap);
	type = format_spec->type;
	if (type == CHAR || type == INT)
		return (type == CHAR ? ft_printf_char(format_spec, ap) :
		ft_printf_int(format_spec, ap));
	else if (type == STRING)
		return (ft_printf_string(format_spec, ap));
	else if (type == POINTER)
		return (ft_printf_pointer(format_spec, ap));
	else if (type == UNSIGNED_INT)
		ft_printf_unsigned_int(format_spec, ap);
	else if (type == S_HEXADECIMAL || type == L_HEXADECIMAL)
		ft_printf_hexadecimal(format_spec, ap);
	else if (type == PERCENT)
		ft_printf_percent(format_spec);
	else
		return (0);
	return (1);
}
