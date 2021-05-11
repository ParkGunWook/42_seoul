/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpark <gpark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 18:56:22 by gpark             #+#    #+#             */
/*   Updated: 2021/05/11 12:53:29 by gpark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libprint.h"

static void		fill_int_buffer(t_format *format_spec, char *print_buffer,
		const char *int_str)
{
	char	to_fill;

	to_fill = format_spec->flags[ZERO_FLAG] ? '0' : ' ';
	ft_memset(print_buffer, to_fill, format_spec->size[BUFFER]);
	if ((format_spec->flags[PLUS_FLAG] || format_spec->flags[SPACE_FLAG])
	&& format_spec->flags[MINUS_FLAG])
		fill_print_buffer(format_spec, print_buffer + 1,
		int_str);
	else
		fill_print_buffer(format_spec, print_buffer, int_str);
	if (format_spec->flags[ZERO_FLAG])
	{
		print_buffer[0] = format_spec->flags[PLUS_FLAG] ? '+' : print_buffer[0];
		print_buffer[0] = format_spec->flags[SPACE_FLAG] ?
		' ' : print_buffer[0];
	}
	else if (format_spec->flags[PLUS_FLAG] && format_spec->flags[MINUS_FLAG])
		print_buffer[0] = '+';
	else if (format_spec->flags[PLUS_FLAG] && !format_spec->flags[MINUS_FLAG])
		print_buffer[format_spec->size[BUFFER] - 2 - ft_strlen(int_str)] = '+';
	print_buffer[format_spec->size[BUFFER] - 1] = 0;
}

int				ft_printf_int(t_format *format_spec, va_list ap)
{
	int		value;
	char	*int_str;
	char	*print_buffer;
	size_t	size[2];

	value = va_arg(ap, int);
	if (!(int_str = ft_itoa(value)))
		return (0);
	size[1] = ft_strlen(int_str);
	size[BUFFER] = format_spec->width > 1 ?
	format_spec->width + 1 : ft_strlen(int_str) + 1;
	if (!(print_buffer = alloc_print_buffer(size[BUFFER])))
	{
		free(int_str);
		return (0);
	}
	/*write(1, "ft start : ", 11);
	ft_putstr_fd(str, 1);
	write(1, "\n", 1);*/
	fill_int_buffer(format_spec, print_buffer, int_str);
	ft_putstr_fd(print_buffer, 1);
	format_spec->spec_size += 2;
	free(int_str);
	free(print_buffer);
	return (1);
}
