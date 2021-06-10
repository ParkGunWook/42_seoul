/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_image.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpark <gpark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 15:05:38 by gpark             #+#    #+#             */
/*   Updated: 2021/06/10 20:02:56 by gpark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "myloc.h"
#include "solong.h"

void		put_image(t_mlx *mlx, int flag, int i, int j)
{
	mlx_put_image_to_window_scale(
			mlx->mlx_ptr, mlx->win_ptr, mlx->img_ptr[ASSET],
			0, 0, 16, 16,
			i * TILE_SIZE, j * TILE_SIZE, TILE_SIZE, TILE_SIZE, 0xFFFFFFFF);
	if (flag == WALL)
		mlx_put_image_to_window_scale(
			mlx->mlx_ptr, mlx->win_ptr, mlx->img_ptr[ASSET],
			32, 16, 16, 16,
			i * TILE_SIZE, j * TILE_SIZE, TILE_SIZE, TILE_SIZE, 0xFFFFFFFF);
	else if (flag == COLLECT)
		mlx_put_image_to_window_scale(
			mlx->mlx_ptr, mlx->win_ptr, mlx->img_ptr[ASSET],
			240, 48, 16, 16,
			i * TILE_SIZE + 8, j * TILE_SIZE + 8, BOX_SIZE, BOX_SIZE,
			0xFFFFFFFF);
	else if (flag == ESCAPE)
		mlx_put_image_to_window_scale(
			mlx->mlx_ptr, mlx->win_ptr, mlx->img_ptr[ASSET],
			160, 80, 16, 16,
			i * TILE_SIZE, j * TILE_SIZE, TILE_SIZE, TILE_SIZE, 0xFFFFFFFF);
	else if (flag == PLAYER)
		mlx_put_image_to_window_scale(
			mlx->mlx_ptr, mlx->win_ptr, mlx->img_ptr[CHAR],
			49, 5, 48, 48,
			i * TILE_SIZE, j * TILE_SIZE, TILE_SIZE, TILE_SIZE, 0xFFFFFFFF);
}
