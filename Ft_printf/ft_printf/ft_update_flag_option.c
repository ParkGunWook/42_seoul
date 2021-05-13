/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_update_flag_option.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpark <gpark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 22:01:57 by gpark             #+#    #+#             */
/*   Updated: 2021/05/13 21:13:04 by gpark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libprint.h"

static size_t	ft_update_flag_option(const char *str, t_format *format_spec)
{
	if (format_spec->width != -1 || format_spec->precision != -1
	|| format_spec->length != -1)
		return (0);
	else if (*str == '0')
	{
		format_spec->flags[ZERO_FLAG] = 1;
		format_spec->flags[PZERO_FLAG] = 1;
	}
	else if (*str == '-')
		format_spec->flags[MINUS_FLAG] = 1;
	else if (*str == '#')
		format_spec->flags[SHARP_FLAG] = 1;
	else if (*str == ' ' && !format_spec->flags[PLUS_FLAG])
		format_spec->flags[SPACE_FLAG] = 1;
	else if (*str == '+' && !format_spec->flags[SPACE_FLAG])
		format_spec->flags[PLUS_FLAG] = 1;
	else
		return (0);
	return (1);
}

static size_t	ft_update_width_option(const char *str,
				t_format *format_spec, va_list ap)
{
	size_t	len;
	int		n;
	char	*new;

	if (format_spec->width != -1 || format_spec->precision != -1 ||
	format_spec->length != -1)
		return (0);
	n = (*str == '*') ? va_arg(ap, int) : ft_atoi(str);
	if (*str == '*' && n == -2147483648)
		return (0);
	format_spec->width = n;
	if (*str == '*' && n < 0)
	{
		format_spec->width = -n;
		format_spec->flags[MINUS_FLAG] = 1;
	}
	if (!(new = ft_itoa(n)))
		return (0);
	len = ft_strlen(new);
	free(new);
	return (*str == '*' ? 1 : (len));
}

static size_t	ft_update_precision_option(const char *str,
				t_format *format_spec, va_list ap)
{
	size_t	len;
	int		n;
	char	*new;

	if (format_spec->precision != -1 || format_spec->length != -1)
		return (0);
	if (*(str + 1) != '*' && *(str + 1) != '-' &&
		!('0' <= *(str + 1) && *(str + 1) <= '9'))
	{
		format_spec->precision = 0;
		format_spec->flags[ZERO_FLAG] = 0;
		return (1);
	}
	n = *(str + 1) == '*' ? va_arg(ap, int) : ft_atoi(str + 1);
	new = ft_itoa(n);
	if (*(str + 1) == '0' && n == 0)
		len = ft_strlen(new);
	else
		len = ft_strlen(new) + zero_counter(str + 1);
	if (n >= 0)
	{
		format_spec->precision = n;
		format_spec->flags[ZERO_FLAG] = 0;
	}
	else
		format_spec->precision = -2;
	free(new);
	return (*(str + 1) == '*' ? 2 : (len + 1));
}

static size_t	ft_update_length_option(const char *str, t_format *format_spec)
{
	if (*str == 'l' && *(str + 1) == 'l')
		format_spec->length = LL_FLAG;
	else if (*str == 'h' && *(str + 1) == 'h')
		format_spec->length = HH_FLAG;
	else if (*str == 'l')
		format_spec->length = L_FLAG;
	else if (*str == 'h')
		format_spec->length = H_FLAG;
	if (format_spec->length <= 1)
		return (1);
	else
		return (2);
}

size_t			ft_update_options(const char *str,
				t_format *format_spec, int spec, va_list ap)
{
	size_t	n;

	n = 0;
	if (spec == FLAG)
		n = ft_update_flag_option(str, format_spec);
	else if (spec == WIDTH)
		n = ft_update_width_option(str, format_spec, ap);
	else if (spec == PRECISION)
		n = ft_update_precision_option(str, format_spec, ap);
	else if (spec == LENGTH)
		n = ft_update_length_option(str, format_spec);
	return (n);
}
