/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmejri <tmejri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 17:08:21 by tmejri            #+#    #+#             */
/*   Updated: 2022/12/08 14:32:33 by tmejri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void    *put_pixel(t_data *data, int x, int y, int color)
{
    char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
    return (dst);
}

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Fractol");
	img.img = mlx_new_image(mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
	// mlx_put_image_to_window(mlx, mlx_win, img.img, 500, 500);

	mlx_win += 1;
	mlx_win -= 1;
	
	put_pixel(img.img, 0, 0, 0xFF0000);
	// put_pixel(img.img, 1, 0, 0xFF0000);
	// put_pixel(img.img, 2, 0, 0xFF0000);
	// put_pixel(img.img, 3, 0, 0xFF0000);
	// put_pixel(img.img, 4, 0, 0xFF0000);
	// put_pixel(img.img, 5, 0, 0xFF0000);
	// put_pixel(img.img, 6, 0, 0xFF0000);
	// put_pixel(img.img, 7, 0, 0xFF0000);
	// put_pixel(img.img, 8, 0, 0xFF0000);
	mlx_loop(mlx);
}

