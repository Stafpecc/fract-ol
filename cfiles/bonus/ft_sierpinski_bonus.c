/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sierpinski_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarini <tarini@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 20:22:47 by tarini            #+#    #+#             */
/*   Updated: 2025/02/26 19:43:56 by tarini           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

static int	is_sierpinski(int x, int y)
{
	while (x > 0 || y > 0)
	{
		if ((x % 3 == 1) && (y % 3 == 1))
			return (0);
		if ((x % 3 == 2) && (y % 3 == 2))
			return (0);
		x /= 3;
		y /= 3;
	}
	return (1);
}

int	ft_sierpinski(t_data *data)
{
	int	x;
	int	y;
	int	color;

	y = 0;
	while (y < ULTRA_HEIGHT)
	{
		x = 0;
		while (x < ULTRA_WIDTH)
		{
			color = ft_get_color_dark_rainbow(x, y, (x + y) % MAX_ITER);
			if (is_sierpinski(x, y))
				ft_my_mlx_pixel_put(&data->img, x, y, color);
			else
				ft_my_mlx_pixel_put(&data->img, x, y, 0x000000);
			x++;
		}
		y++;
	}
	return (EXIT_SUCCESS);
}
