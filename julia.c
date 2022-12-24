/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tas <tas@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 17:35:32 by tmejri            #+#    #+#             */
/*   Updated: 2022/12/24 13:06:09 by tas              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_fractal   init_julia(t_fractal f_julia)
{
    f_julia.x_min = -1.3;
    f_julia.x_max = 1.3;
    f_julia.y_min = -1;
    f_julia.y_max = 1; // voir plus tard pour precision
    f_julia.zoom = 500;
	f_julia.color = 0x00D8BFD8;
    f_julia.iteration_max = 50;
	f_julia.image_x = (f_julia.x_max - f_julia.x_min);
	f_julia.image_y = (f_julia.y_max - f_julia.y_min);
    return (f_julia);
}

 void calculate_julia(t_data *img, t_fractal f_j)
{
    double x;
    double y;
	
	x = 0;
	f_j = init_julia(f_j);
	while (x < WIDTH)
    {
		y = 0;
        while (y < HEIGHT)
        {
			julia(img, x, y, f_j);
			y++;
		}
        x++;
    }
}

void	julia(t_data *img, double x, double y, t_fractal f_j)
{
    int i;
    t_complex   c;
    t_complex   z;
	double		tmp_r;
    
    i = 0;
    c.r = -0.54;
    c.i = 0.54;
	z.r = x / f_j.zoom + f_j.x_min;
	z.i = y / f_j.zoom + f_j.y_min;
	while ((pow(z.r, 2) + pow(z.i, 2)) < 4 && i < f_j.iteration_max) 
	{
		tmp_r = z.r;
		z.r = pow(z.r, 2) - pow(z.i, 2) + c.r;
		z.i = (2 * z.i * tmp_r) + c.i;
		i++;
	}
	if (i == f_j.iteration_max)
		put_pixel(img, x, y, 0x00000000);
	else
		put_pixel(img, x, y, f_j.color * i);
}


		// put_pixel(img, x + WIDTH/2 - (f_j.zoom * f_j.x_max), y + HEIGHT/2 - (f_j.zoom * f_j.y_max), 0x00000000);