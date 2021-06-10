/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpark <gpark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 14:30:19 by gpark             #+#    #+#             */
/*   Updated: 2021/06/10 21:18:05 by gpark            ###   ########.fr       */
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
			put_image(mlx, map->map[i][j], j, i);
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
	render_window(map, mlx);
	mlx_hook(mlx->win_ptr, 2, 1L << 0, get_key, params);
	return (0);
}
