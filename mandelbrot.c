/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tas <tas@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 16:47:58 by tas               #+#    #+#             */
/*   Updated: 2022/12/19 18:04:16 by tas              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_fractal   init_mandelbrot(t_fractal f_mandelbrot)
{
    f_mandelbrot.x_min = -2.1;
    f_mandelbrot.x_max = 0.6;
    f_mandelbrot.y_min = -1.2;
    f_mandelbrot.y_max = 1.2;
    f_mandelbrot.zoom = 100;
    f_mandelbrot.iteration_max = 50;
    return (f_m);
}

void calculate_image(t_data img, t_fractal f_m)
{
    double  x;
    double  y;
    double  i;
	double		tmp_r;
   	t_complex	c;
	t_complex	z;
    
    x = 0;
    y = 0;
    f_m = init_mandelbrot(f_m);
    img.x = (f_m.x_max - f_m.x_min) * f_m.zoom;
    img.y = (f_m.y_max - f_m.y_min) * f_m.zoom;
    while (x < img.x)
    {
        while (y < img.y)
        {
            c.r = x / f_m.zoom + f_m.x_min;            
            c.i = y / f_m.zoom + f_m.y_min;
            z.r = 0;            
            z.i = 0;
            i = 0;
            while ((pow(z.r, 2) + pow(z.i, 2)) < 4 && i < f_m.iteration_max)
	        {
	        	tmp_r = z.r;
	        	z.r = (z.r * z.r) - (z.i * z.i) + c.r;
	        	z.i = (2 * z.i * tmp_r) + c.i;
	        	i++;
	        }
            if (i == f_m.iteration_max)
    			put_pixel(&img, x, y, 0x00FFFF00);
            y++;
        }
        x++;
    }
    
}


void	mandelbrot(t_data img, double x, double y)
{
	t_complex	c;
	t_complex	z;
	double		i;
	double		tmp_r;
	int			iteration_max;
	
	c.r = x;
	c.i = y;
	z.r = 0;
	z.i = 0;
	iteration_max = 50;
	while ((pow(z.r, 2) + pow(z.i, 2)) < 4 && i < iteration_max)
	{
		tmp_r = z.r;
		z.r = (z.r * z.r) - (z.i * z.i) + c.r;
		z.i = (2 * z.i * tmp_r) + c.i;
		i++;
	}
}
