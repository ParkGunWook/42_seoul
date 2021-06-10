/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_event.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpark <gpark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 14:36:47 by gpark             #+#    #+#             */
/*   Updated: 2021/06/10 17:24:38 by gpark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "myloc.h"
#include "solong.h"

static int		can_move(t_map *map)
{
	if (map->player_i < 0 || map->player_i >= map->height ||
		map->player_j < 0 || map->player_j >= map->height)
		return (0);
	if (map->map[map->player_i][map->player_j] == WALL)
		return (0);
	return (1);
}

int				move_up(int keycode, t_params *params)
{
	printf("key code : %d\n", keycode);
	printf("user at : %d %d\n", params->map->player_i, params->map->player_j);
	params->map->player_i = params->map->player_i - 1;
	if (!can_move(params->map))
	{
		params->map->player_i = params->map->player_i + 1;
		return (0);
	}
	params->map->map[params->map->player_i][params->map->player_j] = PLAYER;
	params->map->map[params->map->player_i + 1][params->map->player_j] = EMPTY;
	put_image(params->mlx, EMPTY, params->map->player_i + 1, params->map->player_j);
	return (1);
}

int				move_down(int keycode, t_params *params)
{
	printf("key code : %d\n", keycode);
	printf("user at : %d %d\n", params->map->player_i, params->map->player_j);
	params->map->player_i = params->map->player_i + 1;
	if (!can_move(params->map))
	{
		params->map->player_i = params->map->player_i - 1;
		return (0);
	}
	params->map->map[params->map->player_i][params->map->player_j] = PLAYER;
	params->map->map[params->map->player_i - 1][params->map->player_j] = EMPTY;
	put_image(params->mlx, EMPTY, params->map->player_i - 1, params->map->player_j);
	return (1);
}

int				move_right(int keycode, t_params *params)
{
	printf("key code : %d\n", keycode);
	printf("user at : %d %d\n", params->map->player_i, params->map->player_j);
	params->map->player_j = params->map->player_j - 1;
	if (!can_move(params->map))
	{
		params->map->player_j = params->map->player_j + 1;
		return (0);
	}
	params->map->map[params->map->player_i][params->map->player_j] = PLAYER;
	params->map->map[params->map->player_i][params->map->player_j + 1] = EMPTY;
	put_image(params->mlx, EMPTY, params->map->player_i, params->map->player_j + 1);
	return (1);
}

int				move_left(int keycode, t_params *params)
{
	printf("key code : %d\n", keycode);
	printf("user at : %d %d\n", params->map->player_i, params->map->player_j);
	params->map->player_j = params->map->player_j + 1;
	if (!can_move(params->map))
	{
		params->map->player_j = params->map->player_j - 1;
		return (0);
	}
	params->map->map[params->map->player_i][params->map->player_j] = PLAYER;
	params->map->map[params->map->player_i][params->map->player_j - 1] = EMPTY;
	put_image(params->mlx, EMPTY, params->map->player_i, params->map->player_j - 1);
	return (1);
}

int				close_win(int keycode, t_params *params)
{
	printf("key code : %d", keycode);
	if (keycode == ESC)
	{
		mlx_destroy_window(params->mlx->mlx_ptr, params->mlx->win_ptr);
		free_mlx(params->map, params->mlx);
		exit(0);
	}
	return (0);
}