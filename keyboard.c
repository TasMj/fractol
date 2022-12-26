/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tas <tas@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 09:56:58 by tas               #+#    #+#             */
/*   Updated: 2022/12/26 13:53:58 by tas              ###   ########.fr       */
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

int find_fract(t_mlx *mlx)
{
	char	*name;

	name = mlx->f.name;
	if (ft_strcmp(name, "mandelbrot") == 0)
		calc_fractal(mlx->img, mlx, mandelbrot);
	else if (ft_strcmp(name, "julia") == 0)
		calc_fractal(mlx->img, mlx, julia);
	else if (ft_strcmp(name, "burningship") == 0)
		calc_fractal(mlx->img, mlx, burningship);
	return (0);
}

int	reset_screen(t_mlx *mlx)
{
	mlx_destroy_image(mlx->mlx, mlx->img->img);
	mlx->img->img = mlx_new_image(mlx->mlx, WIDTH, HEIGHT);
	mlx->img->addr = mlx_get_data_addr(mlx->img->img, &mlx->img->bits_per_pixel, &mlx->img->line_length,
								&mlx->img->endian);
	return (0);
}

int keypress(int keycode, t_mlx *mlx)
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
		find_fract(mlx);		
	}
    else if (keycode == 122)
	{
		reset_screen(mlx);
    	mlx->f.zoom = mlx->f.zoom + 100;
		find_fract(mlx);		
	}
    else if (keycode == 100 && mlx->f.zoom > 100)
	{
		reset_screen(mlx);
    	mlx->f.zoom = mlx->f.zoom - 100;
		find_fract(mlx);
	}
	else if (keycode == 65363 && (mlx->img->x >= 0 && mlx->img->x <= WIDTH))
	{
		printf("x: %f\n", mlx->img->x);
		reset_screen(mlx);	
		mlx->img->x = mlx->img->x + 10;
		find_fract(mlx);
	}
	else if (keycode == 65361 && (mlx->img->x >= 0 && mlx->img->x <= WIDTH))
	{
		reset_screen(mlx);	
		mlx->img->x = mlx->img->x - 10;
		find_fract(mlx);
	}
	// else if (keycode == 65362 && (img->y >= 0 && img->y <= WIDTH))
	// 	img->y = img->y + 10;
	// else if (keycode == 65364 && (img->y >= 0 && img->y <= WIDTH))
	// 	img->y = img->y - 10;
	// else if (keycode == 104)
		// display_menu(mlx);
    return (0);
}
