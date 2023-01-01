/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tas <tas@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 17:54:47 by tas               #+#    #+#             */
/*   Updated: 2023/01/01 20:11:52 by tas              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

int	zoom_in(int x, int y, t_mlx *mlx)
{
	reset_screen(mlx);
	mlx->f.x_min = (x / mlx->f.zoom + mlx->f.x_min) - (x / mlx->f.zoom * 1.3);
	mlx->f.x_max = (x / mlx->f.zoom + mlx->f.x_max) - (x / mlx->f.zoom * 1.3);
	mlx->f.y_min = (y / mlx->f.zoom + mlx->f.y_min) - (y / mlx->f.zoom * 1.3);
	mlx->f.y_max = (y / mlx->f.zoom + mlx->f.y_max) - (y / mlx->f.zoom * 1.3);
	mlx->f.zoom /= 1.3;
	return (0);
}

int	zoom_out(int x, int y, t_mlx *mlx)
{
	reset_screen(mlx);
	mlx->f.x_min = (x / mlx->f.zoom + mlx->f.x_min) - (x / mlx->f.zoom / 1.3);
	mlx->f.x_max = (x / mlx->f.zoom + mlx->f.x_max) - (x / mlx->f.zoom / 1.3);
	mlx->f.y_min = (y / mlx->f.zoom + mlx->f.y_min) - (y / mlx->f.zoom / 1.3);
	mlx->f.y_max = (y / mlx->f.zoom + mlx->f.y_max) - (y / mlx->f.zoom / 1.3);
	mlx->f.zoom *= 1.3;
	return (0);
}

int	mouse_hook(int keycode, int x, int y, t_mlx *mlx)
{
	if ((x >= 0 && x <= WIDTH) && (y >= 0 && y <= HEIGHT))
	{
		if (keycode == 4 || keycode == 2)
			zoom_in(x, y, mlx);
		else if ((keycode == 5 || keycode == 1) && mlx->f.zoom > 100)
			zoom_out(x, y, mlx);
	}
	find_fract(mlx);
	return (0);
}
