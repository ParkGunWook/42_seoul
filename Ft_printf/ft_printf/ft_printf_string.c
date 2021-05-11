/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_string.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpark <gpark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 18:56:22 by gpark             #+#    #+#             */
/*   Updated: 2021/05/11 15:05:00 by gpark            ###   ########.fr       */
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
	{
		write(1, "This shall not printed\n", 23);
		return (0);
	}
	ft_memset(print_buffer, ' ', format_spec->size[BUFFER]);
	/*write(1, "ft start : ", 11);
	ft_putstr_fd(str, 1);
	write(1, "\n", 1);*/
	fill_print_buffer(format_spec, print_buffer, str);
	ft_putstr_size_fd(print_buffer, 1, format_spec->size[BUFFER]);
	free(print_buffer);
	return (1);
}
