/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpark <gpark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 15:05:43 by gpark             #+#    #+#             */
/*   Updated: 2021/06/15 20:58:30 by gpark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void		call_child(int *pipes, t_cmds *cmds, char *argv[])
{
	if (redirect_in(pipes, argv[INFILE]) == -1)
	{
		free_cmd(&cmds);
		ft_perror(errno);
		return ;
	}
	if (execve(cmds->exe_path1, cmds->cmd1, NULL) == -1)
	{
		free_cmd(&cmds);
		ft_perror(errno);
		return ;
	}
	dup2(STDOUT_FILENO, pipes[1]);
}

static void		call_father(int *pipes, t_cmds *cmds, char *argv[])
{
	wait(0);
	dup2(pipes[0], STDIN_FILENO);
	if (redirect_out(pipes, argv[OUTFILE]) == -1)
	{
		free_cmd(&cmds);
		ft_perror(errno);
		return ;
	}
	if (execve(cmds->exe_path2, cmds->cmd2, NULL) == -1)
	{
		free_cmd(&cmds);
		ft_perror(errno);
		return ;
	}
	free_cmd(&cmds);
}

static int		init_pipex(int argc, int *pipes)
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
	return (0);
}

int				main(int argc, char *argv[])
{
	pid_t		pid;
	t_cmds		*cmds;
	int			pipes[2];

	if (init_pipex(argc, pipes) == -1)
		return (0);
	cmds = init_cmd(argv);
	if (cmds == NULL)
	{
		ft_perror(errno);
		return (0);
	}
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
		call_father(pipes, cmds, argv);
	return (0);
}
