/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_julia_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarini <tarini@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 20:09:29 by tarini            #+#    #+#             */
/*   Updated: 2025/02/21 18:30:29 by tarini           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

int ft_get_color_julia_animation(int iterations, t_data *data);

int ft_julia_anime(t_data *data)
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
    c.zr = data->julia_constant.zr;
    c.zi = data->julia_constant.zi;
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
            ft_myMlxPixelPut(&data->img, x, y, ft_get_color_julia_animation(iterations, data));
            x++;
        }
        y++;
    }
    return (EXIT_SUCCESS);
}

int ft_get_color_julia_animation(int iterations, t_data *data)
{
    double t = (double)iterations / (double)MAX_ITER;
    double hue_shift = fmod(data->time * 0.05, 1.0);
    double shift = sin(data->time * 0.3) * 5.0;
    double intensity = (sin(data->time * 0.2) + 1.0) * 0.5;
    int r = (int)((255 * fabs(sin(t * M_PI * 2 + hue_shift * M_PI + shift))) * intensity);
    int g = (int)((255 * fabs(sin((t + 0.33) * M_PI * 2 + hue_shift * M_PI - shift))) * intensity);
    int b = (int)((255 * fabs(cos((t + 0.66) * M_PI * 2 + hue_shift * M_PI + shift * 0.5))) * intensity);

    if (rand() % 50 == 0)
    {
        r = 255;
        g = 255;
        b = 255;
    }
    if (iterations == MAX_ITER)
    {
        r = 240;
        g = 240;
        b = 240;
    }
    if (r < 0) r = 0; if (r > 255) r = 255;
    if (g < 0) g = 0; if (g > 255) g = 255;
    if (b < 0) b = 0; if (b > 255) b = 255;
    return ((r << 16) | (g << 8) | b);
}

