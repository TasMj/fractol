/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tas <tas@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 16:47:58 by tas               #+#    #+#             */
/*   Updated: 2022/12/30 23:31:50 by tas              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_fractal	init_mandelbrot(t_mlx *mlx)
{
	mlx->f.x_min = -1.8;
	mlx->f.x_max = 0.6;
	mlx->f.y_min = -1;
	mlx->f.y_max = 1.2;
	mlx->f.zoom = 500;
	mlx->f.color = 0x0077B5FE;
	mlx->f.iteration_max = 50;
	mlx->f.name = "mandelbrot";
	mlx->f.image_x = (mlx->f.x_max - mlx->f.x_min);
	mlx->f.image_y = (mlx->f.y_max - mlx->f.y_min);
	return (mlx->f);
}

void	mandelbrot(t_data *img, double x, double y, t_mlx *mlx)
{
	int			i;
	t_complex	c;
	t_complex	z;
	double		tmp_r;

	i = 0;
	c.r = x / mlx->f.zoom + mlx->f.x_min;
	c.i = y / mlx->f.zoom + mlx->f.y_min;
	z.r = 0;
	z.i = 0;
	while ((pow(z.r, 2) + pow(z.i, 2)) < 4 && i < mlx->f.iteration_max)
	{
		tmp_r = z.r;
		z.r = (z.r * z.r) - (z.i * z.i) + c.r;
		z.i = (2 * z.i * tmp_r) + c.i;
		i++;
	}
	if (!(i == mlx->f.iteration_max))
		put_pixel(img, x, y, mlx->f.color * i);
}
