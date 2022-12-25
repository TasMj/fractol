/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burningship.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tas <tas@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 13:25:21 by tas               #+#    #+#             */
/*   Updated: 2022/12/25 01:54:17 by tas              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_fractal   init_burningship(t_fractal f_burningship)
{
    f_burningship.x_min = -2.5;
    f_burningship.x_max = 1;
    f_burningship.y_min = -2.5;
    f_burningship.y_max = 2;
    f_burningship.zoom = 300;
	f_burningship.color = 0x00FFC0CB;
    f_burningship.iteration_max = 50;
	f_burningship.image_x = (f_burningship.x_max - f_burningship.x_min);
	f_burningship.image_y = (f_burningship.y_max - f_burningship.y_min);
    return (f_burningship);
}

// fprintf(stderr, "x= %f - y = %f", x, y);

void	burningship(t_data *img, double x, double y, t_fractal f_b)
{
	int		    i;
    t_complex   c;
    t_complex   z;
	double	tmp_r;
    
	i = 0;
	z.i = 0;
	z.r = 0;
	c.i = x / f_b.zoom + f_b.x_min;
	c.r = y / f_b.zoom + f_b.y_min;
	while ((pow(z.r, 2) + pow(z.i, 2)) < 4 && i < f_b.iteration_max)
	{
		tmp_r = z.r;
		z.r = fabs(pow(z.r, 2) - pow(z.i, 2) + c.r);
		z.i = fabs(2 * z.i * tmp_r + c.i);
		i++;
	}
	if (i == f_b.iteration_max)
		put_pixel(img, x, y, 0x000000);
	else				
		put_pixel(img, x, y, f_b.color * i);
}