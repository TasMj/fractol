/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tas <tas@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 17:54:47 by tas               #+#    #+#             */
/*   Updated: 2022/12/30 17:54:47 by tas              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mouse_hook(int keycode, int x, int y, t_mlx *mlx)
{
	if ((x >= 0 && x <= WIDTH) && (y >= 0 && y <= HEIGHT))
	{
		if (keycode == 4)
		{
			reset_screen(mlx);
			mlx->f.zoom += 100;
		}
		else if ((keycode == 5) && mlx->f.zoom > 100)
		{
			reset_screen(mlx);
			mlx->f.zoom -= 100;
		}
	}	
	find_fract(mlx);
	return (0);
}

// int	hook_expose(t_mlx *mlx, int x, int y)
// {
// 	if ((x >= 0 && x <= WIDTH) && (y >= 0 && y <= HEIGHT))
// 	{
// 		reset_screen(mlx);
//     	mlx->f.zoom += 100;
// 	}	
// 	find_fract(mlx);
// 	return (0);
// }