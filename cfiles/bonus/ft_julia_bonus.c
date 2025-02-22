/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_julia_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarini <tarini@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 15:57:39 by tarini            #+#    #+#             */
/*   Updated: 2025/02/21 19:07:04 by tarini           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

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
			ft_myMlxPixelPut(&data->img, x, y, ft_get_color_light_raimbow(x, y, iterations));
			x++;
		}
		y++;
	}
	return (EXIT_SUCCESS);
}