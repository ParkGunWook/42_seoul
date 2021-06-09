/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpark <gpark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 14:30:19 by gpark             #+#    #+#             */
/*   Updated: 2021/06/09 17:13:03 by gpark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "myloc.h"
#include "solong.h"

int		mlx_add_hooks(t_map *map, t_mlx *mlx)
{
	t_params	params;
	//int			(*func_ptr[5])(t_params params);
	int			i;

	params.map = map;
	params.mlx = mlx;
	//func_ptr[0] = &move_up;
	//func_ptr[1] = &move_down;
	//func_ptr[2] = &move_right;
	//func_ptr[3] = &move_left;
	//func_ptr[4] = close_win;
	i = 0;
	printf("hook?\n");
	mlx_hook(mlx->win_ptr, 2, 1L << 0, close_win, &params);
	printf("hook done\n");
	return (0);
}