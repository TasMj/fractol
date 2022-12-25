// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   mouse.c                                            :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: tas <tas@student.42.fr>                    +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2022/12/22 10:55:20 by tas               #+#    #+#             */
// /*   Updated: 2022/12/22 20:38:18 by tas              ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

#include "fractol.h"

int mouse_hook(int keycode, t_mlx *mlx, t_data *img)
{
	(void)img;
    printf("key = %d\n", keycode);
	if (keycode == 4)
		mlx->f.zoom = mlx->f.zoom * 1.5;
	else if (keycode == 5)
		mlx->f.zoom = mlx->f.zoom / 1.5;
	// if ((souris > 0 && souris < WIDTH) && (souris > 0 && souris < HEIGHT))
	// {
		// zoomer sur la position();
	// }
	// if (souris == la croix)
		// close_win(mlx)
	calc_fractal(img, mlx, mandelbrot);
	return (0);
}