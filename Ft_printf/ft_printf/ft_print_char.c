/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpark <gpark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 18:56:22 by gpark             #+#    #+#             */
/*   Updated: 2021/05/09 22:56:22 by gpark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libprint.h"

int		ft_print_char(t_format *format_spec, va_list ap)
{
	char	c;
	char	*c_str;
	char	*print_buffer;
	size_t	buffer_size;


	buffer_size = format_spec->width > 1 ? format_spec->width + 1 : 1 + 1;
	write(1, "width : ", 8);
	ft_putnbr_fd(buffer_size, 1);
	write(1, "\n", 1);
	if (!(print_buffer = alloc_print_buffer(buffer_size)))
		return (0);
	ft_memset(print_buffer, ' ', buffer_size);
	c = va_arg(ap, int);
	if (!(c_str = malloc(sizeof(char) * 2)))
		return (0);
	c_str[0] = c;
	c_str[1] = 0;
	fill_print_buffer(format_spec, print_buffer, c_str, buffer_size);
	ft_putstr_fd(print_buffer, 1);
	format_spec->spec_size = 2;
	free(c_str);
	free(print_buffer);
	return (1);
}
