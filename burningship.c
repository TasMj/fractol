/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burningship.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmejri <tmejri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 13:25:21 by tas               #+#    #+#             */
/*   Updated: 2022/12/31 19:53:58 by tmejri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_fractal	init_burningship(t_mlx *mlx)
{
	mlx->f.x_min = -2.5;
	mlx->f.x_max = 1;
	mlx->f.y_min = -2.5;
	mlx->f.y_max = 2;
	mlx->f.zoom = 300;
	mlx->f.color = 0x00FFC0CB;
	mlx->f.iteration_max = 50;
	mlx->f.name = "burningship";
	mlx->f.image_x = (mlx->f.x_max - mlx->f.x_min);
	mlx->f.image_y = (mlx->f.y_max - mlx->f.y_min);
	return (mlx->f);
}

void	burningship(t_data *img, double x, double y, t_mlx *mlx)
{
	int			i;
	t_complex	c;
	t_complex	z;
	double		tmp_r;

	i = 0;
	z.i = 0;
	z.r = 0;
	c.i = x / mlx->f.zoom + mlx->f.x_min;
	c.r = y / mlx->f.zoom + mlx->f.y_min;
	while ((z.r * z.r + z.i * z.i) < 4 && i < mlx->f.iteration_max)
	{
		tmp_r = z.r;
		z.r = v_abs(((z.r * z.r) - (z.i * z.i)) + c.r);
		z.i = v_abs(2 * z.i * tmp_r + c.i);
		i++;
	}
	if (!(i == mlx->f.iteration_max))
		put_pixel(img, x, y, mlx->f.color * i);
}
