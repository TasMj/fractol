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

int mouse_hook(int keycode, t_mlx *mlx)
{
	printf("key mouse = %d\n", keycode);
	printf("--> mlx: %p\n", mlx->img->addr);

	if (keycode == 4 && keycode == 2)
	{
		printf("zoom: %f\n", mlx->f.zoom);
		reset_screen(mlx);
    	mlx->f.zoom += 100;
	}
    else if ((keycode == 5 || keycode == 4) && mlx->f.zoom > 100)
	{
		printf("zoom: %f\n", mlx->f.zoom);
		reset_screen(mlx);
    	mlx->f.zoom -= 100;
	}
	// if ((souris > 0 && souris < WIDTH) && (souris > 0 && souris < HEIGHT))
	// {
		// zoomer sur la position();
	// }
	find_fract(mlx);
	return (0);
}