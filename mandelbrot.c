/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmejri <tmejri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 16:47:58 by tas               #+#    #+#             */
/*   Updated: 2022/12/20 19:08:38 by tmejri           ###   ########.fr       */
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
	f_mandelbrot.image_x = (f_mandelbrot.x_max - f_mandelbrot.x_min);
	f_mandelbrot.image_y = (f_mandelbrot.y_max - f_mandelbrot.y_min);
	
	
    return (f_mandelbrot);
}

void calculate_image(t_data *img, t_fractal f_m)
{
    double x = 0;
    double y = 0;

	f_m = init_mandelbrot(f_m);

	while (x < WIDTH)
    {
		
        while (y < HEIGHT)
        {         

			// fprintf(stderr, "x= %f - y = %f", x, y);

			// fprintf(stderr, "newx= %f - newy = %f\n", (x + WIDTH/2 - 5) / 100, (y + HEIGHT/2 + 5) / 100);
			// if (mandelbrot(((x + WIDTH/2) / WIDTH/2 ), (y + HEIGHT/2 ) /(HEIGHT/2)) == 50)
			if (mandelbrot(((x + WIDTH/2) / WIDTH/2 ), (y + HEIGHT/2 ) /(HEIGHT/2)) == 50)
			{
    			put_pixel(img, x, y, 0x00FF7F7F);
			}
			put_pixel(img, x, y, 0x00d3a2e4);
            y++;
        }
		y = 0;
        x++;
    }
}


int	mandelbrot(double x, double y)
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
	
    i = 0;
	iteration_max = 50;
	while ((pow(z.r, 2) + pow(z.i, 2)) < 4 && i < iteration_max)
	{
		tmp_r = z.r;
		z.r = (z.r * z.r) - (z.i * z.i) + c.r;
		z.i = (2 * z.i * tmp_r) + c.i;
		i++;
	}

	return i;

	
	
}
