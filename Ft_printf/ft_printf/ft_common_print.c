/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_common_print.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpark <gpark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 19:02:29 by gpark             #+#    #+#             */
/*   Updated: 2021/05/13 21:09:57 by gpark            ###   ########.fr       */
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

size_t	zero_counter(const char *str)
{
	size_t idx;

	idx = 0;
	while (*(str + idx) == '0' && *(str + idx))
		idx++;
	return (idx);
}
