/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tas <tas@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 16:34:45 by tmejri            #+#    #+#             */
/*   Updated: 2022/12/19 19:42:11 by tas              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

#include <stdio.h> // A SUPPR
#include <stdlib.h>
#include <math.h>
#include "./mlx_linux/mlx.h"

# define	WIDTH 1920
# define	HEIGHT 1080

typedef struct	s_data 
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	double	x;
	double	y;
}				t_data;

typedef	struct	s_mlx
{
	void	*mlx;
	void	*mlx_win;
}				t_mlx;

typedef	struct	s_rgbt
{
	int	r;
	int	g;
	int	b;
	int	t;
}				t_rgbt;

typedef	struct s_fractal
{
	double	x_min;
	double	x_max;
	double	y_min;
	double	y_max;
	double	zoom;
	double	iteration_max;
}				t_fractal;


typedef struct	s_complex
{
	double r;
	double i;
}				t_complex;

#endif

void    	put_pixel(t_data *data, int x, int y, int color);
void		init_window(void);
t_mlx		init_image(t_data img, t_mlx mlx);
void		draw_image(t_data img, int x, int y);
void		mandelbrot(double x, double y);
t_fractal   init_mandelbrot(t_fractal f_mandelbrot);
void		calculate_image(t_data img, t_fractal f_m);
void	draw_frac(t_data img);





