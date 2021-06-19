/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpark <gpark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 19:03:48 by gpark             #+#    #+#             */
/*   Updated: 2021/06/19 21:37:19 by gpark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int		redirect_in(int *pipes, char *filename)
{
	int		fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (-1);
	if (dup2(fd, STDIN_FILENO) == -1)
		return (-1);
	if (dup2(pipes[1], STDOUT_FILENO) == -1)
		return (-1);
	close(pipes[0]);
	close(pipes[1]);
	close(fd);
	return (0);
}

int		redirect_out(int *pipes, char *filename)
{
	int		fd;

	fd = open(filename, O_WRONLY | O_CREAT, 0644);
	if (fd == -1)
		return (-1);
	if (dup2(fd, STDOUT_FILENO) == -1)
		return (-1);
	if (dup2(pipes[0], STDIN_FILENO) == -1)
		return (-1);
	close(pipes[0]);
	close(pipes[1]);
	close(fd);
	return (0);
}
