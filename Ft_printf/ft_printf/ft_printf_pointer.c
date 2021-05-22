/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_pointer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpark <gpark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 10:11:00 by gpark             #+#    #+#             */
/*   Updated: 2021/05/14 12:00:58 by gpark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libprint.h"

void		put_pointer(unsigned long long pos_n, unsigned long long base,
			char *new, t_format *format_spec)
{
	int			idx;

	idx = 0;
	while (pos_n)
	{
		new[format_spec->size[STR] - idx - 2] =
		base_to_base(pos_n % base, format_spec);
		pos_n /= base;
		idx++;
	}
	new[format_spec->size[STR] - 1] = 0;
}

size_t		ptr_base_len(unsigned long long n, unsigned long long base,
			t_format *format_spec)
{
	size_t		n_len;

	n_len = 0;
	while (n)
	{
		n /= base;
		n_len++;
	}
	format_spec->size[STR] = n_len;
	return (n_len);
}

int			ft_printf_pointer(t_format *format_spec, va_list ap)
{
	unsigned long long	pointer;
	char				*ptr_str;
	char				*print_buffer;

	pointer = va_arg(ap, unsigned long long);
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
