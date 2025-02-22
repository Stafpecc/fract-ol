/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_newton_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarini <tarini@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 20:21:12 by tarini            #+#    #+#             */
/*   Updated: 2025/02/21 18:30:42 by tarini           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

int ft_newton(t_data *data)
{
    int x, y, iterations;
    double scale;
    t_complex z, dz, c;

    t_complex roots[3] = {
        {1.0, 0.0},
        {-0.5, 0.5 * sqrt(3)},
        {-0.5, -0.5 * sqrt(3)}
    };

    y = 0;
    scale = (4.0 / ULTRA_WIDTH) / data->zoom;
    while (y < ULTRA_HEIGHT)
    {
        x = 0;
        while (x < ULTRA_WIDTH)
        {
            c.zr = (x - (ULTRA_WIDTH >> 1)) * scale + data->offset_x;
            c.zi = (y - (ULTRA_HEIGHT >> 1)) * scale + data->offset_y;
            z.zr = c.zr;
            z.zi = c.zi;
            iterations = 0;
            while (z.zr * z.zr + z.zi * z.zi <= 4 && iterations < MAX_ITER)
            {
                dz.zr = (z.zr * z.zr - z.zi * z.zi) / (3 * z.zr * z.zr - z.zi * z.zi);
                dz.zi = (2 * z.zr * z.zi) / (3 * z.zr * z.zr - z.zi * z.zi); 

                z.zr -= (z.zr * z.zr * z.zr - z.zi * z.zi - 1) / (3 * z.zr * z.zr - z.zi * z.zi);
                z.zi -= (2 * z.zr * z.zi) / (3 * z.zr * z.zr - z.zi * z.zi);

                iterations++;
            }
            int root_index = 0;
            double min_dist = 1e6;
            for (int i = 0; i < 3; i++) {
                double dist = sqrt(pow(z.zr - roots[i].zr, 2) + pow(z.zi - roots[i].zi, 2));
                if (dist < min_dist) {
                    min_dist = dist;
                    root_index = i;
                }
            }
            ft_myMlxPixelPut(&data->img, x, y, ft_get_color_dark_raibow(x, y, root_index));
            x++;
        }
        y++;
    }
    return (EXIT_SUCCESS);
}
