/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpark <gpark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 15:05:43 by gpark             #+#    #+#             */
/*   Updated: 2021/06/19 21:41:54 by gpark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void		call_child(int *pipes, t_cmds *cmds, char *argv[])
{
	if (redirect_in(pipes, argv[INFILE]) == -1)
	{
		free_cmd(&cmds);
		ft_perror(errno);
		exit(0);
	}
	if (execve(cmds->exe_path1, cmds->cmd1, NULL) == -1)
	{
		free_cmd(&cmds);
		ft_perror(errno);
		exit(0);
	}
}

static void		call_father(int *pipes, t_cmds *cmds, char *argv[])
{
	wait(0);
	if (dup2(pipes[0], STDIN_FILENO) == -1)
	{
		free_cmd(&cmds);
		ft_perror(errno);
		exit(0);
	}
	if (redirect_out(pipes, argv[OUTFILE]) == -1)
	{
		free_cmd(&cmds);
		ft_perror(errno);
		exit(0);
	}
	if (execve(cmds->exe_path2, cmds->cmd2, NULL) == -1)
	{
		free_cmd(&cmds);
		ft_perror(errno);
		exit(0);
	}
}

static int		init_main(int argc, char *argv[], int *pipes, t_cmds **cmds)
{
	if (argc != 5)
	{
		errno = WRONG_ARGUMENTS;
		ft_perror(errno);
		return (-1);
	}
	if (pipe(pipes) == -1)
	{
		ft_perror(errno);
		return (-1);
	}
	(*cmds) = init_cmd(argv);
	if ((*cmds) == NULL)
	{
		ft_perror(errno);
		return (-1);
	}
	return (0);
}

static void		main2(char *argv[], t_cmds *cmds, int *pipes)
{
	pid_t		pid;

	pid = fork();
	if (pid == -1)
	{
		free_cmd(&cmds);
		ft_perror(errno);
		return ;
	}
	else if (pid == 0)
		call_father(pipes, cmds, argv);
	else
	{
		wait(0);
		free_cmd(&cmds);
	}
	return ;
}

int				main(int argc, char *argv[])
{
	pid_t		pid;
	t_cmds		*cmds;
	int			pipes[2];

	cmds = NULL;
	if (init_main(argc, argv, pipes, &cmds) == -1)
		return (0);
	pid = fork();
	if (pid == -1)
	{
		free_cmd(&cmds);
		ft_perror(errno);
		return (0);
	}
	else if (pid == 0)
		call_child(pipes, cmds, argv);
	else
		main2(argv, cmds, pipes);
	return (0);
}
