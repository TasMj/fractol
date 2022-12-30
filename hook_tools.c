/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tas <tas@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 15:05:15 by tas               #+#    #+#             */
/*   Updated: 2022/12/30 17:45:11 by tas              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	close_win(t_mlx *mlx)
{
	mlx_loop_end(mlx->mlx);
	return (0);
}

int	find_fract(t_mlx *mlx)
{
	char	*name;

	name = mlx->f.name;
	if (ft_strcmp(name, "mandelbrot") == 0)
		calc_fractal(mlx->img, mlx, mandelbrot);
	else if (ft_strcmp(name, "julia") == 0)
		calc_fractal(mlx->img, mlx, julia);
	else if (ft_strcmp(name, "burningship") == 0)
		calc_fractal(mlx->img, mlx, burningship);
	return (0);
}

int	reset_screen(t_mlx *mlx)
{
	mlx_destroy_image(mlx->mlx, mlx->img->img);
	mlx->img->img = mlx_new_image(mlx->mlx, WIDTH, HEIGHT);
	mlx->img->addr = mlx_get_data_addr(mlx->img->img, &mlx->img->bits_per_pixel,
			&mlx->img->line_length, &mlx->img->endian);
	return (0);
}
