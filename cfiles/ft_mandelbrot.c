/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mandelbrot.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarini <tarini@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 18:37:08 by tarini            #+#    #+#             */
/*   Updated: 2025/02/09 16:15:27 by tarini           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int ft_get_color(int iterations)
{
	if (iterations == MAX_ITER)
		return 0x000000;
	return (0xFF0000 + (iterations * 255 / MAX_ITER) * 0x010101);
}

// void ft_draw_fractal(t_data *data)
// {
//     int x;
//     int y;
//     int iterations;
//     double tmp;
//     double scale;
//     t_complex c;
//     t_complex z;

//     y = 0;

//     scale = (4.0 / ULTRA_WIDTH) / data->zoom;
//     while (y < ULTRA_HEIGHT)
//     {
//         x = 0;
//         while (x < ULTRA_WIDTH)
//         {
//             c.zr = (x - (ULTRA_WIDTH >> 1)) * scale + data->offset_x;
//             c.zi = (y - (ULTRA_HEIGHT >> 1))* scale + data->offset_y;
//             z.zr = 0;
//             z.zi = 0;
//             iterations = 0;
//             while (z.zr * z.zr + z.zi * z.zi <= 4 && iterations < MAX_ITER)
//             {
//                 tmp = z.zr * z.zr - z.zi * z.zi + c.zr;
//                 z.zi = 2 * z.zr * z.zi + c.zi;
//                 z.zr = tmp;
//                 iterations++;
//             }
//             ft_myMlxPixelPut(&data->img, x, y, ft_get_color(iterations));
//             x++;
//         }
//         y++;
//     }
// }

void ft_draw_fractal(t_data *data)
{
    int x;
    int y;
    int iterations;
    double tmp;
    double scale;
    t_complex c;
    t_complex z;

    scale = (4.0 / ULTRA_WIDTH) / data->zoom;
    c.zi = -0.7;
    c.zr = 0.27015;

    y = 0;
    while (y < ULTRA_HEIGHT)
    {
        x = 0;
        while (x < ULTRA_WIDTH)
        {
            z.zr = (x - (ULTRA_WIDTH >> 1)) * scale + data->offset_x;
            z.zi = (y - (ULTRA_HEIGHT >> 1)) * scale + data->offset_y;
            iterations = 0;
            while (z.zr * z.zr + z.zi * z.zi <= 4 && iterations < MAX_ITER)
            {
                tmp = z.zr * z.zr - z.zi * z.zi + c.zr;
                z.zi = 2 * z.zr * z.zi + c.zi;
                z.zr = tmp;
                iterations++;
            }
            ft_myMlxPixelPut(&data->img, x, y, ft_get_color(iterations));
            x++;
        }
        y++;
    }
}
