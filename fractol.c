/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmejri <tmejri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 17:08:21 by tmejri            #+#    #+#             */
/*   Updated: 2022/11/30 16:31:45 by tmejri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	void	*img;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Fractol");
	img = mlx_new_image(mlx, 1920, 1080);
	mlx_win +=1;
	mlx_win -=1;
	img +=1;
	img -=1;
	mlx_pixel_put(mlx, mlx_win, 0, 0, 0xFF0000);
	
	mlx_loop(mlx);
}