/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpark <gpark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 21:53:41 by gpark             #+#    #+#             */
/*   Updated: 2021/06/08 11:28:20 by gpark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLONG_H
# define SOLONG_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <string.h>
# include <errno.h>
# include <stdio.h>

# include "libft.h"
# include "mlx.h"


enum			e_tile
{
	EMPTY = 0,
	WALL,
	COLLECT,
	ESCAPE,
	PLAYER
};

enum			e_user_error
{
	NOT_RECT = -20,
	INVALID_TILE,
	NOT_CLOSED,
	MIN_TILE,
	WRONG_EXTENSIONS
};

# define EXTENSIONS ".ber"
# define TILE_SIZE 100

typedef struct	s_map
{
	int		**map;
	int		width;
	int		height;
}				t_map;

typedef struct	s_mlx
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr[5];
	int		img_width[5];
	int		img_height[5];
}				t_mlx;

t_map			*get_map(char *filename);
int				assign_map(int fd, t_map *map);
int				get_map_size(t_map *map, int fd, char *filename);
int				alloc_map(t_map *map, int fd);
void			free_map(t_map *map);
t_mlx			*init_struct_mlx(t_map *map);

#endif