/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpark <gpark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 14:22:14 by gpark             #+#    #+#             */
/*   Updated: 2021/05/11 14:00:30 by gpark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libprint.h"

static void	init_formatter(t_format *format_spec)
{
	int	i;

	i = 0;
	while (i < 5)
		format_spec->flags[i++] = 0;
	i = 0;
	while (i < 2)
		format_spec->size[i++] = 0;
	format_spec->type = 0;
	format_spec->spec_size = 1;
	format_spec->width = -1;
	format_spec->precision = -1;
	format_spec->length = -1;
}

int			ft_printf(const char *str, ...)
{
	size_t				i;
	size_t				num_print;
	va_list				ap;
	t_format			format_spec;

	va_start(ap, str);
	num_print = 0;
	i = 0;
	while (*(str + i))
	{
		//write(1, (str + i), 1);
		/*write(1, "idx : ", 6);
		ft_putnbr_fd(i, 1);
		write(1, "\n", 1);*/
		if (*(str + i) != '%')
		{
			ft_putchar_fd(*(str + i), 1);
			i++;
			num_print++;
		}
		else
		{
			init_formatter(&format_spec);
			ft_printf_format_spec(str + i + 1, &format_spec, ap);
			//ft_putnbr_fd(format_spec.spec_size, 1);
			i += format_spec.spec_size;
			num_print += format_spec.size[BUFFER];
		}
	}
	return (num_print);
}
