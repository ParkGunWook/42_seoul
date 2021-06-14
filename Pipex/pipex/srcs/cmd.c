/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpark <gpark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 15:12:18 by gpark             #+#    #+#             */
/*   Updated: 2021/06/14 20:35:17 by gpark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

t_cmds		*init_cmd(char *argv[])
{
	t_cmds		*cmds;
	cmds = (t_cmds*)malloc(sizeof(t_cmds));
	if (cmds == NULL)
		return (NULL);
	cmds->cmd1 = ft_split(argv[CMD1], ' ');
	if (cmds->cmd1 == NULL)
	{
		errno = SPLIT_ERROR;
		ft_perror(errno);
		return (NULL);
	}
	cmds->cmd2 = ft_split(argv[CMD2], ' ');
	if (cmds->cmd2 == NULL)
	{
		errno = SPLIT_ERROR;
		ft_perror(errno);
		return (NULL);
	}
	cmds->main_cmd1 = ft_strjoin("/usr/bin/", cmds->cmd1[0]);
	cmds->main_cmd2 = ft_strjoin("/usr/bin/", cmds->cmd2[0]);
	return (cmds);
}
