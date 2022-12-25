/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tas <tas@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 09:56:58 by tas               #+#    #+#             */
/*   Updated: 2022/12/25 03:36:32 by tas              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int close_win(t_mlx *mlx)
{
    mlx_loop_end(mlx->mlx);
    return (0);
}

// int zoom(t_fractal f, t_data *img)
// {
//     f.x_max = (img->x / f.zoom + f.x_max) - (img->x / f.zoom * 1.3);
//     f.y_max = (img->y / f.zoom + f.y_max) - (img->y / f.zoom * 1.3);
//     f.zoom = f.zoom * 1.3;
//     return (0);
// }

// int	shift_color(t_mlx *mlx, t_fractal *f, t_data *img)
// {
// 	char	*name;

// 	name = f->name;
// 	printf("name: %s\n", name);
	
//     f->color = 0x00FF0000;
//     // f->color = f->color >> 1;
// 	if (ft_strcmp(name, "mandelbrot") == 0)
// 	{
// 		calc_fractal(img, f, mandelbrot, mlx);
// 	}
// 	else if (ft_strcmp(name, "julia") == 0)
// 		calc_fractal(img, f, julia, mlx);
// 	else if (ft_strcmp(name, "burningship") == 0)
// 		calc_fractal(img, f, burningship, mlx);
// 	printf("OK!\n");
// 	return (0);
// }

int keypress(int keycode, t_mlx *mlx, t_data *img)
{
    printf("key = %d\n", keycode);
	(void)img;
    if (keycode == 65307)
        close_win(mlx);
    // if (keycode == 99)
	// 	shift_color(mlx, &f, img);
        
    // if (keycode == 122)
        // zoom(f, img);
    return (0);
}
