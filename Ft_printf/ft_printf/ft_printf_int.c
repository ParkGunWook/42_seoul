/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpark <gpark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 18:56:22 by gpark             #+#    #+#             */
/*   Updated: 2021/05/11 20:55:23 by gpark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libprint.h"

static void		swap_padding_and_sign(t_format *format_spec,
				char *int_str, char *print_buffer, size_t index)
{
	if (int_str[0] == '-')
		print_buffer[0] = '-';
	else if (format_spec->flags[PLUS_FLAG])
		print_buffer[0] = '+';
	else if (format_spec->flags[SPACE_FLAG])
		print_buffer[0] = ' ';
	else
		return ;
	if (index != 0)
		print_buffer[index] = '0';
}

static void		fill_int_buffer(t_format *format_spec,
				char *print_buffer, const char *int_str)
{
	char	padding;

	padding = format_spec->flags[ZERO_FLAG] ? '0' : ' ';
	ft_memset(print_buffer, padding, format_spec->size[BUFFER]);
	fill_print_buffer(format_spec, print_buffer, int_str);
	if (format_spec->flags[ZERO_FLAG] && !format_spec->flags[MINUS_FLAG])
	{
		swap_padding_and_sign(format_spec, (char*)int_str, print_buffer,
		format_spec->size[BUFFER] - format_spec->size[STR]);
	}
}

static size_t	realloc_with_precision(t_format *format_spec, char **int_str)
{
	char	*new;

	if (format_spec->precision <= 0 ||
	(int)ft_strlen(*int_str) > format_spec->precision)
		return (ft_strlen(*int_str));
	if (*(int_str)[0] == '-' ||
	format_spec->flags[PLUS_FLAG] || format_spec->flags[SPACE_FLAG])
		format_spec->precision++;
	if (!(new = malloc(sizeof(char) * format_spec->precision)))
	{
		free(*int_str);
		*int_str = new;
		return (0);
	}
	ft_memset(new, '0', format_spec->precision);
	ft_memcpy(new + format_spec->precision - ft_strlen(*int_str),
	*int_str, ft_strlen(*int_str));
	swap_padding_and_sign(format_spec, *int_str, new,
	format_spec->precision - ft_strlen(*int_str));
	free(*int_str);
	*int_str = new;
	return (format_spec->precision);
}

int				ft_printf_int(t_format *format_spec, va_list ap)
{
	int		value;
	char	*int_str;
	char	*print_buffer;

	value = va_arg(ap, int);
	if (format_spec->flags[ZERO_FLAG] && format_spec->flags[MINUS_FLAG])
		format_spec->flags[ZERO_FLAG] = 0;
	if (!(int_str = ft_ntoa_flag(value, 10, format_spec)))
		return (0);
	format_spec->size[STR] = realloc_with_precision(format_spec, &int_str);
	if (!int_str)
		return (0);
	format_spec->size[BUFFER] =
	format_spec->width > (int)format_spec->size[STR] ?
	format_spec->width : format_spec->size[STR];
	if (!(print_buffer = alloc_print_buffer(format_spec->size[BUFFER])))
	{
		free(int_str);
		return (0);
	}
	fill_int_buffer(format_spec, print_buffer, int_str);
	ft_putstr_size_fd(print_buffer, 1, format_spec->size[BUFFER]);
	free(int_str);
	free(print_buffer);
	return (1);
}
