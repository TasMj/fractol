/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tas <tas@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 21:45:55 by tas               #+#    #+#             */
/*   Updated: 2022/12/19 19:40:11 by tas              ###   ########.fr       */
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
			put_pixel(&img, x, y, 0x00FFFF00);
			x++;
		}
		x = 0;
		y++;
	}
}

// void	draw_frac(t_data img)
// {
	// mandelbrot(img.x, img.y);
	// put_pixel(&img, img.x, img.y, 0x00FFFF00);
// }