/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpark <gpark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 21:53:41 by gpark             #+#    #+#             */
/*   Updated: 2021/06/06 22:28:02 by gpark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLONG_H
# define SOLONG_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <string.h>

# include "mlx.h"

# define EMPTY 0
# define WALL 1
# define COLLECT 2
# define EXIT 3
# define PLAYER 4

typedef struct	s_map
{
	int		**map;
	int		width;
	int		height;
}				t_map;

int				get_map_info(int fd, char *filename);

#endif
