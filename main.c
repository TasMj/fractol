/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tas <tas@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 17:08:21 by tmejri            #+#    #+#             */
/*   Updated: 2022/12/29 10:21:05 by tas              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int argc, char **argv)
{
	t_mlx	mlx;
	t_data	img;

	init_window(&mlx, &img);
	if (argc != 2 || init_fract(argv, &mlx, &img) == 1)
	{
		write(1, "ERROR: incorrect fractal\nAvailable fractals:\n\n", 46);
		write(1,"* Mandelbrot\n* Julia\n* Julia_2\n* Julia_3\n* Burningship", 54);
		return (1);
	}	
	init_fract(argv, &mlx, &img);
	mlx.img = &img;
	mlx_hook(mlx.mlx_win, 17, 0, close_win, &mlx);
	mlx_key_hook(mlx.mlx_win, keypress, &mlx);
	mlx_mouse_hook(mlx.mlx_win, mouse_hook, &img);
	mlx_loop(mlx.mlx);
	end_window(&mlx, &img);
}
