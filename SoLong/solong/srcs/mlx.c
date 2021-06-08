/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpark <gpark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 10:11:51 by gpark             #+#    #+#             */
/*   Updated: 2021/06/08 15:56:20 by gpark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "myloc.h"
#include "solong.h"

void	free_mlx(t_map *map, t_mlx *mlx)
{
	free_map(map);
	my_free((void*)&mlx);
}

t_mlx	*init_struct_mlx(t_map *map)
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
	mlx->win_ptr = mlx_new_window(mlx->mlx_ptr,
		(map->height) * TILE_SIZE, (map->width) * TILE_SIZE, "So_long");
	if (!mlx->win_ptr)
	{
		free_mlx(map, mlx);
		return (0);
	}
	if (init_png_file(map, mlx) == -1)
	{
		free_mlx(map, mlx);
		return (0);
	}
	for (int i = 0 ;i<map->height; i++)
	{
		for (int j = 0 ; j<map->width; j++)
		{
			printf("%d %d %d\n", i, j, map->map[i][j]);
			put_image(mlx, map->map[i][j], i, j);
		}
	}
	mlx_loop(mlx->mlx_ptr);
	return (mlx);
}

