/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpark <gpark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 17:07:49 by gpark             #+#    #+#             */
/*   Updated: 2021/05/15 21:44:49 by gpark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int			recursive_get_next_line(int fd, char **line, char *save_buff, size_t idx)
{
	char			read_buff[BUFFER_SIZE + 1];
	size_t			nums[3];
	int				flag;

	ft_memset(read_buff, 0, BUFFER_SIZE + 1);
	nums[READ] = read(fd, read_buff, BUFFER_SIZE);
	nums[ENDL] = endl_is_in_string(read_buff, nums[READ]);
	flag = get_flag(nums[READ], nums[ENDL]);
	if (flag == READ_DONE)
	{
		if (!(*line = (char*)malloc(sizeof(char) * (idx + nums[READ]))))
			return (-1);
		ft_memcpy(*line + idx, read_buff, nums[READ]);
		(*line)[idx + nums[READ]] = 0;
		ft_memset(save_buff, 0, BUFFER_SIZE + 1);
		//printf("hello : %d\n", BUFFER_SIZE);
	}
	else if (flag == SAVE_PART)
	{
		if (!(*line = (char*)malloc(sizeof(char) * (idx + nums[ENDL]))))
			return (-1);
		ft_memcpy(*line + idx, read_buff, nums[ENDL]);
		ft_memset(save_buff, 0, BUFFER_SIZE + 1);
		ft_memcpy(save_buff, read_buff + nums[ENDL] + 1, BUFFER_SIZE - nums[ENDL] - 1);
		//printf("save nums[ENDL] : %zu\n", nums[ENDL]);
	}
	else if (flag == GET_ALL)
	{
		flag = recursive_get_next_line(fd, line, save_buff, idx + BUFFER_SIZE);
		//write(1, "ret\n", 4);
		ft_memcpy((*line) + idx, read_buff, BUFFER_SIZE);
		//printf("%p\n", ((*line) + idx));
		//write(1, line + idx, BUFFER_SIZE);
	}
	return (flag);
}

int get_next_line(int fd, char **line)
{
	static char		save_buff[BUFFER_SIZE + 1];
	int		ret;
	char	*temp_save;
	size_t	save_size;
	size_t	endl_idx;

	save_size = 0;
	endl_idx = 0;
	while (save_buff[save_size])
		save_size++;
	while (save_buff[endl_idx] != '\n' && endl_idx < save_size)
		endl_idx++;
	if (endl_idx == save_size)
	{
		//printf("Save loading : %zu %zu\n", endl_idx, endl_idx);
		if (!(temp_save = (char*)malloc(sizeof(char) * endl_idx)))
			return (-1);
		ft_memcpy(temp_save, save_buff, endl_idx);
		//ft_memset(temp_save, 0, endl_idx);
		ret = recursive_get_next_line(fd, line, save_buff, endl_idx);
		ft_memcpy(*line, temp_save, endl_idx);
		free(temp_save);
	}
	else
	{
		//printf("Not func : %zu %zu\n", endl_idx, save_size);
		if (!(*line = (char*)malloc(sizeof(char) * endl_idx)))
			return (-1);
		ft_memcpy(*line, save_buff, endl_idx);
		ft_memcpy(save_buff, save_buff + endl_idx, save_size - endl_idx);
		ft_memset(save_buff + endl_idx + 1, 0, save_size - endl_idx);
		ret = (endl_idx + 1 == save_size) ? 0 : 1;
		if (ret == 0)
			ft_memset(save_buff, 0, BUFFER_SIZE);
	}
	//write(1, "WORKS : ", 7);
	//write(1, *line, hello);
	return (ret);
}
