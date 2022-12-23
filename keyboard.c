/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tas <tas@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 09:56:58 by tas               #+#    #+#             */
/*   Updated: 2022/12/23 21:52:17 by tas              ###   ########.fr       */
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

int keypress(int keycode, t_mlx *mlx)
{
    printf("key = %d\n", keycode);
    if (keycode == 65307)
        close_win(mlx);
    // if (keycode == 122)
        // zoom(f, img);
    return (0);
}
