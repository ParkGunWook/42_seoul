/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpark <gpark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 16:24:20 by gpark             #+#    #+#             */
/*   Updated: 2021/06/06 22:31:14 by gpark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "solong.h"

int		main(int argc, char *argv[])
{
	int		map_fd;

	if (argc != 2)
		return (-1);
	map_fd = open(argv[1], O_RDONLY);
	printf("map fd : %d\n", map_fd);
	get_map_info(map_fd, argv[1]);
	return (0);
}
