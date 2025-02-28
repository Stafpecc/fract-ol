/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dragon_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarini <tarini@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 20:20:12 by tarini            #+#    #+#             */
/*   Updated: 2025/02/27 17:51:56 by tarini           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

int	ft_dragon(t_data *data)
{
	t_fractal	f;
	t_complex	c;
	t_complex	z;

	ft_init_fractal(&f, data);
	while (f.y < ULTRA_HEIGHT)
	{
		f.x = 0;
		while (f.x < ULTRA_WIDTH)
		{
			c.zr = (f.x - f.center_x) * f.scale;
			c.zi = (f.y - f.center_y) * f.scale;
			z.zr = c.zr;
			z.zi = c.zi;
			f.iterations = 0;
			while (z.zr * z.zr + z.zi * z.zi <= 4 && f.iterations < MAX_ITER)
				f.iterations += ft_fractal_formula(&z, &c);
			ft_my_mlx_pixel_put(&data->img, f.x, f.y, \
				ft_get_color_light_rainbow(f.x, f.y, f.iterations));
			f.x++;
		}
		f.y++;
	}
	return (EXIT_SUCCESS);
}
