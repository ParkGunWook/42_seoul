/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpark <gpark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 14:30:19 by gpark             #+#    #+#             */
/*   Updated: 2021/06/12 14:55:42 by gpark            ###   ########.fr       */
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
		my_free((void*)&params);
		exit(0);
	}
	if (keycode == DOWN)
		move_event(params, 0);
	else if (keycode == RIGHT)
		move_event(params, 2);
	else if (keycode == UP)
		move_event(params, 1);
	else if (keycode == LEFT)
		move_event(params, 3);
	return (1);
}

int		red_cross(t_params *params)
{
	mlx_destroy_window(params->mlx->mlx_ptr, params->mlx->win_ptr);
	mlx_destroy_image(params->mlx->mlx_ptr, params->mlx->img_ptr[CHAR]);
	mlx_destroy_image(params->mlx->mlx_ptr, params->mlx->img_ptr[ASSET]);
	free_mlx(params->map, params->mlx);
	my_free((void*)&params);
	exit(0);
}

int		render_window(t_params *params)
{
	int		i;
	int		j;

	i = 0;
	while (i < params->map->height)
	{
		j = 0;
		while (j < params->map->width)
		{
			put_image(params->mlx, params->map->map[i][j], j, i);
			j++;
		}
		i++;
	}
	return (0);
}

int		mlx_add_hooks(t_map *map, t_mlx *mlx)
{
	t_params	*params;
	int			i;

	my_aloc((void*)&params, sizeof(t_params));
	params->map = map;
	params->mlx = mlx;
	i = 0;
	mlx_loop_hook(mlx->mlx_ptr, render_window, params);
	mlx_hook(mlx->win_ptr, 2, 1L << 0, get_key, params);
	mlx_hook(mlx->win_ptr, 17, 1L << 0, red_cross, params);
	return (0);
}
