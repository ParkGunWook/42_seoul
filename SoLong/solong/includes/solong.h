/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpark <gpark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 21:53:41 by gpark             #+#    #+#             */
/*   Updated: 2021/06/10 14:04:37 by gpark            ###   ########.fr       */
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

enum			e_pngfile
{
	ASSET = 0,
	CHAR
};

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
	WRONG_EXTENSIONS,
	WRONG_ARGUMENTS
};

# define EXTENSIONS ".ber"
# define TILE_SIZE 64
# define BOX_SIZE 48

# define UP 126
# define DOWN 125
# define LEFT 123
# define RIGHT 124
# define ESC 53
# define KeyPress 2
# define KeyRelease 3
# define KeyPressMask (1L<<0)
# define KeyReleaseMask (1L<<1)

typedef struct	s_map
{
	int		**map;
	int		width;
	int		height;
	int		player_i;
	int		player_j;
}				t_map;

typedef struct	s_mlx
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr[2];
	int		img_width[2];
	int		img_height[2];
}				t_mlx;

typedef struct	s_params
{
	struct s_map *map;
	struct s_mlx *mlx;
}				t_params;

t_map			*get_map(char *filename);
int				assign_map(int fd, t_map *map);
int				get_map_size(t_map *map, int fd, char *filename);
int				alloc_map(t_map *map, int fd);
void			free_map(t_map *map);
t_mlx			*init_struct_mlx(t_map *map);
void			free_mlx(t_map *map, t_mlx *mlx);
void			put_image(t_mlx *mlx, int flag, int i, int j);
int				mlx_add_hooks(t_map *map, t_mlx *mlx);
int				move_up(int keycode, t_params *params);
int				move_down(int keycode, t_params *params);
int				move_right(int keycode, t_params *params);
int				move_left(int keycode, t_params *params);
int				key_catcher(int keycode, t_params *params);

#endif
