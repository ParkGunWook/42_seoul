/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpark <gpark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 10:11:51 by gpark             #+#    #+#             */
/*   Updated: 2021/06/08 16:44:50 by gpark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "myloc.h"
#include "solong.h"

void			free_mlx(t_map *map, t_mlx *mlx)
{
	free_map(map);
	my_free((void*)&mlx);
}

static	int		init_mlx_win_ptr(t_map *map, t_mlx *mlx)
{
	printf("%d %d\n", map->height, map->width);
	mlx->win_ptr = mlx_new_window(mlx->mlx_ptr,
		(map->width) * TILE_SIZE, (map->height) * TILE_SIZE, "So_long");
	if (!mlx->win_ptr)
	{
		free_mlx(map, mlx);
		return (-1);
	}
	return (0);
}

static int		init_png_file(t_map *map, t_mlx *mlx)
{
	mlx->img_ptr[ASSET] = mlx_png_file_to_image(mlx->mlx_ptr,
		"./img/Assets.png", &mlx->img_width[ASSET], &mlx->img_height[ASSET]);
	if (!mlx->img_ptr[ASSET])
	{
		free_mlx(map, mlx);
		return (-1);
	}
	mlx->img_ptr[CHAR] = mlx_png_file_to_image(mlx->mlx_ptr,
		"./img/Char.png", &mlx->img_width[CHAR], &mlx->img_height[CHAR]);
	if (!mlx->img_ptr[ASSET])
	{
		free_mlx(map, mlx);
		return (-1);
	}
	return (0);
}

t_mlx			*init_struct_mlx(t_map *map)
{
	t_mlx	*mlx;

	my_aloc((void*)&mlx, sizeof(t_mlx*));
	if (!mlx)
	{
		free_mlx(map, mlx);
		return (0);
	}
	mlx->mlx_ptr = mlx_init();
	if (!mlx->mlx_ptr)
	{
		free_mlx(map, mlx);
		return (0);
	}
	if (init_mlx_win_ptr(map, mlx) == -1)
		return (0);
	if (init_png_file(map, mlx) == -1)
		return (0);
	for (int i = 0;i<map->height;i++)
	{
		for(int j = 0;j<map->width;j++)
		{
			printf("%d %d %d\n", i, j, map->map[i][j]);
			put_image(mlx, map->map[i][j], j, i);
		}
	}
	mlx_loop(mlx->mlx_ptr);
	return (mlx);
}
