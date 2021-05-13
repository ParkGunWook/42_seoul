/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_pointer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpark <gpark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 10:11:00 by gpark             #+#    #+#             */
/*   Updated: 2021/05/13 13:51:06 by gpark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libprint.h"

int		ft_printf_pointer(t_format *format_spec, va_list ap)
{
	size_t		pointer;
	char		*ptr_str;
	char		*print_buffer;

	pointer = va_arg(ap, size_t);
	if (!(ptr_str = ft_ptoa_flag(pointer, 16, format_spec)))
		return (0);
	format_spec->size[STR] = ft_strlen(ptr_str);
	format_spec->size[BUFFER] =
	format_spec->width > (int)format_spec->size[STR] ?
	format_spec->width : format_spec->size[STR];
	if (!(print_buffer = alloc_print_buffer(format_spec->size[BUFFER]))
	&& format_spec->size[BUFFER] != 0)
		return (0);
	ft_memset(print_buffer, ' ', format_spec->size[BUFFER]);
	fill_print_buffer(format_spec, print_buffer, ptr_str);
	write(1, print_buffer, format_spec->size[BUFFER]);
	free(print_buffer);
	free(ptr_str);
	return (1);
}
