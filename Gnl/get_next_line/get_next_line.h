/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpark <gpark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 17:07:51 by gpark             #+#    #+#             */
/*   Updated: 2021/05/18 11:21:55 by gpark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define ERROR -1
# define READ_DONE 0
# define SAVE_PART 1
# define GET_ALL 2

# define READ 0
# define ENDL 1
# define IDX 2

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

typedef struct	s_save
{
	int			fd;
	char		*buff;
	long long	endl_idx;
	long long	size;
}				t_save;

int				get_next_line(int fd, char **line);
char			*allocate_string(long long size);
void			*ft_memcpy(void *dst, const void *src, long long n);
void			*ft_memset(void *b, int c, long long len);
long long		endl_is_in_string(char *buff, long long num_read);
int				get_flag(long long *nums, long long idx);

#endif
