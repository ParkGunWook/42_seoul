/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpark <gpark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 16:24:20 by gpark             #+#    #+#             */
/*   Updated: 2021/06/10 21:10:18 by gpark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"
#include "myloc.h"

int		g_mlcnt = 0;

int		basic_error(int argc, char *argv[])
{
	if (argc != 2)
	{
		errno = WRONG_ARGUMENTS;
		ft_perror(errno);
		return (-1);
	}
	if (ft_strncmp(&argv[1][ft_strlen(argv[1]) - 4], EXTENSIONS, 4) != 0)
	{
		errno = WRONG_EXTENSIONS;
		ft_perror(errno);
		return (-1);
	}
	return (0);
}

int		main(int argc, char *argv[])
{
	t_map	*map;
	t_mlx	*mlx;

	if (basic_error(argc, argv) == -1)
		return (0);
	map = get_map(argv[1]);
	if (map == 0)
	{
		ft_perror(errno);
		return (0);
	}
	mlx = init_mlx_struct(map);
	if (!mlx)
		return (0);
	mlx_add_hooks(map, mlx);
	mlx_loop(mlx->mlx_ptr);
	return (0);
}
