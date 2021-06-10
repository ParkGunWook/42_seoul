/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_event.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpark <gpark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 14:36:47 by gpark             #+#    #+#             */
/*   Updated: 2021/06/10 21:50:41 by gpark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "myloc.h"
#include "solong.h"

static int		can_move(t_map *map, int prev_i, int prev_j)
{
	if (map->player_i < 0 || map->player_i >= map->height ||
		map->player_j < 0 || map->player_j >= map->width ||
		(map->map[map->player_i][map->player_j] == WALL))
	{
		map->player_i = prev_i;
		map->player_j = prev_j;
		return (0);
	}
	return (1);
}

static void		update_map(t_params *params, int prev_i, int prev_j)
{
	if (params->map->map[params->map->player_i][params->map->player_j]
		== COLLECT)
	{
		params->map->collection[GET]++;
		params->map->map[params->map->player_i][params->map->player_j] = EMPTY;
	}
	put_image(params->mlx, PLAYER,
		params->map->player_j, params->map->player_i);
	put_image(params->mlx, EMPTY, prev_j, prev_i);
	if (params->map->map[params->map->player_i][params->map->player_j]
		== ESCAPE)
		if (params->map->collection[GET] == params->map->collection[TOTAL])
			get_key(ESC, params);
	if (params->map->map[prev_i][prev_j] == ESCAPE)
		put_image(params->mlx, ESCAPE, prev_j, prev_i);
}

int				move_event(t_params *params, int dir)
{
	int		change;
	int		prev_i;
	int		prev_j;

	prev_i = params->map->player_i;
	prev_j = params->map->player_j;
	if (dir == 0 || dir == 2)
		change = 1;
	else
		change = -1;
	if (dir == 0 || dir == 1)
		params->map->player_i = params->map->player_i + change;
	else
		params->map->player_j = params->map->player_j + change;
	if (!can_move(params->map, prev_i, prev_j))
		return (0);
	params->map->player_move++;
	update_map(params, prev_i, prev_j);
	ft_putnbr_fd(params->map->player_move, 1);
	write(1, "\n", 1);
	return (1);
}
