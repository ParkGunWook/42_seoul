/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_common_print.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpark <gpark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 19:02:29 by gpark             #+#    #+#             */
/*   Updated: 2021/05/10 20:41:20 by gpark            ###   ########.fr       */
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
		const char *str, size_t buffer_size)
{
	char	to_fill;
	int		dir;
	size_t	idx;

	to_fill = format_spec->flags[ZERO_FLAG] ? '0' : ' ';
	idx = format_spec->flags[MINUS_FLAG] ? 0 : buffer_size - 1;
	dir = format_spec->flags[MINUS_FLAG] ? 1 : -1;
	format_spec->flags[MINUS_FLAG] ?
	ft_strlcpy(print_buffer, str, buffer_size) :
	ft_strlcpy(print_buffer + buffer_size - ft_strlen(str) - 1,
	str, buffer_size);
}
