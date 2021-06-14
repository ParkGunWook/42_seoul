/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execve.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpark <gpark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 17:26:37 by gpark             #+#    #+#             */
/*   Updated: 2021/06/14 21:38:06 by gpark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>

int main(int ac, char *av[], char *ev[])
{
	char	**argv;
	char	**argv2;
	char	**envp;
	int 	pipes[2];
	pid_t	pid;
	int 	fd;
	int		fd2;

	envp = malloc(sizeof(char*) * 3);
	envp[0] = "PATH=/usr/bin/";
	envp[1] = "PATH=/bin/";
	envp[2] = 0;
	argv = malloc(sizeof(char*) * 3);
	pipe(pipes);
	if (ac != 1)
	{
		if (av != NULL)
			return (0);
	}
	argv[0] = "grep";
	argv[1] = "a1";
	argv[2] = NULL;
	argv2 = malloc(sizeof(char*) * 3);
	argv2[0] = "wc";
	argv2[1] = "-l";
	argv2[2] = NULL;

	char *ptr = *ev;
	int i = 0;
	while (ptr != NULL)
	{
		printf("%s\n", ptr);
		ptr = *(ev + i++);
	}
	pid = fork();
	if (pid > 0)
	{
		wait(0);
		fd2 = open("b.txt", O_WRONLY | O_CREAT, 0644);
		dup2(fd2, STDOUT_FILENO);
		dup2(pipes[0], STDIN_FILENO);
		close(pipes[0]);
		close(pipes[1]);
		execve("wc", argv2, ev);
		perror("execve failed");
		return (1);
	}
	else if (pid == 0)
	{
		fd = open("a.txt", O_RDONLY);
		dup2(fd, STDIN_FILENO);
		dup2(pipes[1], STDOUT_FILENO);
		close(pipes[0]);
		close(pipes[1]);
		execve("$PATHgrep", argv, ev);
		perror("execve failed");
		return (1);
	}
	return (0);
}
