/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tas <tas@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 16:34:45 by tmejri            #+#    #+#             */
/*   Updated: 2022/12/25 04:03:56 by tas              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

#include <stdio.h> // A SUPPR
#include <stdlib.h>
#include <math.h>
#include <unistd.h>
#include "./mlx_linux/mlx.h"

# define	WIDTH 1820
# define	HEIGHT 980

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

typedef struct	s_complex
{
	double r;
	double i;
}				t_complex;

typedef	struct s_fractal
{
	char		*name;
	double		x_min;
	double		x_max;
	double		y_min;
	double		y_max;
	double		zoom;
	int			color;
	double		image_x;
	double		image_y;
	double		iteration_max;
	t_complex	c;
}				t_fractal;

typedef	struct	s_mlx
{
	void		*mlx;
	void		*mlx_win;
	t_fractal	f;
}				t_mlx;


void   		put_pixel(t_data *data, int x, int y, int color);

// Window
void		init_window(t_mlx *mlx, t_data *img);
void		end_window(t_mlx *mlx, t_data *img);

// draw
void		cadre(t_data *img, int x, int y);

// Mandelbrot
t_fractal   init_mandelbrot(t_mlx *mlx);
void		mandelbrot(t_data *img, double x, double y, t_mlx *mlx);

// Julia
t_fractal   init_julia(t_mlx *mlx);
void	julia(t_data *img, double x, double y, t_mlx *mlx);


// Burningship
t_fractal   init_burningship(t_mlx *mlx);
void		burningship(t_data *img, double x, double y, t_mlx *mlx);

// Keyboard
int			close_win(t_mlx *mlx);
// int			keypress(int keycode, t_mlx *mlx);
int keypress(int keycode, t_mlx *mlx, t_data *img);
// int zoom(t_fractal f, t_data *img);

// Tools
int	ft_strcmp(const char *s1, const char *s2);

// Fractal
int			select_fractal(char **argv);
void		calc_fractal(t_data *img, t_mlx *mlx, void(*funct) ());
int			init_fract(char **argv, t_mlx *mlx, t_data *img);


#endif	