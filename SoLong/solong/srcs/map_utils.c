/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpark <gpark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 14:10:01 by gpark             #+#    #+#             */
/*   Updated: 2021/06/08 11:27:49 by gpark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"
#include "myloc.h"
#include <stdio.h>

static int	check_map_tile(char buffer)
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

int			assign_map(int fd, t_map *map)
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

int			get_map_size(t_map *map, int fd, char *filename)
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

int			alloc_map(t_map *map, int fd)
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

void		free_map(t_map *map)
{
	int		i;

	i = 0;
	while (i < map->height)
		my_free((void*)(&map->map[i++]));
	my_free((void*)(&map->map));
	my_free((void*)(&map));
}
