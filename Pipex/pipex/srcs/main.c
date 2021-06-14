/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpark <gpark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 15:05:43 by gpark             #+#    #+#             */
/*   Updated: 2021/06/14 20:44:44 by gpark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void		call_child(int *pipes, t_cmds *cmds, char *argv[], char *envp[])
{
	if (redirect_in(pipes, argv[INFILE]) == -1)
	{
		ft_perror(errno);
		return ;
	}
	if (execve(cmds->main_cmd1, cmds->cmd1, envp) == -1)
	{
		ft_perror(errno);
		return ;
	}
	dup2(STDOUT_FILENO, pipes[1]);
}

static void		call_father(int *pipes, t_cmds *cmds, char *argv[], char *envp[])
{
	wait(0);
	dup2(pipes[0], STDIN_FILENO);
	if (redirect_out(pipes, argv[OUTFILE]) == -1)
	{
		ft_perror(errno);
		return ;
	}
	if (execve(cmds->main_cmd2, cmds->cmd2, envp) == -1)
	{
		ft_perror(errno);
		return ;
	}
}

int				main(int argc, char *argv[], char *envp[])
{
	pid_t		pid;
	t_cmds		*cmds;
	int			pipes[2];

	if (argc != 5)
	{
		errno = WRONG_ARGUMENTS;
		ft_perror(errno);
		return (0);
	}
	if (pipe(pipes) == -1)
	{
		ft_perror(errno);
		return (0);
	}
	cmds = init_cmd(argv);
	if (cmds == NULL)
	{
		ft_perror(errno);
		return (0);
	}
	pid = fork();
	if (pid == -1)
	{
		ft_perror(errno);
		return (0);
	}
	else if (pid == 0)
		call_child(pipes, cmds, argv, envp);
	else
		call_father(pipes, cmds, argv, envp);
	return (0);
}
