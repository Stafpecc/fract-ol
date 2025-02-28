/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_julia_anime_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarini <tarini@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 20:09:29 by tarini            #+#    #+#             */
/*   Updated: 2025/02/27 17:46:27 by tarini           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

static void	normalize_rgb(t_color_julia_anime *color)
{
	if (color->r < 0)
		color->r = 0;
	if (color->r > 255)
		color->r = 255;
	if (color->g < 0)
		color->g = 0;
	if (color->g > 255)
		color->g = 255;
	if (color->b < 0)
		color->b = 0;
	if (color->b > 255)
		color->b = 255;
}

int	ft_get_color_julia_animation(int iterations, t_data *data)
{
	t_color_julia_anime	color;

	ft_init_color_julia_anime(&color, *data, iterations);
	if (rand() % 50 == 0)
	{
		color.r = 255;
		color.g = 255;
		color.b = 255;
	}
	if (iterations == MAX_ITER)
	{
		color.r = 240;
		color.g = 240;
		color.b = 240;
	}
	normalize_rgb(&color);
	return ((color.r << 16) | (color.g << 8) | color.b);
}

int	ft_julia_anime(t_data *data)
{
	t_fractal	f;
	t_complex	c;
	t_complex	z;

	ft_init_fractal(&f, data);
	c.zr = data->julia_constant.zr;
	c.zi = data->julia_constant.zi;
	while (f.y < ULTRA_HEIGHT)
	{
		f.x = 0;
		while (f.x < ULTRA_WIDTH)
		{
			z.zr = (f.x - f.center_x) * f.scale;
			z.zi = (f.y - f.center_y) * f.scale;
			f.iterations = 0;
			while (z.zr * z.zr + z.zi * z.zi <= 4 && f.iterations < MAX_ITER)
				f.iterations += ft_fractal_formula(&z, &c);
			ft_my_mlx_pixel_put(&data->img, f.x, f.y, \
				ft_get_color_julia_animation(f.iterations, data));
			f.x++;
		}
		f.y++;
	}
	return (EXIT_SUCCESS);
}
