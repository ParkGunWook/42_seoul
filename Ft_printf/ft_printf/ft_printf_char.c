/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpark <gpark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 18:56:22 by gpark             #+#    #+#             */
/*   Updated: 2021/05/13 20:34:09 by gpark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libprint.h"

int		ft_printf_char(t_format *format_spec, va_list ap)
{
	char	c;
	char	*c_str;
	char	*print_buffer;

	c = va_arg(ap, int);
	format_spec->size[BUFFER] = format_spec->width > 1 ? format_spec->width : 1;
	format_spec->size[STR] = 1;
	if (!(print_buffer = alloc_print_buffer(format_spec->size[BUFFER])))
		return (0);
	ft_memset(print_buffer, ' ', format_spec->size[BUFFER]);
	if (!(c_str = malloc(sizeof(char))))
		return (0);
	c_str[0] = c;
	fill_print_buffer(format_spec, print_buffer, c_str);
	write(1, print_buffer, format_spec->size[BUFFER]);
	free(c_str);
	free(print_buffer);
	return (1);
}

int		ft_printf_percent(t_format *format_spec)
{
	char	c;
	char	*print_buffer;
	char	padding;

	if (format_spec->flags[PZERO_FLAG] && !format_spec->flags[MINUS_FLAG])
		padding = '0';
	else
		padding = ' ';
	format_spec->size[BUFFER] = format_spec->width > 1 ? format_spec->width : 1;
	format_spec->size[STR] = 1;
	if (!(print_buffer = alloc_print_buffer(format_spec->size[BUFFER])))
		return (0);
	ft_memset(print_buffer, padding, format_spec->size[BUFFER]);
	c = '%';
	fill_print_buffer(format_spec, print_buffer, &c);
	if (!format_spec->flags[MINUS_FLAG] && format_spec->flags[PZERO_FLAG])
	{
		print_buffer[0] = '0';
		print_buffer[format_spec->size[BUFFER] - 1] = '%';
	}
	write(1, print_buffer, format_spec->size[BUFFER]);
	free(print_buffer);
	return (1);
}
