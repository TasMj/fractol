/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmejri <tmejri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 16:47:58 by tas               #+#    #+#             */
/*   Updated: 2022/12/21 12:00:08 by tmejri           ###   ########.fr       */
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

void calculate_mandelbrot(t_data *img, t_fractal f_m)
{
    double x = 0;
    double y = 0;

	f_m = init_mandelbrot(f_m);
	while (x < WIDTH)
    {
        while (y < HEIGHT)
        {         
			mandelbrot(img, ((f_m.image_x / (WIDTH / 2)) + x) / 10, ((f_m.image_y / (HEIGHT/2)) + y) / 10);
            y++;
        }
		y = 0;
        x++;
    }
}

// if (mandelbrot(((x + WIDTH/2) / WIDTH/2 ), (y + HEIGHT/2 ) /(HEIGHT/2)) == 50)
// fprintf(stderr, "x= %f - y = %f", x, y);
// fprintf(stderr, "newx= %f - newy = %f\n", ((WIDTH / f_m.image_x) + x) / 100, ((HEIGHT / f_m.image_y) + y) / 100);

void	mandelbrot(t_data *img, double x, double y)
{
	int		i;
	t_complex	c;
	t_complex	z;
	double		tmp_r;
	
    i = 0;
	c.r = x;
	c.i = y;
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
	{
		put_pixel(img, x, y, 0x0077B5FE);
		printf("A\n");
	}
}
