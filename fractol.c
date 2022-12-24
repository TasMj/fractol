/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tas <tas@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 17:01:08 by tas               #+#    #+#             */
/*   Updated: 2022/12/24 18:51:20 by tas              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int select_fractal(char **argv)
{
    if (ft_strcmp(argv[1], "Mandelbrot") == 0)
        return (1);
    if (ft_strcmp(argv[1], "Julia") == 0)
        return (2);
    if (ft_strcmp(argv[1], "Burningship") == 0)
        return (3);
	else
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
		printf("x: %f\n", f.x_max);	
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
	else
	{
		// write(1, "Error\n", 6);
		return (1);
	}
	printf("fract: %d\n", select_fractal(argv));
	return (0);	
}