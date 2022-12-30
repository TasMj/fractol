/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tas <tas@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 17:08:21 by tmejri            #+#    #+#             */
/*   Updated: 2022/12/30 23:38:41 by tas              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int argc, char **argv)
{
	t_mlx	mlx;
	t_data	img;

	if (argc != 2 || select_fractal(argv) == -1)
	{
		write(1, "ERROR: incorrect fractal\nAvailable fractals:\n\n", 46);
		write(1, "* Mandelbrot\n* Julia\n* Julia_2\n* Julia_3\n* Burningship", 54);
		return (1);
	}
	init_window(&mlx, &img);
	init_fract(argv, &mlx, &img);
	mlx.img = &img;
	mlx_hook(mlx.mlx_win, 17, 0, close_win, &mlx);
	mlx_key_hook(mlx.mlx_win, keypress, &mlx);
	mlx_mouse_hook(mlx.mlx_win, mouse_hook, &mlx);
	// mlx_hook(mlx.mlx_win, 6, 1L < 6, hook_expose, &mlx);
	mlx_loop(mlx.mlx);
	end_window(&mlx, &img);
}
