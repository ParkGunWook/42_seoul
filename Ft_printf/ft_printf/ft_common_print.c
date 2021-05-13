/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_common_print.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpark <gpark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 19:02:29 by gpark             #+#    #+#             */
/*   Updated: 2021/05/13 16:56:20 by gpark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libprint.h"

char	*alloc_print_buffer(size_t size)
{
	char	*new;

	if (!(new = (char*)malloc(sizeof(char) * (size))))
		return (NULL);
	return (new);
}

void	fill_print_buffer(t_format *format_spec, char *print_buffer,
		const char *str)
{
	format_spec->flags[MINUS_FLAG] ?
	ft_memcpy(print_buffer, str, format_spec->size[STR]) :
	ft_memcpy(print_buffer + format_spec->size[BUFFER] - format_spec->size[STR],
	str, format_spec->size[STR]);
	/*write(1, "filled : ", 9);
	write(1, str, format_spec->size[STR]);
	write(1, " ", 1);
	write(1, print_buffer, format_spec->size[BUFFER]);
	write(1, "\n", 1);*/
}

char	base_to_base(long long idx, t_format *format_spec)
{
	if (idx >= 10)
	{
		if (format_spec->type == POINTER || format_spec->type == S_HEXADECIMAL)
			return ('a' + idx - 10);
		else
			return ('A' + idx - 10);
	}
	else
		return ('0' + idx);
}

