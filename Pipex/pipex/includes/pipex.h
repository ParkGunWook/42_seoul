/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpark <gpark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 18:47:04 by gpark             #+#    #+#             */
/*   Updated: 2021/06/14 17:35:38 by gpark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <errno.h>
# include <string.h>

enum			e_argv
{
	INFILE = 1,
	CMD1,
	CMD2,
	OUTFILE
};

enum			e_user_error
{
	WRONG_ARGUMENTS = -20,
	SPLIT_ERROR
};

typedef struct	s_cmds
{
	char	**cmd1;
	char	**cmd2;
	char	*main_cmd1;
	char	*main_cmd2;
}				t_cmds;

void			ft_perror(int errcase);
char			**ft_split(char const *s, char c);
int				free_all(char **ret, size_t idx);
char			*ft_strjoin(char const *s1, char const *s2);
size_t			ft_strlcpy(char *dst, const char *src, size_t dstsize);
int				ft_strlen(const char *str);
char			*ft_substr(char const *s, unsigned int start, size_t len);
int				redirect_in(int *pipes, char *filename);
int				redirect_out(int *pipes, char *filename);
t_cmds			*init_cmd(char *argv[]);

#endif