/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_burning_ship_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarini <tarini@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 18:29:17 by tarini            #+#    #+#             */
/*   Updated: 2025/02/26 15:11:31 by tarini           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

int	ft_burning_ship(t_data *data)
{
	int			x;
	int			y;
	int			iterations;
	double		tmp;
	double		scale;
	t_complex	c;
	t_complex	z;

	y = 0;
	scale = (4.0 / ULTRA_WIDTH) / data->zoom;
	while (y < ULTRA_HEIGHT)
	{
		x = 0;
		while (x < ULTRA_WIDTH)
		{
			c.zr = (x - (ULTRA_WIDTH >> 1)) * scale + data->offset_x;
			c.zi = (y - (ULTRA_HEIGHT >> 1)) * scale + data->offset_y;
			z.zr = 0;
			z.zi = 0;
			iterations = 0;
			while (z.zr * z.zr + z.zi * z.zi <= 4 && iterations < MAX_ITER)
			{
				tmp = z.zr * z.zr - z.zi * z.zi + c.zr;
				z.zi = 2 * fabs(z.zr * z.zi) + c.zi;
				z.zr = tmp;
				iterations++;
			}
			ft_my_mlx_pixel_put(&data->img, x, y, \
				ft_get_color_light_rainbow(x, y, iterations));
			x++;
		}
		y++;
	}
	return (EXIT_SUCCESS);
}
