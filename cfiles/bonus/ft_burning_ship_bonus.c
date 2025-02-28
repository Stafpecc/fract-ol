/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_burning_ship_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarini <tarini@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 18:29:17 by tarini            #+#    #+#             */
/*   Updated: 2025/02/27 17:52:02 by tarini           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

static int	ft_burning_ship_formula(t_complex *z, t_complex *c)
{
	double	tmp;

	tmp = z->zr * z->zr - z->zi * z->zi + c->zr;
	z->zi = 2 * z->zr * z->zi + c->zi;
	z->zr = tmp;
	return (1);
}

int	ft_burning_ship(t_data *data)
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
			z.zr = 0;
			z.zi = 0;
			f.iterations = 0;
			while (z.zr * z.zr + z.zi * z.zi <= 4 && f.iterations < MAX_ITER)
				f.iterations += ft_burning_ship_formula(&z, &c);
			ft_my_mlx_pixel_put(&data->img, f.x, f.y, \
				ft_get_color_light_rainbow(f.x, f.y, f.iterations));
			f.x++;
		}
		f.y++;
	}
	return (EXIT_SUCCESS);
}
