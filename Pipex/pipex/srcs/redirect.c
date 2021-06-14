/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpark <gpark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 19:03:48 by gpark             #+#    #+#             */
/*   Updated: 2021/06/14 17:58:04 by gpark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int		redirect_in(int *pipes, char *filename)
{
	int		fd;

	printf("hello redirect in\n");
	fd = open(filename, O_RDONLY);
	printf("open file\n");
	if (fd < 0)
		return (-1);
	if (dup2(fd, STDIN_FILENO) == -1)
		return (-1);
	close(fd);
	return (0);
}

int		redirect_out(int *pipes, char *filename)
{
	int		fd;

	fd = open(filename, O_WRONLY | O_CREAT, 0644);
	if (fd < 0)
		return (-1);
	close(fd);
	dup2(fd, STDIN_FILENO);
	return (0);
}
