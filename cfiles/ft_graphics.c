/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_graphics.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarini <tarini@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 15:00:42 by tarini            #+#    #+#             */
/*   Updated: 2025/02/26 15:04:31 by tarini           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_my_mlx_pixel_put(t_img *data, int x, int y, int color)
{
	if (x < 0 || x >= ULTRA_WIDTH || y < 0 || y >= ULTRA_HEIGHT)
		return ;
	*(unsigned int *)(data->addr + (y * data->line_length + x * \
		((int)(data->bits_per_pixel * 0.125)))) = color;
}

int	ft_get_color(int iterations)
{
	int	r;
	int	g;
	int	b;

	r = 127;
	g = 128;
	b = 127;
	if (iterations == MAX_ITER)
		return (0x000000);
	return ((r << 16) | (g << 8) | b);
}
