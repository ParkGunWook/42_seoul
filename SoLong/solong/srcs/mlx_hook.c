/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpark <gpark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 14:30:19 by gpark             #+#    #+#             */
/*   Updated: 2021/06/10 17:25:44 by gpark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "myloc.h"
#include "solong.h"

int		get_key(int keycode, t_params *params)
{
	if (keycode == ESC)
	{
		mlx_destroy_window(params->mlx->mlx_ptr, params->mlx->win_ptr);
		mlx_destroy_image(params->mlx->mlx_ptr, params->mlx->img_ptr[CHAR]);
		mlx_destroy_image(params->mlx->mlx_ptr, params->mlx->img_ptr[ASSET]);
		free_mlx(params->map, params->mlx);
		exit(0);
	}
	else if (keycode == UP)
	{
		move_up(keycode, params);
		printf("user at : %d %d\n", params->map->player_i, params->map->player_j);
	}
	else if (keycode == DOWN)
	{
		move_down(keycode, params);
		printf("user at : %d %d\n", params->map->player_i, params->map->player_j);
	}
	else if (keycode == LEFT)
	{
		move_left(keycode, params);
	}
	else if (keycode == RIGHT)
	{
		move_right(keycode, params);
	}
	return (1);
}

int		render_window(t_map *map, t_mlx *mlx)
{
	int		i;
	int		j;

	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			put_image(mlx->mlx_ptr, map->map[i][j], j, i);
			j++;
		}
		i++;
	}
	return (0);
}

int		mlx_add_hooks(t_map *map, t_mlx *mlx)
{
	t_params	*params;
	//int			(*func_ptr[5])(t_params params);
	int			i;

	my_aloc((void*)&params, sizeof(t_params));
	params->map = map;
	params->mlx = mlx;
	//func_ptr[0] = &move_up;
	//func_ptr[1] = &move_down;
	//func_ptr[2] = &move_right;
	//func_ptr[3] = &move_left;
	//func_ptr[4] = close_win;
	i = 0;
	printf("hook?\n");
	for (i = 0;i<map->height;i++)
	{
		for(int j = 0;j<map->width;j++)
		{
			printf("%d %d %d\n", i, j, map->map[i][j]);
			put_image(mlx, map->map[i][j], j, i);
			printf("done %d %d %d\n", i, j, map->map[i][j]);
		}
	}
	mlx_hook(mlx->win_ptr, 2, 1L << 0, get_key, params);
	printf("hook done\n");
	return (0);
}