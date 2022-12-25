/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tas <tas@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 09:56:58 by tas               #+#    #+#             */
/*   Updated: 2022/12/26 00:03:27 by tas              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int close_win(t_mlx *mlx)
{
    mlx_loop_end(mlx->mlx);
    return (0);
}

// int	display_menu(t_mlx *mlx)
// {
// 	t_data	*img_menu;
// 	int		*w;
// 	int		*h;
	
// 	w = 0;
// 	h = 0;
// 	img_menu->name = ft_strdup(MENU);
// 	img_menu->img = mlx_new_image(mlx->mlx, 500, 500);
// 	img_menu->addr = mlx_get_data_addr(img_menu->img, &img_menu->bits_per_pixel, &img_menu->line_length,
// 								&img_menu->endian);
// 	img_menu->img = mlx_xpm_file_to_image(mlx, MENU, w, h);
// 	mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, img_menu, 100, 100);
// 	return (0);
// }

int keypress(int keycode, t_mlx *mlx, t_data *img)
{
    printf("key = %d\n", keycode);
    if (keycode == 65307)
	{
        close_win(mlx);
		return(1);	
	}
    if (keycode == 99)
	{
    	mlx->f.color = mlx->f.color >> 1;
		printf("img key: %p\n", img->img);
		calc_fractal(img, mlx, mandelbrot);
		
		
	}
    else if (keycode == 122)
    	mlx->f.zoom = mlx->f.zoom + 100;
	else if (keycode == 65363 && (img->x >= 0 && img->x <= WIDTH))
		img->x = img->x + 10;
	else if (keycode == 65361 && (img->x >= 0 && img->x <= WIDTH))
		img->x = img->x - 10;
	else if (keycode == 65362 && (img->y >= 0 && img->y <= WIDTH))
		img->y = img->y + 10;
	else if (keycode == 65364 && (img->y >= 0 && img->y <= WIDTH))
		img->y = img->y - 10;
	// else if (keycode == 104)
		// display_menu(mlx);
    return (0);
}
