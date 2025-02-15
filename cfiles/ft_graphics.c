/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_graphics.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarini <tarini@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 18:30:26 by tarini            #+#    #+#             */
/*   Updated: 2025/02/15 20:53:48 by tarini           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void ft_myMlxPixelPut(t_img *data, int x, int y, int color)
{
    if (x < 0 || x >= ULTRA_WIDTH || y < 0 || y >= ULTRA_HEIGHT)
        return;

    *(unsigned int*)(data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8))) = color;
}

void ft_putLine(t_data *data, int x1, int y1, int x2, int y2)
{
    int dx;
    int dy;
    int sx;
    int sy;
    int err;
    int e2;
    
    dx = abs(x2 - x1);
    dy = abs(y2 - y1);
    sx = -1;
    if (x1 < x2)
        sx = 1;
    sy = -1;
    if (y1 < y2)
        sy = 1;
    err = dx - dy;
    while (x1 >= 0 && x1 < ULTRA_WIDTH && y1 >= 0 && y1 < ULTRA_HEIGHT)
    {
        ft_myMlxPixelPut(&(data->img), x1, y1, 0xFF0000);
        if (x1 == x2 && y1 == y2)
            break;
        e2 = 2 * err;
        if (e2 > -dy)
        {
            err = err - dy;
            x1 = x1 + sx;
        }
        if (e2 < dx)
        {
            err = err + dx;
            y1 = y1 + sy;
        }
    }
}

int ft_get_color(int iterations)
{
	if (iterations == MAX_ITER)
		return 0x000000;
	return (0xFF0000 + (iterations * 255 / MAX_ITER) * 0x010101);
}
