/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tas <tas@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 17:35:32 by tmejri            #+#    #+#             */
/*   Updated: 2022/12/22 09:55:46 by tas              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_fractal   init_julia(t_fractal f_julia)
{
    f_julia.x_min = -1;
    f_julia.x_max = 1;
    f_julia.y_min = -1.2;
    f_julia.y_max = 1.2;
    f_julia.zoom = 100;
    f_julia.iteration_max = 150;
	f_julia.image_x = (f_julia.x_max - f_julia.x_min);
	f_julia.image_y = (f_julia.y_max - f_julia.y_min);
    return (f_julia);
}


void calculate_julia(t_data *img, t_fractal f_j)
{
    double x = img->x;
    double y = img->y;
	f_j = init_julia(f_j);
	while (x < WIDTH)
    {
        while (y < HEIGHT)
        {
			// julia(img, ((f_j.image_x / WIDTH) + x) / 10, ((f_j.image_y / HEIGHT) + y) / 10);
			// julia(img, (x / WIDTH) * f_j.image_x * 100, (y / HEIGHT) * f_j.image_y * 100);
			julia(img, (f_j.image_x / WIDTH) * x * 100, (f_j.image_y / HEIGHT) * y * 100);
			y++;
		}
		y = 0;
        x++;
    }
}

void	julia(t_data *img, double x, double y)
{
    int i;
    t_complex   c;
    t_complex   z;
	double		tmp_r;
    
    i = 0;
    c.r = 0.285;
    c.i = 0.01;
	z.r = x / 100 - 1;
	z.i = y / 100 - 1.2;
	while ((pow(z.r, 2) + pow(z.r, 2)) < 4 && i < 150)
	{
		tmp_r = z.r;
		z.r = (z.r * z.r) - (z.i * z.i) + c.r;
		z.i = (2 * z.i * tmp_r) + c.i;
		i++;
	}
	if (i == 150)
	{
		put_pixel(img, x, y, 0x0077B5FE);
	}
	img->x = z.r;
	img->y = z.i;
}

// 		z.r = (z.r * z.r) - (z.i * z.i) - 0.8 + (0.6 / x / WIDTH);
//		 z.i = (2 * z.i * tmp_r) + (0.27015 / y / HEIGHT);
