/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tas <tas@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 17:08:21 by tmejri            #+#    #+#             */
/*   Updated: 2022/12/24 12:37:27 by tas              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(void)
{
	t_mlx	mlx;
	t_data	img;
	t_fractal	f;

	mlx.mlx = mlx_init();
	mlx.mlx_win = mlx_new_window(mlx.mlx, WIDTH, HEIGHT, "Fractol");
	img.img = mlx_new_image(mlx.mlx, WIDTH, HEIGHT);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
	
	cadre(&img, 0, 0);
	// calculate_mandelbrot(&img, f);
	calculate_julia(&img, f);
	// draw_image(img, 0, 0);
	
	mlx_put_image_to_window(mlx.mlx, mlx.mlx_win, img.img, 0, 0);

	// FAIRE HOOK
	
	mlx_hook(mlx.mlx_win, 2, 1L << 0, keypress, &mlx);
	// mlx_loop_hook(mlx.mlx, &draw_image, &img);
	mlx_loop(mlx.mlx);

	
	//FREE TOUT A LA FIN
	mlx_destroy_image(mlx.mlx, img.img);
	mlx_destroy_window(mlx.mlx, mlx.mlx_win);
	mlx_destroy_display(mlx.mlx);
	free(mlx.mlx);	
}


