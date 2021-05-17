/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpark <gpark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 17:07:49 by gpark             #+#    #+#             */
/*   Updated: 2021/05/17 17:57:04 by gpark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

static	void	ft_putnbr2_fd(int nb, int fd)
{
	int	remainder;

	remainder = nb % 10;
	nb /= 10;
	if (nb == 0)
	{
		ft_putchar_fd('0' + remainder, fd);
		return ;
	}
	ft_putnbr2_fd(nb, fd);
	ft_putchar_fd('0' + remainder, fd);
}

void			ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
		write(fd, "-2147483648", 11);
	else if (n >= 0)
		ft_putnbr2_fd(n, fd);
	else if (n < 0)
	{
		ft_putchar_fd('-', fd);
		ft_putnbr2_fd(-n, fd);
	}
}

int			recursive_get_next_line(int fd, char **line, char *save_buff, size_t idx)
{
	char			read_buff[BUFFER_SIZE + 1];
	size_t			nums[3];
	int				flag;

	ft_memset(read_buff, 0, BUFFER_SIZE + 1);
	nums[READ] = read(fd, read_buff, BUFFER_SIZE);
	nums[ENDL] = endl_is_in_string(read_buff, nums[READ]);
	flag = get_flag(nums[READ], nums[ENDL]);
	/*write(1, "READ ENDL : ", 12);
	ft_putnbr_fd(nums[READ], 1);
	write(1, " ", 1);
	ft_putnbr_fd(nums[ENDL], 1);
	write(1, "\n", 1);*/
	if (flag == READ_DONE)
	{
		if (!(*line = (char*)malloc(sizeof(char) * (idx + nums[READ] + 1))))
			return (-1);
		/*ft_putnbr_fd(idx + nums[READ], 1);
		write(1, "x\n", 2);*/
		ft_memcpy(*line + idx, read_buff, nums[READ]);
		(*line)[idx + nums[READ]] = 0;
		ft_memset(save_buff, 0, BUFFER_SIZE + 1);
		//printf("hello : %d\n", BUFFER_SIZE);
	}
	else if (flag == SAVE_PART)
	{
		if (!(*line = (char*)malloc(sizeof(char) * (idx + nums[ENDL] + 1))))
			return (-1);
		/*ft_putnbr_fd(idx + nums[ENDL], 1);
		write(1, "X\n", 2);*/
		ft_memcpy(*line + idx, read_buff, nums[ENDL]);
		(*line)[idx + nums[ENDL]] = 0;
		ft_memset(save_buff, 0, BUFFER_SIZE + 1);
		ft_memcpy(save_buff, read_buff + nums[ENDL] + 1, BUFFER_SIZE - nums[ENDL] - 1);
		/*write(1, "SAVE : ", 7);
		write(1, save_buff, BUFFER_SIZE - nums[ENDL] - 1);
		write(1, "\\\n", 2);*/
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
	//printf("Save loading : %zu %zu\n", endl_idx, save_size);
	if (!(temp_save = (char*)malloc(sizeof(char) * endl_idx + 2)))
		return (-1);
	ft_memcpy(temp_save, save_buff, endl_idx + 1);
	temp_save[endl_idx + 1] = 0;
	if (endl_idx < save_size)
	{
		(*line) = (char*)malloc(sizeof(char) * (endl_idx + 1));
		ft_memcpy(*line, temp_save, endl_idx);
		ft_memcpy(save_buff, save_buff + endl_idx + 1, save_size - endl_idx);
		(*line)[endl_idx] = 0;
		free(temp_save);
		return (1);
	}
	//ft_memset(temp_save, 0, endl_idx);
	ret = recursive_get_next_line(fd, line, save_buff, endl_idx);
	ft_memcpy(*line, temp_save, endl_idx);
	free(temp_save);
	//write(1, "WORKS : ", 7);
	//write(1, *line, hello);
	return (ret);
}
