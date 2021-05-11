/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_common_print.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpark <gpark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 19:02:29 by gpark             #+#    #+#             */
/*   Updated: 2021/05/11 15:54:56 by gpark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libprint.h"

void	ft_putstr_size_fd(char *str, int fd, size_t size)
{
	size_t	idx;

	idx = 0;
	while (idx < size)
	{
		ft_putchar_fd(*(str + idx), fd);
		idx++;
	}
}

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
	write(1, str, format_spec->size[BUFFER]);
	write(1, print_buffer, format_spec->size[BUFFER]);
	write(1, "\n", 1);*/
}
