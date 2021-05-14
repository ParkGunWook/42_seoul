/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpark <gpark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 17:07:46 by gpark             #+#    #+#             */
/*   Updated: 2021/05/14 22:43:10 by gpark            ###   ########.fr       */
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

size_t		endl_is_in_string(char *read_buff, size_t num_read)
{
	size_t		idx;

	idx = 0;
	while(idx < num_read)
	{
		if (read_buff[idx] == '\n')
			return (idx);
		idx++;
	}
	return (idx);
}

size_t		get_flag(size_t num_read, size_t endl_idx)
{
	if (num_read < BUFFER_SIZE && endl_idx == num_read)
	{
		return (READ_DONE);
	}
	else if (num_read < BUFFER_SIZE && endl_idx < num_read)
	{
		if (num_read != 0)
			return (SAVE_PART);
		else
			return (LOAD_SAVE);
	}
	else if (num_read == BUFFER_SIZE && endl_idx == num_read)
	{
		return (GET_ALL);
	}
	else if (num_read == BUFFER_SIZE && endl_idx < num_read)
	{
		return (SAVE_PART);
	}
	else
		return (ERROR);
}

size_t		recursive_get_next_line(int fd, char *new_line, size_t idx)
{
	static	char	save_buff[BUFFER_SIZE + 1];
	char			read_buff[BUFFER_SIZE + 1];
	size_t			num_read;
	size_t			endl_idx;
	size_t			flag;

	ft_memset(read_buff, 0, BUFFER_SIZE + 1);
	num_read = read(fd, read_buff, BUFFER_SIZE);
	endl_idx = is_in_endl(read_buff);
	flag = get_flag(num_read, endl_idx);
	if (flag == READ_DONE)
		return (READ_DONE);
	else if (flag == SAVE_PART)
	{
		new_line = (char*)malloc(sizeof(char) * (idx + num_read - endl_idx));
		ft_memset(save_buff, 0, BUFFER_SIZE + 1);
		ft_memcpy(save_buff, read_buff + endl_idx + 1, num_read - endl_idx);
	}
	else if (flag == READ_LINE)
	{

	}
	else if (flag == GET_ALL)
	{
		recursive_get_next_line(fd, new_line, idx + BUFFER_SIZE);
		flag = ft_memcpy(read_buff, new_line + idx, BUFFER_SIZE);
	}
	return (flag);
}
