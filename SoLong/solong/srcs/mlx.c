/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpark <gpark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 10:11:51 by gpark             #+#    #+#             */
/*   Updated: 2021/06/08 11:28:33 by gpark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "myloc.h"
#include "solong.h"

void	free_mlx(t_mlx *mlx)
{
	my_free((void*)&mlx);
}

t_mlx	*init_struct_mlx(t_map *map)
{
	t_mlx	*mlx;

	printf("hello mlx\n");
	my_aloc((void*)&mlx, sizeof(t_mlx*));
	if (!mlx)
	{
		free_map(map);
		free_mlx(mlx);
		return (0);
	}
	mlx->mlx_ptr = mlx_init();
	mlx->win_ptr =
	mlx_new_window(mlx->mlx_ptr, (map->width + 1) * TILE_SIZE, (map->height + 1) * TILE_SIZE, "So_long");
	mlx->img_ptr[EMPTY] =
	mlx_png_file_to_image(mlx->mlx_ptr, "./img/Empty.png",
	&mlx->img_width[EMPTY], &mlx->img_height[EMPTY]);
	mlx->img_ptr[WALL] =
	mlx_png_file_to_image(mlx->mlx_ptr, "./img/WALL.png",
	&mlx->img_width[WALL], &mlx->img_height[WALL]);
	printf("EMPTY DONE\n");
	printf("%d %d\n", map->height, map->width);
	for(int i = 0; i < map->height; i++)
	{
		for(int j = 0; j < map->width; j++)
		{
			printf("i : %d j : %d\n", i, j);
			mlx_put_image_to_window_scale(
				mlx->mlx_ptr, mlx->win_ptr, mlx->img_ptr[EMPTY],
				0, 0, mlx->img_width[EMPTY], mlx->img_height[EMPTY],
				i * TILE_SIZE, j * TILE_SIZE, TILE_SIZE, TILE_SIZE, 0xFFFFFFFF);
			if (map->map[i][j] == WALL)
				mlx_put_image_to_window_scale(
					mlx->mlx_ptr, mlx->win_ptr, mlx->img_ptr[WALL],
					0, 0, mlx->img_width[WALL], mlx->img_height[WALL],
					i * TILE_SIZE, j * TILE_SIZE, TILE_SIZE, TILE_SIZE, 0xFFFFFFFF);
			else if (map->map[i][j] == EMPTY)
			{
				;
			}
		}
	}
	mlx_loop(mlx->mlx_ptr);
	return (mlx);
}

