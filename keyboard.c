/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tas <tas@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 09:56:58 by tas               #+#    #+#             */
/*   Updated: 2022/12/30 15:07:15 by tas              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int key_fractal_name(int keycode, t_mlx *mlx)
{
	char *ptr;
	char *fractal;
	 
	fractal = mlx->f.name;
	ptr = fractal;
	if (keycode == 106)
		fractal = "julia";
	else if (keycode == 109)
		fractal = "mandelbrot";
	else if (keycode == 98)
		fractal = "burningship";
	reset_screen(mlx);
	init_fract(&ptr, mlx, mlx->img);
	return (0);
}

int	key_arrow(int keycode, t_mlx *mlx)
{
	reset_screen(mlx);
	if (keycode == 65363 && (mlx->img->x >= 0 && mlx->img->x <= WIDTH))
		mlx->f.x_min += 0.2;
	else if (keycode == 65361 && (mlx->img->x >= 0 && mlx->img->x <= WIDTH))
		mlx->f.x_min -= 0.2;
	else if (keycode == 65362 && (mlx->img->y >= 0 && mlx->img->y <= HEIGHT))
		mlx->f.y_min -= 0.2;
	else if (keycode == 65364 && (mlx->img->y >= 0 && mlx->img->y <= HEIGHT))
		mlx->f.y_min += 0.2;
	find_fract(mlx);
	return (0);
}

int key_zoom(int keycode, t_mlx *mlx)
{
	if (keycode == 122)
	{
		reset_screen(mlx);
    	mlx->f.zoom += 100;
	}
    else if (keycode == 100 && mlx->f.zoom > 100)
	{
		reset_screen(mlx);
    	mlx->f.zoom -= 100;
	}
	find_fract(mlx);
	return (0);
}

int keypress(int keycode, t_mlx *mlx)
{
	if (keycode == 98 || keycode == 106 || keycode == 109)
		key_fractal_name(keycode, mlx);
	if (keycode >= 65361 && keycode <= 65364)
		key_arrow(keycode, mlx);
	if (keycode == 100 || keycode == 122)
		key_zoom(keycode, mlx);
    if (keycode == 99)
    	mlx->f.color = mlx->f.color >> 1;
    else if (keycode == 65307)
	{
        close_win(mlx);
		return(1);	
	}
	else if (keycode == 104)
	{
		draw_menu(mlx);
		return (0);
	}
	else
		return (1);
	find_fract(mlx);
    return (0);
}
