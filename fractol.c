/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tas <tas@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 17:01:08 by tas               #+#    #+#             */
/*   Updated: 2022/12/26 11:15:19 by tas              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <unistd.h>


int select_fractal(char **argv)
{
    if (ft_strcmp(argv[1], "Mandelbrot") == 0
		|| ft_strcmp(argv[1], "mandelbrot") == 0)
        return (1);
    else if (ft_strcmp(argv[1], "Julia") == 0
		|| ft_strcmp(argv[1], "julia") == 0)
        return (2);
    else if (ft_strcmp(argv[1], "Burningship") == 0
		|| ft_strcmp(argv[1], "burningship") == 0)
        return (3);
	else if (ft_strcmp(argv[1], "Julia_2") == 0
		|| ft_strcmp(argv[1], "julia_2") == 0)
        return (4);
	else if (ft_strcmp(argv[1], "Julia_3") == 0
		|| ft_strcmp(argv[1], "julia_3") == 0)
        return (5);
	return (0);
}

 void calc_fractal(t_data *img,  t_mlx *mlx, void(*funct) ())
{
    double x;
    double y;
	
	x = 0;
	while (x < WIDTH)
    {
		y = 0;
        while (y < HEIGHT)
        {
			funct(img, x, y, mlx);
			y++;
		}
        x++;
    }
	mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, img->img, 0, 0);
}

int	init_fract(char **argv, t_mlx *mlx, t_data *img)
{
	if (select_fractal(argv) == 1)
	{
		mlx->f = init_mandelbrot(mlx);
		calc_fractal(img, mlx, mandelbrot);
	}
	else if (select_fractal(argv) == 2)
	{
		mlx->f = init_julia(mlx);
		calc_fractal(img, mlx, julia);
	}
	else if (select_fractal(argv) == 3)
	{
		mlx->f = init_burningship(mlx);
		calc_fractal(img, mlx, burningship);
	}
	else if (select_fractal(argv) == 4)
	{
		mlx->f = init_julia(mlx);
		mlx->f.c.r = -0.4;
		mlx->f.c.i = 0.6;
		calc_fractal(img, mlx, julia);
	}
	else if (select_fractal(argv) == 5)
	{
		mlx->f = init_julia(mlx);
		mlx->f.c.r = -0.835;
		mlx->f.c.i = -0.2321;
		calc_fractal(img, mlx, julia);
	}
	else
		return (1);
	return (0);
}