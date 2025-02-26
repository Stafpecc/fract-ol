/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_julia.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarini <tarini@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 15:57:39 by tarini            #+#    #+#             */
/*   Updated: 2025/02/26 21:06:07 by tarini           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_julia(t_data *data)
{
	t_fractal	fract;
	t_complex	c;
	t_complex	z;

	ft_init_fractal(&fract, data);
	c.zr = data->julia_constant.zr;
	c.zi = data->julia_constant.zi;
	while (fract.y < ULTRA_HEIGHT)
	{
		fract.x = 0;
		while (fract.x < ULTRA_WIDTH)
		{
			z.zr = (fract.x - fract.center_x) * fract.scale;
			z.zi = (fract.y - fract.center_y) * fract.scale;
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
