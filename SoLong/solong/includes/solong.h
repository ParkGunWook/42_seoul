/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpark <gpark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 21:53:41 by gpark             #+#    #+#             */
/*   Updated: 2021/06/10 21:13:38 by gpark            ###   ########.fr       */
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

# define EXTENSIONS ".ber"
# define TILE_SIZE 64
# define BOX_SIZE 48

# define UP 13
# define DOWN 1
# define LEFT 0
# define RIGHT 2
# define ESC 53

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

enum			e_collection
{
	GET = 0,
	TOTAL
};

typedef struct	s_map
{
	int		**map;
	int		width;
	int		height;
	int		player_i;
	int		player_j;
	int		collection[2];
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

void			ft_perror(int errcase);
t_map			*get_map(char *filename);
int				min_tile_check(t_map *map, int fd);
int				map_close_check(t_map *map, int fd);
void			update_map_info(t_map *map);
void			free_map(t_map *map);
t_mlx			*init_mlx_struct(t_map *map);
void			free_mlx(t_map *map, t_mlx *mlx);
void			put_image(t_mlx *mlx, int flag, int i, int j);
int				mlx_add_hooks(t_map *map, t_mlx *mlx);
int				move_event(t_params *params, int dir);
int				get_key(int keycode, t_params *params);

#endif
