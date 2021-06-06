/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpark <gpark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 22:01:18 by gpark             #+#    #+#             */
/*   Updated: 2021/06/06 22:38:08 by gpark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"
#include <stdio.h>

int		get_map_size(t_map *map, int fd, char *filename)
{
	char	buffer;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (read(fd, &buffer, 1))
	{
		if (map->width == 0 && buffer == '\n')
			map->width = i;
		i++;
		if (buffer == '\n')
			j++;
	}
	map->height = j;
	printf("%d %d\n", map->width, map->height);
	close(fd);
	fd = open(filename, O_RDONLY);
	return (fd);
}

int		get_map_info(int fd, char *filename)
{
	t_map	*map;
	int		i;
	int		j;
	char	buffer;

	i = 0;
	map = (t_map*)malloc(sizeof(t_map));
	fd = get_map_size(map, fd, filename);
	map->map = (int**)malloc(sizeof(int**) * map->height);
	while (i < map->height)
	{
		map->map[i] = (int*)malloc(sizeof(int*) * map->width);
		i++;
	}
	i = 0;
	while (i < map->height)
	{
		j = 0;
		printf("new line\n");
		while (j <= map->width)
		{
			read(fd, &buffer, 1);
			printf("%c", buffer);
			if (buffer == '0')
				map->map[i][j] = EMPTY;
			else if (buffer == '1')
				map->map[i][j] = WALL;
			else if (buffer == 'C')
				map->map[i][j] = COLLECT;
			else if (buffer == 'E')
				map->map[i][j] = EXIT;
			else if (buffer == 'P')
				map->map[i][j] = PLAYER;
			else if (buffer == '\n')
				break ;
			else
				return (-1);
			j++;
		}
		i++;
	}
	for (int a = 0; a < map->height; a++)
	{
		for (int b = 0; b <map->width; b++)
		{
			printf("%d ", map->map[i][j]);
		}
		printf("\n");
	}
	return (0);
}
