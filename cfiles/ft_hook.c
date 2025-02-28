/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarini <tarini@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 13:54:48 by tarini            #+#    #+#             */
/*   Updated: 2025/02/28 18:09:14 by tarini           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_key_hook(int keysym, t_data *data)
{
	if (keysym == ESC)
	{
		ft_free_data(data);
		exit(0);
	}
	else if (keysym == UP)
		data->offset_y -= 5 * data->zoom;
	else if (keysym == DOWN)
		data->offset_y += 5 * data->zoom;
	else if (keysym == LEFT)
		data->offset_x -= 5 * data->zoom;
	else if (keysym == RIGHT)
		data->offset_x += 5 * data->zoom;
	else if (keysym == PLUS)
		data->zoom *= 1.1;
	else if (keysym == MINUS)
		data->zoom *= 0.9;
	ft_render(data, data->ft_draw_fractal);
	return (EXIT_SUCCESS);
}

int	ft_mouse_hook(int button, int x, int y, t_data *data)
{
	double	new_x;
	double	new_y;

	new_x = (x - (ULTRA_WIDTH >> 1)) * data->zoom;
	new_y = (y - (ULTRA_HEIGHT >> 1)) * data->zoom;
	if (button == SCROLL_UP)
	{
		data->zoom += 0.2;
		data->offset_x -= new_x * 0.2;
		data->offset_y -= new_y * 0.2;
	}
	else if (button == SCROLL_DOWN)
	{
		data->zoom -= 0.2;
		data->offset_x += new_x * 0.2;
		data->offset_y += new_y * 0.2;
	}
	ft_render(data, data->ft_draw_fractal);
	return (EXIT_SUCCESS);
}

int	ft_close_hook(t_data *data)
{
	ft_free_data(data);
	exit(0);
	return (EXIT_SUCCESS);
}

int	ft_loop_hook(t_data *data)
{
	mlx_put_image_to_window(data->mlx, data->window, data->img.img, 0, 0);
	return (EXIT_SUCCESS);
}
