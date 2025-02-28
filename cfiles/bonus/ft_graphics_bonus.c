/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_graphics_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarini <tarini@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 19:07:31 by tarini            #+#    #+#             */
/*   Updated: 2025/02/27 17:00:22 by tarini           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

void	ft_my_mlx_pixel_put(t_img *data, int x, int y, int color)
{
	if (x < 0 || x >= ULTRA_WIDTH || y < 0 || y >= ULTRA_HEIGHT)
		return ;
	*(unsigned int*)(data->addr + (y * data->line_length + \
		x * ((int)(data->bits_per_pixel * 0.125)))) = color;
}

int	ft_get_color_dark_rainbow(int x, int y, int iterations)
{
	t_color	color;

	ft_init_color(&color);
	color.cx = ULTRA_WIDTH / 2.0f;
	color.cy = ULTRA_HEIGHT / 2.0f;
	color.dx = x - color.cx;
	color.dy = y - color.cy;
	color.dist = sqrtf(color.dx * color.dx + color.dy * color.dy);
	color.t = color.dist / (sqrtf(color.cx * color.cx + color.cy * color.cy));
	color.iter_t = (float)iterations / MAX_ITER;
	color.angle = (color.t + color.iter_t) * 360.0f;
	color.r = (int)(sin(color.angle * M_PI / 180.0f) * 127 + 128);
	color.g = (int)(sin((color.angle + 120) * M_PI / 180.0f) * 127 + 128);
	color.b = (int)(sin((color.angle + 240) * M_PI / 180.0f) * 127 + 128);
	color.brightness = powf(1.0f - powf(color.t, 0.8f), 0.5f) * \
		powf(color.iter_t, 0.5f);
	color.r *= color.brightness;
	color.g *= color.brightness;
	color.b *= color.brightness;
	if (iterations == MAX_ITER)
		return (0x000000);
	return ((color.r << 16) | (color.g << 8) | color.b);
}

int	ft_get_color_light_rainbow(int x, int y, int iterations)
{
	t_color	color;

	ft_init_color(&color);
	color.cx = ULTRA_WIDTH / 2.0f;
	color.cy = ULTRA_HEIGHT / 2.0f;
	color.dx = x - color.cx;
	color.dy = y - color.cy;
	color.dist = sqrtf(color.dx * color.dx + color.dy * color.dy);
	color.t = color.dist / (sqrtf(color.cx * color.cx + color.cy * color.cy));
	color.iter_t = (float)iterations / MAX_ITER;
	color.angle = (color.t + color.iter_t * 2.0f) * 360.0f;
	color.r = (int)(sin(color.angle * M_PI / 180.0f) * 127 + 128);
	color.g = (int)(sin((color.angle + 120) * M_PI / 180.0f) * 127 + 128);
	color.b = (int)(sin((color.angle + 240) * M_PI / 180.0f) * 127 + 128);
	color.brightness = powf(1.0f - powf(color.t, 0.6f), 0.8f) * \
		powf(color.iter_t, 0.7f);
	color.brightness = fmaxf(color.brightness, 0.4f);
	color.r = fminf(color.r * color.brightness + 50, 255);
	color.g = fminf(color.g * color.brightness + 50, 255);
	color.b = fminf(color.b * color.brightness + 50, 255);
	if (iterations == MAX_ITER)
		return (0x000000);
	return ((color.r << 16) | (color.g << 8) | color.b);
}
