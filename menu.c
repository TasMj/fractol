/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmejri <tmejri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 12:15:23 by tas               #+#    #+#             */
/*   Updated: 2022/12/31 19:49:58 by tmejri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	display_menu(t_mlx *mlx)
{
	t_menu	*menu;

	menu = &mlx->menu;
	menu->path = MENU;
	menu->img = mlx_xpm_file_to_image(mlx->mlx, menu->path, &menu->w, &menu->h);
	menu->flag = 0;
	return (0);
}

void	draw_menu(t_mlx *mlx)
{
	if (mlx->menu.flag == 0)
	{
		mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, mlx->menu.img, 0, 0);
		mlx->menu.flag = 1;
	}
	else
	{
		find_fract(mlx);
		mlx->menu.flag = 0;
	}
}
