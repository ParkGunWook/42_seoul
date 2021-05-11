/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpark <gpark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 18:56:22 by gpark             #+#    #+#             */
/*   Updated: 2021/05/11 13:51:28 by gpark            ###   ########.fr       */
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
	if (!(c_str = malloc(sizeof(char) * 2)))
		return (0);
	c_str[0] = c;
	fill_print_buffer(format_spec, print_buffer, c_str);
	if (format_spec->flags[MINUS_FLAG])
		print_buffer[1] = ' ';
	ft_putstr_size_fd(print_buffer, 1, format_spec->size[BUFFER]);
	free(c_str);
	free(print_buffer);
	return (1);
}
