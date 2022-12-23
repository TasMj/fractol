// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   mouse.c                                            :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: tas <tas@student.42.fr>                    +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2022/12/22 10:55:20 by tas               #+#    #+#             */
// /*   Updated: 2022/12/22 20:38:18 by tas              ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

// #include "fractol.h"


// #include "fractol.h"

// t_fractal   init_julia(t_fractal f_julia)
// {
//     f_julia.x_min = -1;
//     f_julia.x_max = 1;
//     f_julia.y_min = -1.2;
//     f_julia.y_max = 1.2;
//     f_julia.zoom = 100;
//     f_julia.iteration_max = 150;
// 	f_julia.image_x = (f_julia.x_max - f_julia.x_min);
// 	f_julia.image_y = (f_julia.y_max - f_julia.y_min);
//     return (f_julia);
// }

// void calculate_julia(t_data *img, t_fractal f_j)
// {
//     double x;
//     double y;
	
// 	x = 0;
// 	f_j = init_julia(f_j);
// 	while (x < WIDTH)
//     {
// 		y = 0;
//         while (y < HEIGHT)
//         {
// 			julia(img, x, y, f_j);
// 			y++;
// 			}
//         x++;
//     }
// }

// void	julia(t_data *img, double x, double y, t_fractal f_j)
// {
//     int i;
//     t_complex   c;
//     t_complex   z;
// 	double		tmp_r;
    
//     i = 0;
//     c.r = 0.285;
//     c.i = 0.01;
// 	z.r = x / f_j.zoom + f_j.x_min;
// 	z.i = y / f_j.zoom + f_j.y_min;
// 	while ((pow(z.r, 2) + pow(z.r, 2)) < 4 && i < 150) 
// 	{
// 		tmp_r = z.r;
// 		z.r = (z.r * z.r) - (z.i * z.i) + c.r;
// 		z.i = (2 * z.i * tmp_r) + c.i;
// 		i++;
// 	}
// 	if (i == 150)
// 		put_pixel(img, x + (WIDTH/2) , y + (HEIGHT/2), 0x0077B5FE);
// }

// // 		z.r = (z.r * z.r) - (z.i * z.i) - 0.8 + (0.6 / x / WIDTH);
// //		 z.i = (2 * z.i * tmp_r) + (0.27015 / y / HEIGHT);

///////////////////////////////////////////////////////////////////////////////////////////////

// void calculate_julia(t_data *img, t_fractal f_j)
// {
    // double x = img->x;
    // double y = img->y;
	// f_j = init_julia(f_j);
	// while (x < WIDTH)
    // {
        // while (y < HEIGHT)
        // {
			// julia(img, (f_j.image_x / WIDTH) * x * 100, (f_j.image_y / HEIGHT) * y * 100);
			// y++;
		// }
		// y = 0;
        // x++;
    // }
// }
// 
// void	julia(t_data *img, double x, double y)
// {
    // int i;
    // t_complex   c;
    // t_complex   z;
	// double		tmp_r;
    // 
    // i = 0;
    // c.r = 0.285;
    // c.i = 0.01;
	// z.r = x / 300 - 1;
	// z.i = y / 300 - 1.2;
	// while ((pow(z.r, 2) + pow(z.r, 2)) < 4 && i < 150)
	// {
		// tmp_r = z.r;
		// z.r = (z.r * z.r) - (z.i * z.i) + c.r;
		// z.i = (2 * z.i * tmp_r) + c.i;
		// i++;
	// }
	// if (i == 150)
	// {
		// put_pixel(img, x + (WIDTH/2), y + (HEIGHT/2), 0x0077B5FE);
	// }
	// img->x = z.r;
	// img->y = z.i;
// }