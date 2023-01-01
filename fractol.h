/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tas <tas@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 16:34:45 by tmejri            #+#    #+#             */
/*   Updated: 2023/01/01 20:17:12 by tas              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include	<stdlib.h>
# include	<unistd.h>
# include	"./mlx_linux/mlx.h"

# define WIDTH 1820
# define HEIGHT 980
# define MENU "image_menu/menu.xpm"

typedef struct s_menu
{
	char	*path;
	void	*img;
	int		h;
	int		w;
	int		flag;
}				t_menu;

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	double	x;
	double	y;
}				t_data;

typedef struct s_complex
{
	double	r;
	double	i;
}				t_complex;

typedef struct s_fractal
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

typedef struct s_mlx
{
	void		*mlx;
	void		*mlx_win;
	t_data		*img;
	t_fractal	f;
	t_menu		menu;
}				t_mlx;

// WINDOW
void		init_window(t_mlx *mlx, t_data *img);
void		end_window(t_mlx *mlx, t_data *img);

// FRACTAL
int			select_fractal(char **argv);
void		calc_fractal(t_data *img, t_mlx *mlx, void (*funct) ());
int			annex_init(char **argv, t_mlx *mlx, t_data *img);
int			init_fract(char **argv, t_mlx *mlx, t_data *img);

// MANDELBROT
t_fractal	init_mandelbrot(t_mlx *mlx);
void		mandelbrot(t_data *img, double x, double y, t_mlx *mlx);

// JULIA
t_fractal	init_julia(t_mlx *mlx);
void		julia(t_data *img, double x, double y, t_mlx *mlx);

// BURNINGSHIP
t_fractal	init_burningship(t_mlx *mlx);
void		burningship(t_data *img, double x, double y, t_mlx *mlx);

// KEYBOARD
int			key_fractal_name(int keycode, t_mlx *mlx);
int			key_arrow(int keycode, t_mlx *mlx);
int			key_zoom(int keycode, t_mlx *mlx);
int			keypress(int keycode, t_mlx *mlx);

// HOOK TOOLS
int			close_win(t_mlx *mlx);
int			find_fract(t_mlx *mlx);
int			reset_screen(t_mlx *mlx);

// MOUSE
int			zoom_in(int x, int y, t_mlx *mlx);
int			zoom_out(int x, int y, t_mlx *mlx);
int			mouse_hook(int keycode, int x, int y, t_mlx *mlx);

// TOOLS
void		put_pixel(t_data *data, int x, int y, int color);
int			ft_strcmp(const char *s1, const char *s2);
double		v_abs(double n);

// MENU
int			display_menu(t_mlx *mlx);
void		draw_menu(t_mlx *mlx);

#endif	