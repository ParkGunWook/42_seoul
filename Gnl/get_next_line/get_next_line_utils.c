/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpark <gpark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 17:07:46 by gpark             #+#    #+#             */
/*   Updated: 2021/05/15 20:05:33 by gpark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	idx;

	if (dst == 0 && src == 0)
		return (dst);
	idx = 0;
	while (idx < n)
	{
		*((unsigned char*)(dst + idx)) = *((unsigned char*)(src + idx));
		idx++;
	}
	return (dst);
}

void	*ft_memset(void *b, int c, size_t len)
{
	size_t	idx;

	idx = 0;
	while (idx < len)
	{
		*((unsigned char*)(b + idx)) = (unsigned char)c;
		idx++;
	}
	return (b);
}

size_t		endl_is_in_string(char *buff, size_t num_read)
{
	size_t		idx;

	idx = 0;
	while(idx < num_read)
	{
		if (buff[idx] == '\n')
			return (idx);
		if (!buff[idx])
			return (idx);
		idx++;
	}
	return (idx);
}

size_t		get_flag(size_t num_read, size_t endl_idx)
{
	if (num_read < 0)
	{
		return (ERROR);
	}
	else if (num_read < BUFFER_SIZE)
	{
		return (READ_DONE);
	}
	else if (num_read == BUFFER_SIZE && endl_idx < num_read)
	{
		return (SAVE_PART);
	}
	else if (num_read == BUFFER_SIZE && endl_idx == num_read)
	{
		return (GET_ALL);
	}
	return (ERROR);
}
