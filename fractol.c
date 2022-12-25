/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tas <tas@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 17:01:08 by tas               #+#    #+#             */
/*   Updated: 2022/12/25 02:27:13 by tas              ###   ########.fr       */
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

 void calc_fractal(t_data *img, t_fractal f, void(*funct) ())
{
    double x;
    double y;
	
	x = 0;
	while (x < WIDTH)
    {
		y = 0;
        while (y < HEIGHT)
        {
			funct(img, x, y, f);
			y++;
		}
        x++;
    }
}

int	init_fract(char **argv, t_data *img, t_fractal f)
{
	if (select_fractal(argv) == 1)
	{
		f = init_mandelbrot(f);
		calc_fractal(img, f, mandelbrot);
	}
	else if (select_fractal(argv) == 2)
	{
		f = init_julia(f);
		calc_fractal(img, f, julia);
	}
	else if (select_fractal(argv) == 3)
	{
		f = init_burningship(f);
		calc_fractal(img, f, burningship);
	}
	else if (select_fractal(argv) == 4)
	{
		f = init_julia(f);
		f.c.r = -0.4;
		f.c.i = 0.6;
		calc_fractal(img, f, julia);
	}
	else if (select_fractal(argv) == 5)
	{
		f = init_julia(f);
		f.c.r = -0.835;
		f.c.i = -0.2321;
		calc_fractal(img, f, julia);
	}
	else
		return (1);
	return (0);	
}