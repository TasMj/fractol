/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tas <tas@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 17:08:21 by tmejri            #+#    #+#             */
/*   Updated: 2022/12/25 02:32:01 by tas              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int argc, char **argv)
{
	t_mlx	mlx;
	t_data	img;
	t_fractal	f;

	init_window(&mlx, &img);
	if (argc != 2 || init_fract(argv, &img, f) == 1)
	{
		write(1, "ERROR: incorrect fractal\nAvailable fractals:\n\n", 46);
		write(1,"* Mandelbrot\n* Julia\n* Julia_2\n* Julia_3\n* Burningship", 54);
		return (1);
	}	
	init_fract(argv, &img, f);
	
	mlx_put_image_to_window(mlx.mlx, mlx.mlx_win, img.img, 0, 0);

	// FAIRE HOOK
	
	mlx_hook(mlx.mlx_win, 2, 1L << 0, keypress, &mlx);
	// mlx_loop_hook(mlx.mlx, &draw_image, &img);
	mlx_loop(mlx.mlx);

	end_window(&mlx, &img);
}


