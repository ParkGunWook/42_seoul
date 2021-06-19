/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpark <gpark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 15:12:18 by gpark             #+#    #+#             */
/*   Updated: 2021/06/19 18:06:41 by gpark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char		*get_path2(char *exe)
{
	char	*path;

	path = ft_strjoin("/usr/sbin/", exe);
	if (access(path, X_OK) == 0)
		return (path);
	else
		free(path);
	path = ft_strjoin("/sbin/", exe);
	if (access(path, X_OK) == 0)
		return (path);
	else
		free(path);
	return (NULL);
}

static char		*get_path(char *exe)
{
	char	*path;

	path = ft_strjoin("/usr/local/bin/", exe);
	if (access(path, X_OK) == 0)
		return (path);
	else
		free(path);
	path = ft_strjoin("/usr/bin/", exe);
	if (access(path, X_OK) == 0)
		return (path);
	else
		free(path);
	path = ft_strjoin("/bin/", exe);
	if (access(path, X_OK) == 0)
		return (path);
	else
		free(path);
	path = get_path2(exe);
	return (path);
}

static int		init_cmd2(char *argv[], t_cmds *cmds)
{
	cmds->cmd2 = ft_split(argv[CMD2], ' ');
	if (cmds->cmd2 == NULL)
	{
		free(cmds);
		free_split(cmds->cmd1);
		free(cmds->exe_path1);
		errno = SPLIT_ERROR;
		ft_perror(errno);
		return (-1);
	}
	int i;
	i = 0;
	while (cmds->cmd2[i])
	{
		printf("%s\n", cmds->cmd2[i]);
		i++;
	}
	cmds->exe_path2 = get_path(cmds->cmd2[0]);
	if (cmds->exe_path1 == NULL)
	{
		free(cmds);
		free_split(cmds->cmd1);
		free(cmds->exe_path1);
		free_split(cmds->cmd2);
		errno = NOT_VALID_EXE;
		ft_perror(NOT_VALID_EXE);
		return (-1);
	}
	return (0);
}

t_cmds			*init_cmd(char *argv[])
{
	t_cmds		*cmds;

	cmds = (t_cmds*)malloc(sizeof(t_cmds));
	if (cmds == NULL)
		return (NULL);
	printf("Split sat\n");
	cmds->cmd1 = ft_split(argv[CMD1], ' ');
	printf("Split done\n");
	int i;
	i = 0;
	while(cmds->cmd1[i])
	{
		printf("%d : %s\n", i, cmds->cmd1[i]);
		i++;
	}
	if (cmds->cmd1 == NULL)
	{
		free(cmds);
		errno = SPLIT_ERROR;
		ft_perror(errno);
		return (NULL);
	}
	cmds->exe_path1 = get_path(cmds->cmd1[0]);
	if (cmds->exe_path1 == NULL)
	{
		free(cmds);
		free_split(cmds->cmd1);
		errno = NOT_VALID_EXE;
		ft_perror(NOT_VALID_EXE);
		return (NULL);
	}
	if (init_cmd2(argv, cmds) == -1)
		return (NULL);
	return (cmds);
}

void			free_cmd(t_cmds **cmds)
{
	free_split((*cmds)->cmd1);
	free((*cmds)->exe_path1);
	free_split((*cmds)->cmd2);
	free((*cmds)->exe_path2);
	free(*cmds);
	*cmds = 0;
}
