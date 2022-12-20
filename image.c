/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmejri <tmejri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 21:45:55 by tas               #+#    #+#             */
/*   Updated: 2022/12/20 16:42:41 by tmejri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void    put_pixel(t_data *data, int x, int y, int color)
{
    char	*dst;

	if (x < 0 || x > WIDTH || y < 0 || y > HEIGHT)
		return ;
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	draw_image(t_data img, int x, int y)
{
	while (y < HEIGHT)
	{
		while (x < WIDTH)
		{
			put_pixel(&img, x, y, 0x00d3a2e4);
			x++;
		}
		x = 0;
		y++;
	}
}


// void	draw_image(t_data img, int x, int y)
// {
// 	t_fractal	f_m;

// 	f_m = init_mandelbrot(f_m);
// 	while (y < HEIGHT)
// 	{
// 		while (x < WIDTH)
// 		{
// 			calculate_image(img, f_m);
// 			put_pixel(&img, x, y, 0x00d3a2e4);
// 			x++;
// 		}
// 		x = 0;
// 		y++;
// 	}
// }
