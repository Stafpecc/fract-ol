/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_julia.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarini <tarini@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 20:09:29 by tarini            #+#    #+#             */
/*   Updated: 2025/02/15 20:23:33 by tarini           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int ft_julia(t_data *data)
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
    c.zr = -0.7;
    c.zi = 0.27015;
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
	return (EXIT_SUCCESS);
}
