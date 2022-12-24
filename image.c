/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tas <tas@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 21:45:55 by tas               #+#    #+#             */
/*   Updated: 2022/12/24 12:17:20 by tas              ###   ########.fr       */
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

int	draw_image(t_data img, int x, int y)
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
	return (0);
}


void	cadre(t_data *img, int x, int y) // A SUPPR
{
	while (y <= HEIGHT)
	{
		while (x <= WIDTH)
		{
			if (x == 0 || x == WIDTH - 1 || x == WIDTH / 2 || y == 0 || y == HEIGHT - 1 || y == HEIGHT / 2)
			{
				put_pixel(img, x, y, 0x00FFA500);
			}
			x++;
		}
		x = 0;
		y++;
	}
}

// int	draw_fractal(t_mlx *mlx,t_data *img, t_fractal f)
// {
// 	calculate_julia(img,f);
// 	mlx_put_image_to_window(&mlx->mlx, &mlx->mlx_win, &img->img, 0, 0);

// 	return (0);
// }