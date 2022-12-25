/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tas <tas@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 17:09:20 by tas               #+#    #+#             */
/*   Updated: 2022/12/25 02:02:01 by tas              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i])
	{
		if (s1[i] == '\0')
			return (0);
		i++;
	}
	return (1);
}

void    put_pixel(t_data *data, int x, int y, int color)
{
    char	*dst;

	if (x < 0 || x > WIDTH || y < 0 || y > HEIGHT)
		return ;
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

// void	cadre(t_data *img, int x, int y) // A SUPPR
// {
// 	while (y <= HEIGHT)
// 	{
// 		while (x <= WIDTH)
// 		{
// 			if (x == 0 || x == WIDTH - 1 || x == WIDTH / 2 || y == 0 || y == HEIGHT - 1 || y == HEIGHT / 2)
// 			{
// 				put_pixel(img, x, y, 0x00FFA500);
// 			}
// 			x++;
// 		}
// 		x = 0;
// 		y++;
// 	}
// }