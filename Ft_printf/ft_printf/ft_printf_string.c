/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_string.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpark <gpark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 18:56:22 by gpark             #+#    #+#             */
/*   Updated: 2021/05/13 19:42:02 by gpark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libprint.h"

int		ft_printf_string(t_format *format_spec, va_list ap)
{
	char	*str;
	char	*print_buffer;

	str = va_arg(ap, char*);
	if (str == NULL)
		str = "(null)";
	format_spec->size[STR] = ft_strlen(str);
	if (format_spec->precision >= 0 &&
	format_spec->precision <= (int)format_spec->size[STR])
		format_spec->size[STR] = format_spec->precision;
	format_spec->size[BUFFER] =
	format_spec->width > (int)format_spec->size[STR] ?
	format_spec->width : format_spec->size[STR];
	if (!(print_buffer = alloc_print_buffer(format_spec->size[BUFFER]))
	&& format_spec->size[BUFFER] != 0)
		return (0);
	ft_memset(print_buffer, ' ', format_spec->size[BUFFER]);
	fill_print_buffer(format_spec, print_buffer, str);
	write(1, print_buffer, format_spec->size[BUFFER]);
	free(print_buffer);
	return (1);
}
