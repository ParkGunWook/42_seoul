/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_string.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpark <gpark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 18:56:22 by gpark             #+#    #+#             */
/*   Updated: 2021/05/11 12:51:02 by gpark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libprint.h"

int		ft_printf_string(t_format *format_spec, va_list ap)
{
	char	*str;
	char	*print_buffer;
	size_t	size[2];

	str = va_arg(ap, char*);
	format_spec->size[BUFFER] = format_spec->width > 1 ?
	format_spec->width : ft_strlen(str);
	format_spec->size[STR] = ft_strlen(str);
	if (!(print_buffer = alloc_print_buffer(format_spec->size[BUFFER])))
		return (0);
	ft_memset(print_buffer, ' ', format_spec->size[BUFFER]);
	/*write(1, "ft start : ", 11);
	ft_putstr_fd(str, 1);
	write(1, "\n", 1);*/
	fill_print_buffer(format_spec, print_buffer, str);
	if (format_spec->flags[MINUS_FLAG])
		print_buffer[format_spec->size[STR]] = ' ';
	print_buffer[size[BUFFER] - 1] = 0;
	ft_putstr_fd(print_buffer, 1);
	format_spec->spec_size += 2;
	free(print_buffer);
	return (1);
}
