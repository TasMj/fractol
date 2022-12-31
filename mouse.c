/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmejri <tmejri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 17:54:47 by tas               #+#    #+#             */
/*   Updated: 2022/12/31 19:41:29 by tmejri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

int	mouse_hook(int keycode, int x, int y, t_mlx *mlx)
{
	if ((x >= 0 && x <= WIDTH) && (y >= 0 && y <= HEIGHT))
	{
		(void)x;
		(void)y;
		if (keycode == 4 || keycode == 1)
		{
			// printf("\nx win: %d\n", x);
			// printf("y win: %d\n\n", y);
			// printf("xmin: %f\n", mlx->f.x_min);
			printf("xmax: %f\n", mlx->f.x_max);
			// printf("ymin: %f\n", mlx->f.y_min);
			printf("ymax: %f\n", mlx->f.y_max);
// 
			// reset_screen(mlx);
			// mlx->f.x_min = (x / mlx->f.zoom + mlx->f.x_min) - (x / mlx->f.zoom / 1.3);
			// mlx->f.x_max = (x / mlx->f.zoom + mlx->f.x_max) - (x / mlx->f.zoom / 1.3);
			// mlx->f.y_min = (y / mlx->f.zoom + mlx->f.y_min) - (y / mlx->f.zoom / 1.3);
			// mlx->f.y_max = (y / mlx->f.zoom + mlx->f.y_max) - (y / mlx->f.zoom / 1.3);
			reset_screen(mlx);
			mlx->f.zoom /= 1.3;
		}
		else if ((keycode == 5) && mlx->f.zoom > 100)
		{
			reset_screen(mlx);
			mlx->f.zoom *= 1.3;
		}
	}	
	find_fract(mlx);
	return (0);
}
