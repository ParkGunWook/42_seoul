/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpark <gpark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 22:01:18 by gpark             #+#    #+#             */
/*   Updated: 2021/06/10 17:21:50 by gpark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"
#include "myloc.h"
#include <stdio.h>

static	int	min_tile_check(t_map *map, int fd)
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

static	int	map_close_check(t_map *map, int fd)
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

t_map		*get_map(char *filename)
{
	t_map	*map;
	int		i;
	int		fd;

	fd = open(filename, O_RDWR);
	if (fd == -1)
		return (0);
	i = 0;
	map = NULL;
	if (!my_aloc((void*)(&map), sizeof(t_map)))
		return (0);
	map->width = 0;
	map->height = 1;
	fd = get_map_size(map, fd, filename);
	if (fd == -1)
		return (0);
	if (alloc_map(map, fd) == -1)
		return (0);
	if (assign_map(fd, map) == -1)
		return (0);
	if (map_close_check(map, fd) == -1 || min_tile_check(map, fd) == -1)
		return (0);
	close(fd);
	return (map);
}
