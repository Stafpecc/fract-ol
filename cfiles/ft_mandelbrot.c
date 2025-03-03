/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mandelbrot.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarini <tarini@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 18:37:08 by tarini            #+#    #+#             */
/*   Updated: 2025/03/03 14:54:44 by tarini           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_mandelbrot(t_data *data)
{
	t_fractal	fract;
	t_complex	c;
	t_complex	z;

	ft_init_fractal(&fract, data);
	while (fract.y < ULTRA_HEIGHT)
	{
		fract.x = 0;
		while (fract.x < ULTRA_WIDTH)
		{
			c.zr = (fract.x - fract.center_x) * fract.scale;
			c.zi = (fract.y - fract.center_y) * fract.scale;
			z.zr = 0;
			z.zi = 0;
			fract.iterations = 0;
			while (z.zr * z.zr + z.zi * z.zi <= 4 && \
				fract.iterations < MAX_ITER)
				fract.iterations += ft_fractal_formula(&z, &c);
			ft_my_mlx_pixel_put(&data->img, fract.x, fract.y, \
				ft_get_color(fract.iterations));
			fract.x++;
		}
		fract.y++;
	}
	return (EXIT_SUCCESS);
}
