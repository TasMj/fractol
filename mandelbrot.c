/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tas <tas@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 16:47:58 by tas               #+#    #+#             */
/*   Updated: 2022/12/25 02:00:50 by tas              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_fractal   init_mandelbrot(t_fractal f_mandelbrot)
{
    f_mandelbrot.x_min = -1.8;
    f_mandelbrot.x_max = 0.6;
    f_mandelbrot.y_min = -1;
    f_mandelbrot.y_max = 1.2;
    f_mandelbrot.zoom = 500;
	f_mandelbrot.color = 0x0077B5FE;
    f_mandelbrot.iteration_max = 50;
	f_mandelbrot.image_x = (f_mandelbrot.x_max - f_mandelbrot.x_min);
	f_mandelbrot.image_y = (f_mandelbrot.y_max - f_mandelbrot.y_min);
    return (f_mandelbrot);
}

void	mandelbrot(t_data *img, double x, double y, t_fractal f_m)
{
	int		i;
	t_complex	c;
	t_complex	z;
	double		tmp_r;
	
    i = 0;
	c.r = x / f_m.zoom + f_m.x_min;
	c.i = y / f_m.zoom + f_m.y_min;
	z.r = 0;
	z.i = 0;
	while ((pow(z.r, 2) + pow(z.i, 2)) < 4 && i < f_m.iteration_max)
	{
		tmp_r = z.r;
		z.r = (z.r * z.r) - (z.i * z.i) + c.r;
		z.i = (2 * z.i * tmp_r) + c.i;
		i++;
	}
	if (i == f_m.iteration_max)
		put_pixel(img, x, y, 0x000000);
	else				
		put_pixel(img, x, y, f_m.color * i);
}

// put_pixel(img, x + WIDTH/2 - f_m.zoom, y + HEIGHT/2 - f_m.zoom, f_m.color * i);