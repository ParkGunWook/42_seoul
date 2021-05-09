/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_format_spec.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpark <gpark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 17:40:19 by gpark             #+#    #+#             */
/*   Updated: 2021/05/09 22:34:03 by gpark            ###   ########.fr       */
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
	else if ('0' <= c && c <= '9')
		return (WIDTH);
	else if (c == '.')
		return (PRECISION);
	else if (c == 'l' || c == 'h')
		return (LENGTH);
	return (0);
}

static size_t	get_format(const char *str, t_format *format_spec)
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
			return (i);
		}
		else if (FLAG <= spec && spec <= LENGTH)
			n = ft_update_options(str + i, format_spec, spec);
		else
			return (0);
		if (n == 0)
			return (0);
		i += n;
	}
	return (0);
}

void		ft_printf_format_spec(const char *str,
							t_format *format_spec, va_list ap)
{
	int		type;

	get_format(str, format_spec);
	type = format_spec->type;
	ft_print_char(format_spec, ap);
	/*if (type == CHAR || type == INT)
		type == CHAR ? ft_print_char(format_spec, ap) :
			ft_print_int(format_spec, ap);
	else if (type == STRING)
		ft_print_string(format_spec, ap);
	else if (type == POINTER)
		ft_print_pointer(format_spec, ap);
	else if (type == UNSIGNED_INT)
		ft_print_unsigned_int(format_spec, ap);
	else if (type == S_HEXADECIMAL || type == L_HEXADECIMAL)
		ft_print_hexadecimal(format_spec, ap);
	else if (type == PERCENT)
		ft_print_percent(format_spec, ap);
	else if (type == COUNTER)
		ft_print_counter(format_spec, ap);
	else if (type == FLOAT)
		ft_print_float(format_spec, ap);
	else if (type == GRANULATED_FLOAT)
		ft_print_granulated(format_spec, ap);*/
}
