/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpark <gpark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 17:07:49 by gpark             #+#    #+#             */
/*   Updated: 2021/05/15 17:38:23 by gpark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

size_t		hello;

int			load_save_buff(int fd, char *save_buff, char **line, size_t *nums);
int			recursive_get_next_line(int fd, char **line, size_t idx);

int			recursive_get_next_line(int fd, char **line, size_t idx)
{
	static char		save_buff[BUFFER_SIZE + 1];
	char			read_buff[BUFFER_SIZE + 1];
	size_t			nums[3];
	int				flag;

	ft_memset(read_buff, 0, BUFFER_SIZE + 1);
	nums[READ] = read(fd, read_buff, BUFFER_SIZE);
	nums[SAVE] = endl_is_in_string(save_buff, BUFFER_SIZE + 1);
	nums[ENDL] = endl_is_in_string(read_buff, nums[READ]);
	/*write(1, "read : ", 7);
	write(1, read_buff, BUFFER_SIZE);
	write(1, "\n", 1);*/
	flag = get_flag(nums[READ], nums[ENDL], nums[SAVE]);
	if (flag == READ_DONE)
	{
		if (!(*line = (char*)malloc(sizeof(char) * (idx + nums[READ]))))
			return (-1);
		hello = idx + nums[READ] + 1;
		ft_memcpy(*line + idx, read_buff, nums[READ]);
		(*line)[idx + nums[READ]] = 0;
		//printf("hello : %zu, %d\n", hello, BUFFER_SIZE);
	}
	else if (flag == SAVE_PART)
	{
		//write(1, "save part\n", 10);
		if (!(*line = (char*)malloc(sizeof(char) * (idx + nums[ENDL]))))
			return (-1);
		hello = idx + nums[ENDL] + 1;
		ft_memcpy(*line + idx, read_buff, nums[ENDL]);
		ft_memset(save_buff, 0, BUFFER_SIZE + 1);
		ft_memcpy(save_buff + nums[ENDL] + 1, read_buff, nums[ENDL] - nums[ENDL] + 1);
	}
	else if (flag == LOAD_SAVE)
	{
		flag = load_save_buff(fd, save_buff, line, nums);
	}
	else if (flag == GET_ALL)
	{
		flag = recursive_get_next_line(fd, line, idx + BUFFER_SIZE);
		//write(1, "ret\n", 4);
		ft_memcpy(*line + idx, read_buff, BUFFER_SIZE);
	}
	return (flag);
}

int			load_save_buff(int fd, char *save_buff, char **line, size_t *nums)
{
	size_t	size_save;
	char	*temp_save;

	size_save = 0;
	while (*(save_buff + size_save))
		size_save++;
	if (nums[SAVE] == size_save)
	{
		if (!(temp_save = (char*)malloc(sizeof(char) * nums[SAVE])))
			return (-1);
		ft_memcpy(temp_save, save_buff, nums[SAVE]);
		ft_memset(temp_save, 0, nums[SAVE]);
		if (nums[READ] != 0)
			recursive_get_next_line(fd, line, nums[SAVE]);
		else
			if (!(*line = (char*)malloc(sizeof(char) * nums[SAVE])))
				return (-1);
		ft_memcpy(line, temp_save, nums[SAVE]);
		free(temp_save);
	}
	else
	{
		if (!(*line = (char*)malloc(sizeof(char) * nums[SAVE])))
			return (-1);
		ft_memcpy(*line, save_buff, nums[SAVE]);
		ft_memcpy(save_buff, save_buff + nums[SAVE], size_save - nums[SAVE]);
		ft_memset(save_buff + nums[SAVE], 0, size_save - nums[SAVE]);
	}
	return (nums[READ] == 0 && size_save == nums[SAVE] ? 0 : 1);
}

int get_next_line(int fd, char **line)
{
	int		ret;

	ret = recursive_get_next_line(fd, line, 0);
	//write(1, "WORKS : ", 7);
	//write(1, *line, hello);
	return (ret);
}
