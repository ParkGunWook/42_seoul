/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpark <gpark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 18:56:22 by gpark             #+#    #+#             */
/*   Updated: 2021/05/10 17:44:36 by gpark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libprint.h"

int		ft_printf_int(t_format *format_spec, va_list ap)
{
	int		value;
	char	to_fill;
	char	*int_str;
	char	*print_buffer;
	size_t	buffer_size;

	value = va_arg(ap, int);
	if (!(int_str = ft_itoa(value)))
		return (0);
	to_fill = format_spec->flags[ZERO_FLAG] ? '0' : ' ';
	buffer_size = format_spec->width > 1 ?
	format_spec->width + 1 : ft_strlen(int_str) + 1;
	if (!(print_buffer = alloc_print_buffer(buffer_size)))
	{
		free(int_str);
		return (0);
	}
	ft_memset(print_buffer, to_fill, buffer_size);
	/*write(1, "ft start : ", 11);
	ft_putstr_fd(str, 1);
	write(1, "\n", 1);*/
	fill_print_buffer(format_spec, print_buffer, int_str, buffer_size);
	if (format_spec->flags[MINUS_FLAG])
		print_buffer[ft_strlen(int_str)] = ' ';
	print_buffer[buffer_size - 1] = 0;
	ft_putstr_fd(print_buffer, 1);
	format_spec->spec_size += 2;
	free(int_str);
	free(print_buffer);
	return (1);
}
