/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpark <gpark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 22:01:18 by gpark             #+#    #+#             */
/*   Updated: 2021/06/10 21:12:14 by gpark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"
#include "myloc.h"

static int		check_map_tile(char buffer)
{
	if (buffer == '0')
		return (EMPTY);
	else if (buffer == '1')
		return (WALL);
	else if (buffer == 'C')
		return (COLLECT);
	else if (buffer == 'E')
		return (ESCAPE);
	else if (buffer == 'P')
		return (PLAYER);
	else
		return (-1);
}

static int		assign_map(int fd, t_map *map)
{
	int		i;
	int		j;
	char	buffer;

	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			read(fd, &buffer, 1);
			map->map[i][j] = check_map_tile(buffer);
			if (map->map[i][j] == -1)
			{
				close(fd);
				errno = INVALID_TILE;
				free_map(map);
				return (-1);
			}
			j++;
		}
		read(fd, &buffer, 1);
		i++;
	}
	return (1);
}

static int		get_map_size(t_map *map, int fd, char *filename)
{
	char	buffer;
	int		i;

	i = 0;
	while (read(fd, &buffer, 1))
	{
		if (buffer == '\n')
		{
			if (map->width == 0)
				map->width = i;
			if (map->width != i)
			{
				close(fd);
				my_free((void*)(&map));
				errno = NOT_RECT;
				return (-1);
			}
			i = -1;
			map->height++;
		}
		i++;
	}
	close(fd);
	fd = open(filename, O_RDWR);
	return (fd);
}

static int		alloc_map(t_map *map, int fd)
{
	int		i;

	if (my_aloc((void*)(&map->map), sizeof(int*) * map->height) == 0)
	{
		my_free((void*)(&map));
		return (-1);
	}
	i = 0;
	while (i < map->height)
	{
		if (my_aloc((void*)(&map->map[i]), sizeof(int) * map->width) == 0)
		{
			close(fd);
			while (--i)
				my_free((void*)(&map->map[i]));
			my_free((void*)(&map->map));
			my_free((void*)(&map));
			return (-1);
		}
		i++;
	}
	return (1);
}

t_map			*get_map(char *filename)
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
	update_map_info(map);
	close(fd);
	return (map);
}
