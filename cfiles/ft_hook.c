/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarini <tarini@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 13:54:48 by tarini            #+#    #+#             */
/*   Updated: 2025/03/03 14:53:04 by tarini           ###   ########.fr       */
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
	double	mouse_x;
	double	mouse_y;
	double	zoom_factor;
	double	old_zoom;
	double	new_zoom;

	old_zoom = data->zoom;
	if (button == SCROLL_UP)
		zoom_factor = 1.1;
	else if (button == SCROLL_DOWN)
		zoom_factor = 0.9;
	else
		return (EXIT_SUCCESS);
	new_zoom = data->zoom * zoom_factor;
	if (new_zoom < ZOOM_MIN)
		new_zoom = ZOOM_MIN;
	else if (new_zoom > ZOOM_MAX)
		new_zoom = ZOOM_MAX;
	mouse_x = (x - (ULTRA_WIDTH >> 1)) * old_zoom + data->offset_x;
	mouse_y = (y - (ULTRA_HEIGHT >> 1)) * old_zoom + data->offset_y;
	data->zoom = new_zoom;
	data->offset_x = mouse_x - ((x - (ULTRA_WIDTH >> 1)) * data->zoom);
	data->offset_y = mouse_y - ((y - (ULTRA_HEIGHT >> 1)) * data->zoom);
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
