/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmejri <tmejri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 17:35:32 by tmejri            #+#    #+#             */
/*   Updated: 2022/12/22 18:31:42 by tmejri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_fractal   init_julia(t_fractal f_julia)
{
    f_julia.x_min = -1;
    f_julia.x_max = 1;
    f_julia.y_min = -1.2;
    f_julia.y_max = 1.2;
    f_julia.zoom = 200;
    f_julia.iteration_max = 150;
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
    c.r = 0.285;
    c.i = 0.01;
	z.r = x / f_j.zoom + f_j.x_min;
	z.i = y / f_j.zoom + f_j.y_min;
	while ((pow(z.r, 2) + pow(z.r, 2)) < 4 && i < 150) 
	{
		tmp_r = z.r;
		z.r = (z.r * z.r) - (z.i * z.i) + c.r;
		z.i = (2 * z.i * tmp_r) + c.i;
		i++;
	}
	if (i == 150)
		// put_pixel(img, x + (WIDTH/2) + (f_j.zoom * f_j.x_min) , y + (HEIGHT/2) + (f_j.zoom * f_j.y_min), 0x0077B5FE);
		put_pixel(img, (x - 40 *f_j.x_max) + (WIDTH/2), (y - 20*f_j.y_max) + (HEIGHT/2), 0x0077B5FE);
}

// 		z.r = (z.r * z.r) - (z.i * z.i) - 0.8 + (0.6 / x / WIDTH);
//		 z.i = (2 * z.i * tmp_r) + (0.27015 / y / HEIGHT);
