/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tas <tas@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 16:47:58 by tas               #+#    #+#             */
/*   Updated: 2022/12/23 22:53:27 by tas              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_fractal   init_mandelbrot(t_fractal f_mandelbrot)
{
    f_mandelbrot.x_min = -1.8;
    f_mandelbrot.x_max = 0.6;
    f_mandelbrot.y_min = -1;
    f_mandelbrot.y_max = 1.2;
    f_mandelbrot.zoom = 400;
    f_mandelbrot.iteration_max = 50;
	f_mandelbrot.image_x = (f_mandelbrot.x_max - f_mandelbrot.x_min);
	f_mandelbrot.image_y = (f_mandelbrot.y_max - f_mandelbrot.y_min);
    return (f_mandelbrot);
}

void calculate_mandelbrot(t_data *img, t_fractal f_m)
{
    double x;
    double y;
	
	x = 0;
	f_m = init_mandelbrot(f_m);
	while (x < WIDTH)
    {
		y = 0;
        while (y < HEIGHT)
        {         
			mandelbrot(img, x, y, f_m);
            y++;
        }
        x++;
    }
}

// fprintf(stderr, "x= %f - y = %f", x, y);

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
	while ((pow(z.r, 2) + pow(z.i, 2)) < 4 && i < 50)
	{
		tmp_r = z.r;
		z.r = (z.r * z.r) - (z.i * z.i) + c.r;
		z.i = (2 * z.i * tmp_r) + c.i;
		i++;
	}
	if (i == 50)
		// put_pixel(img, x + WIDTH/2 - (f_m.zoom * f_m.x_max), y + HEIGHT/2 - (f_m.zoom * f_m.y_max), 0x0077B5FE);
		put_pixel(img, x + WIDTH/2 - f_m.zoom, y + HEIGHT/2 - f_m.zoom, 0x0077B5FE);
}
