/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hexadecimal.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpark <gpark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 14:49:58 by gpark             #+#    #+#             */
/*   Updated: 2021/05/13 17:42:38 by gpark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libprint.h"

static void		swap_padding_and_sign(t_format *format_spec,
				char *print_buffer, size_t index)
{
	if (format_spec->flags[SHARP_FLAG])
	{
		print_buffer[0] = '0';
		print_buffer[1] = format_spec->type == L_HEXADECIMAL ? 'X' : 'x';
	}
	else
		return ;
	if (index > 1)
	{
		print_buffer[index] = '0';
		print_buffer[index + 1] = '0';
	}
	else if (index == 1)
		print_buffer[index + 1] = '0';
}

static void		fill_hex_buffer(t_format *format_spec,
				char *print_buffer, const char *int_str, unsigned int value)
{
	char	padding;

	padding = format_spec->flags[ZERO_FLAG] ? '0' : ' ';
	ft_memset(print_buffer, padding, format_spec->size[BUFFER]);
	/*write(1, "to_fill : ", 9);
	ft_putnbr_fd(format_spec->size[BUFFER], 1);
	write(1, print_buffer, format_spec->size[BUFFER]);
	write(1, "\n", 1);*/
	fill_print_buffer(format_spec, print_buffer, int_str);
	if (format_spec->flags[ZERO_FLAG] && !format_spec->flags[MINUS_FLAG] && value != 0)
		swap_padding_and_sign(format_spec, print_buffer,
		format_spec->size[BUFFER] - format_spec->size[STR]);
}

static size_t	realloc_with_precision(t_format *format_spec,
				char **int_str, unsigned int value)
{
	char	*new;

	if (format_spec->flags[SHARP_FLAG] && value != 0)
		format_spec->precision += 2;
	if (format_spec->precision <= 0 ||
	(int)ft_strlen(*int_str) > format_spec->precision)
		return (ft_strlen(*int_str));
	if (!(new = malloc(sizeof(char) * format_spec->precision)))
	{
		free(*int_str);
		*int_str = new;
		return (0);
	}
	ft_memset(new, '0', format_spec->precision);
	ft_memcpy(new + format_spec->precision - ft_strlen(*int_str),
	*int_str, ft_strlen(*int_str));
	if (format_spec->flags[SHARP_FLAG] && value != 0)
		swap_padding_and_sign(format_spec, new,
		format_spec->precision - ft_strlen(*int_str));
	free(*int_str);
	*int_str = new;
	return (format_spec->precision);
}

int				ft_printf_hexadecimal(t_format *format_spec, va_list ap)
{
	unsigned int	value;
	char			*int_str;
	char			*print_buffer;

	value = va_arg(ap, unsigned int);
	if (format_spec->flags[ZERO_FLAG] && format_spec->flags[MINUS_FLAG])
		format_spec->flags[ZERO_FLAG] = 0;
	if (!(int_str = format_spec->flags[SHARP_FLAG] ?
	ft_ptoa_flag(value, 16, format_spec) : ft_ntoa_flag(value, 16, format_spec)))
		return (0);
	/*write(1, "Int_str : ", 10);
	write(1, int_str, format_spec->size[STR]);
	write(1, "\n", 1);*/
	format_spec->size[STR] = realloc_with_precision(format_spec, &int_str, value);
	/*write(1, "Int_str : ", 10);
	write(1, int_str, format_spec->size[STR]);
	write(1, "\n", 1);*/
	if (!int_str)
		return (0);
	format_spec->size[BUFFER] =
	format_spec->width > (int)format_spec->size[STR] ?
	format_spec->width : format_spec->size[STR];
	if (!(print_buffer = alloc_print_buffer(format_spec->size[BUFFER])))
	{
		free(int_str);
		return (0);
	}
	fill_hex_buffer(format_spec, print_buffer, int_str, value);
	write(1, print_buffer, format_spec->size[BUFFER]);
	free(int_str);
	free(print_buffer);
	return (1);
}
