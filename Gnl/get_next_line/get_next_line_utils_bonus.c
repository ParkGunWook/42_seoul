/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpark <gpark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 17:07:46 by gpark             #+#    #+#             */
/*   Updated: 2021/05/18 11:20:48 by gpark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char		*allocate_string(long long size)
{
	char *new;

	if (!(new = (char*)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	ft_memset(new, 0, size + 1);
	return (new);
}

void		*ft_memcpy(void *dst, const void *src, long long n)
{
	long long	idx;

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

void		*ft_memset(void *b, int c, long long len)
{
	long long	idx;

	idx = 0;
	while (idx < len)
	{
		*((unsigned char*)(b + idx)) = (unsigned char)c;
		idx++;
	}
	return (b);
}

long long	endl_is_in_string(char *buff, long long num_read)
{
	long long		idx;

	idx = 0;
	while (idx < num_read)
	{
		if (buff[idx] == '\n')
			return (idx);
		if (!buff[idx])
			return (idx);
		idx++;
	}
	return (idx);
}

int			get_flag(long long *nums, long long idx)
{
	if (nums[READ] < 0)
	{
		return (ERROR);
	}
	else if (nums[READ] == 0 ||
			(nums[READ] < BUFFER_SIZE && nums[READ] == nums[ENDL]))
	{
		return (READ_DONE);
	}
	else if (nums[READ] <= BUFFER_SIZE && nums[ENDL] < nums[READ])
	{
		nums[IDX] = idx;
		return (SAVE_PART);
	}
	else if (nums[READ] == BUFFER_SIZE && nums[ENDL] == nums[READ])
	{
		return (GET_ALL);
	}
	return (ERROR);
}
