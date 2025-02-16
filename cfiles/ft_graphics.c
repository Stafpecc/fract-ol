/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_graphics.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarini <tarini@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 18:30:26 by tarini            #+#    #+#             */
/*   Updated: 2025/02/16 19:35:50 by tarini           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void ft_myMlxPixelPut(t_img *data, int x, int y, int color)
{
    if (x < 0 || x >= ULTRA_WIDTH || y < 0 || y >= ULTRA_HEIGHT)
        return ;
    *(unsigned int*)(data->addr + (y * data->line_length + x * ((int)(data->bits_per_pixel * 0.125)))) = color;
}

int ft_get_color(int iterations)
{
    double t = (double)iterations / (double)MAX_ITER;

    int r_base = 0;
    int g_base = 255;
    int b_base = 255;

    int r = (int)(r_base + sin(t * M_PI * 2) * 127); 
    int g = (int)(g_base + sin((t + 0.66) * M_PI * 2) * 127); 
    int b = (int)(b_base + sin((t + 0.33) * M_PI * 2) * 127); 

    if (iterations == MAX_ITER)
    {
        r = 240;
        g = 240;
        b = 240;
    }

    if (r < 0) r = 0;
    if (r > 255) r = 255;
    if (g < 0) g = 0;
    if (g > 255) g = 255;
    if (b < 0) b = 0;
    if (b > 255) b = 255;

    return (r << 16) | (g << 8) | b;
}
