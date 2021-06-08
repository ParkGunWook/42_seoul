/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpark <gpark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 16:24:20 by gpark             #+#    #+#             */
/*   Updated: 2021/06/08 10:34:12 by gpark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"
#include "myloc.h"

int		g_mlcnt = 0;

int		main(int argc, char *argv[])
{
	t_map	*map;
	t_mlx	*mlx;

	if (argc != 2)
		return (-1);
	if (ft_strncmp(&argv[1][ft_strlen(argv[1]) - 4], EXTENSIONS, 4) != 0)
	{
		errno = WRONG_EXTENSIONS;
		perror(strerror(errno));
		return (0);
	}
	map = get_map(argv[1]);
	if (map == 0)
	{
		perror(strerror(errno));
		//system("leaks so_long");
		printf("g_mlcnt : %d\n", g_mlcnt);
		return (0);
	}
	mlx = init_struct_mlx(map);
	printf("g_mlcnt : %d\n", g_mlcnt);
	return (0);
}
