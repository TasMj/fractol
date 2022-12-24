/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tas <tas@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 16:34:45 by tmejri            #+#    #+#             */
/*   Updated: 2022/12/24 17:51:42 by tas              ###   ########.fr       */
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

typedef	struct	s_mlx
{
	void	*mlx;
	void	*mlx_win;
}				t_mlx;

typedef	struct s_fractal
{
	double	x_min;
	double	x_max;
	double	y_min;
	double	y_max;
	double	zoom;
	double	iteration_max;
	double	image_x;
	double	image_y;
	int		color;
}				t_fractal;


typedef struct	s_complex
{
	double r;
	double i;
}				t_complex;


void   		put_pixel(t_data *data, int x, int y, int color);
void		init_window(void);
// void    init_window(t_mlx mlx, t_data img);

// draw
void		cadre(t_data *img, int x, int y);
t_mlx		init_image(t_data img, t_mlx mlx);
int			draw_image(t_data img, int x, int y);
// int			draw_fractal(t_data img, t_fractal f);


// Mandelbrot
void		mandelbrot(t_data *img, double x, double y, t_fractal f_m);
t_fractal   init_mandelbrot(t_fractal f_mandelbrot);
void		calculate_mandelbrot(t_data *img, t_fractal f_m);

// Julia
t_fractal   init_julia(t_fractal f_julia);
void		julia(t_data *img, double x, double y, t_fractal f_j);
void		calculate_julia(t_data *img, t_fractal f_j);

// Burningship
t_fractal   init_burningship(t_fractal f_burningship);
void		calculate_burningship(t_data *img, t_fractal f_b);
void		burningship(t_data *img, double x, double y, t_fractal f_b);

// Keyboard
int			close_win(t_mlx *mlx);
int			keypress(int keycode, t_mlx *mlx);
// int keypress(int keycode, t_mlx *mlx, t_fractal f, t_data *img);
// int zoom(t_fractal f, t_data *img);

// Tools
int	ft_strcmp(const char *s1, const char *s2);

// Fractal
int			select_fractal(char **argv);
void		calc_fractal(t_data *img, t_fractal f, void(*funct) ());
int			init_fract(char **argv, t_data *img, t_fractal f);

#endif	