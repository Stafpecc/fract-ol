/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mandelbrot_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarini <tarini@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 18:37:08 by tarini            #+#    #+#             */
/*   Updated: 2025/02/21 19:07:08 by tarini           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

int ft_mandelbrot(t_data *data)
{
    int x;
    int y;
    int iterations;
    double tmp;
    double scale;
    t_complex c;
    t_complex z;

    y = 0;
    scale = (4.0 / ULTRA_WIDTH) / data->zoom;
    double centerX = (ULTRA_WIDTH >> 1) + data->offset_x;
    double centerY = (ULTRA_HEIGHT >> 1) + data->offset_y;

    while (y < ULTRA_HEIGHT)
    {
        x = 0;
        while (x < ULTRA_WIDTH)
        {
            c.zr = (x - centerX) * scale;
            c.zi = (y - centerY) * scale;
            z.zr = 0;
            z.zi = 0;
            iterations = 0;
            while (z.zr * z.zr + z.zi * z.zi <= 4 && iterations < MAX_ITER)
            {
                tmp = z.zr * z.zr - z.zi * z.zi + c.zr;
                z.zi = 2 * z.zr * z.zi + c.zi;
                z.zr = tmp;
                iterations++;
            }
            ft_myMlxPixelPut(&data->img, x, y, ft_get_color_dark_raibow(x, y, iterations));
            x++;
        }
        y++;
    }
    return (EXIT_SUCCESS);
}
