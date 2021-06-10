/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpark <gpark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 14:10:01 by gpark             #+#    #+#             */
/*   Updated: 2021/06/10 21:15:53 by gpark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"
#include "myloc.h"

int			min_tile_check(t_map *map, int fd)
{
	int		i;
	int		j;
	int		tiles[5];

	ft_bzero(tiles, sizeof(int) * 5);
	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			tiles[map->map[i][j]]++;
			j++;
		}
		i++;
	}
	if (tiles[PLAYER] != 1 || tiles[COLLECT] <= 0 || tiles[ESCAPE] <= 0)
	{
		errno = MIN_TILE;
		close(fd);
		free_map(map);
		return (-1);
	}
	return (1);
}

int			map_close_check(t_map *map, int fd)
{
	int		i;

	i = 0;
	while (i < map->width)
	{
		if (map->map[0][i] != WALL || map->map[map->height - 1][i] != WALL)
			errno = NOT_CLOSED;
		i++;
	}
	i = 0;
	while (i < map->height)
	{
		if (map->map[i][0] != WALL || map->map[i][map->width - 1] != WALL)
			errno = NOT_CLOSED;
		i++;
	}
	if (errno == NOT_CLOSED)
	{
		close(fd);
		free_map(map);
		return (-1);
	}
	return (1);
}

void		update_map_info(t_map *map)
{
	int		i;
	int		j;

	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			if (map->map[i][j] == PLAYER)
			{
				map->player_i = i;
				map->player_j = j;
				map->map[i][j] = PLAYER;
			}
			if (map->map[i][j] == COLLECT)
				map->collection[TOTAL]++;
			j++;
		}
		i++;
	}
}

void		free_map(t_map *map)
{
	int		i;

	i = 0;
	while (i < map->height)
		my_free((void*)(&map->map[i++]));
	my_free((void*)(&map->map));
	my_free((void*)(&map));
}
