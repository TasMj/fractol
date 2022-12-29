/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tas <tas@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 17:35:32 by tmejri            #+#    #+#             */
/*   Updated: 2022/12/26 21:54:01 by tas              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_fractal   init_julia(t_mlx *mlx)
{
    mlx->f.x_min = -1.3;
    mlx->f.x_max = 1.3;
    mlx->f.y_min = -1;
    mlx->f.y_max = 1; // voir plus tard pour precision
    mlx->f.zoom = 500;
	mlx->f.c.r = -0.54;
	mlx->f.c.i = 0.54;
	mlx->f.name = "julia";
    mlx->f.iteration_max = 50;
	mlx->f.color = 0x00D8BFD8;
	mlx->f.image_x = (mlx->f.x_max - mlx->f.x_min);
	mlx->f.image_y = (mlx->f.y_max - mlx->f.y_min);
    return (mlx->f);
}

void	julia(t_data *img, double x, double y, t_mlx *mlx)
{
    int			i;
    t_complex	z;
	double		tmp_r;
    
    i = 0;
	z.r = x / mlx->f.zoom + mlx->f.x_min;
	z.i = y / mlx->f.zoom + mlx->f.y_min;
	while ((pow(z.r, 2) + pow(z.i, 2)) < 4 && i < mlx->f.iteration_max) 
	{
		tmp_r = z.r;
		z.r = pow(z.r, 2) - pow(z.i, 2) + mlx->f.c.r;
		z.i = (2 * z.i * tmp_r) + mlx->f.c.i;
		i++;
	}
	if (!(i == mlx->f.iteration_max))
		put_pixel(img, x, y, mlx->f.color * i);
}
// put_pixel(img, x + WIDTH/2 - mlx->f.zoom, y + HEIGHT/2 - mlx->f.zoom, mlx->f.color * i);
// put_pixel(img, x + WIDTH/2 - (f_j.zoom * f_j.x_max), y + HEIGHT/2 - (f_j.zoom * f_j.y_max), 0x00000000);