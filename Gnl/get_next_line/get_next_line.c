/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpark <gpark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 17:07:49 by gpark             #+#    #+#             */
/*   Updated: 2021/05/18 12:24:46 by gpark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

static void		clear_save(int ret, t_save **save)
{
	if (ret == 0)
	{
		(*save)->fd = 0;
		(*save)->endl_idx = 0;
		(*save)->size = 0;
		ft_memset((*save)->buff, 0, BUFFER_SIZE + 1);
		free((*save)->buff);
		free((*save));
		*save = 0;
	}
}

static int		save_part(char **line, char *read_buff,
			t_save *save, long long *nums)
{
	if (!(*line = allocate_string(nums[IDX] + nums[ENDL])))
		return (-1);
	ft_memcpy(*line + nums[IDX], read_buff, nums[ENDL]);
	ft_memset(save->buff, 0, BUFFER_SIZE + 1);
	ft_memcpy(save->buff, read_buff + nums[ENDL] + 1,
	BUFFER_SIZE - nums[ENDL] - 1);
	return (1);
}

static int		recursive_get_next_line(int fd, char **line,
				t_save *save, long long idx)
{
	char			read_buff[BUFFER_SIZE + 1];
	long long		nums[3];
	int				flag;

	ft_memset(read_buff, 0, BUFFER_SIZE + 1);
	nums[READ] = read(fd, read_buff, BUFFER_SIZE);
	nums[ENDL] = endl_is_in_string(read_buff, nums[READ]);
	flag = get_flag(nums, idx);
	if (flag == READ_DONE)
	{
		if (!(*line = allocate_string(idx + nums[READ])))
			return (-1);
		ft_memcpy(*line + idx, read_buff, nums[READ]);
	}
	else if (flag == SAVE_PART)
		save_part(line, read_buff, save, nums);
	else if (flag == GET_ALL)
	{
		flag = recursive_get_next_line(fd, line, save, idx + BUFFER_SIZE);
		ft_memcpy((*line) + idx, read_buff, BUFFER_SIZE);
	}
	else
		clear_save(0, &save);
	return (flag);
}

static int		init_s(t_save **save)
{
	long long		idx;

	if (BUFFER_SIZE <= 0)
		return (0);
	idx = 0;
	if (!*save)
	{
		if (!((*save) = (t_save*)malloc(sizeof(t_save))))
			return (0);
		if (!(((*save))->buff = allocate_string(BUFFER_SIZE)))
			return (0);
	}
	(*save)->endl_idx = 0;
	(*save)->size = 0;
	while ((*save)->buff[(*save)->size])
		(*save)->size++;
	while ((*save)->buff[(*save)->endl_idx] != '\n' &&
			(*save)->endl_idx < (*save)->size)
		(*save)->endl_idx++;
	return (1);
}

int				get_next_line(int fd, char **line)
{
	static t_save	*save[OPEN_MAX] = {0, };
	int				ret;
	char			*temp_save;

	if (!(0 <= fd && fd < OPEN_MAX) || !line || !init_s(&save[fd]))
		return (ERROR);
	if (!(temp_save = allocate_string(save[fd]->endl_idx + 1)))
		return (ERROR);
	ft_memcpy(temp_save, save[fd]->buff, save[fd]->endl_idx + 1);
	if (save[fd]->endl_idx < save[fd]->size)
	{
		if (!(*line = allocate_string(save[fd]->endl_idx)))
			return (-1);
		ft_memcpy(*line, temp_save, save[fd]->endl_idx);
		ft_memcpy(save[fd]->buff, save[fd]->buff + save[fd]->endl_idx + 1,
		save[fd]->size - save[fd]->endl_idx);
		free(temp_save);
		return (1);
	}
	ret = recursive_get_next_line(fd, line, save[fd], save[fd]->endl_idx);
	if (ret != -1)
		ft_memcpy(*line, temp_save, save[fd]->endl_idx);
	free(temp_save);
	clear_save(ret, &save[fd]);
	return (ret);
}
