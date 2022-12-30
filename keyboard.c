/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tas <tas@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 09:56:58 by tas               #+#    #+#             */
/*   Updated: 2022/12/30 13:54:35 by tas              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int close_win(t_mlx *mlx)
{
    mlx_loop_end(mlx->mlx);
    return (0);
}

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



int keypress(int keycode, t_mlx *mlx)
{
	key_fractal_name(keycode, mlx);
    if (keycode == 65307)
	{
        close_win(mlx);
		return(1);	
	}
    else if (keycode == 99)
	{
    	mlx->f.color = mlx->f.color >> 1;
	}
    else if (keycode == 122)
	{
		reset_screen(mlx);
    	mlx->f.zoom += 100;
	}
    else if (keycode == 100 && mlx->f.zoom > 100)
	{
		reset_screen(mlx);
    	mlx->f.zoom -= 100;
	}
	else if (keycode == 65363 && (mlx->img->x >= 0 && mlx->img->x <= WIDTH))
	{
		reset_screen(mlx);
		mlx->f.x_min += 0.2;
	}
	else if (keycode == 65361 && (mlx->img->x >= 0 && mlx->img->x <= WIDTH))
	{
		reset_screen(mlx);	
		mlx->f.x_min -= 0.2;
	}
	else if (keycode == 65362 && (mlx->img->y >= 0 && mlx->img->y <= HEIGHT))
	{
		reset_screen(mlx);	
		mlx->f.y_min -= 0.2;
	}
	else if (keycode == 65364 && (mlx->img->y >= 0 && mlx->img->y <= HEIGHT))
	{
		reset_screen(mlx);	
		mlx->f.y_min += 0.2;
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
