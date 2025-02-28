/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hook_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarini <tarini@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 13:54:48 by tarini            #+#    #+#             */
/*   Updated: 2025/02/27 17:56:52 by tarini           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

int	ft_mouse_hook(int button, int x, int y, t_data *data)
{
	double	new_x;
	double	new_y;
	double	prev_scale;

	prev_scale = data->zoom;
	new_x = (x - (ULTRA_WIDTH >> 1)) * data->zoom;
	new_y = (y - (ULTRA_HEIGHT >> 1)) * data->zoom;
	if (button == SCROLL_UP)
	{
		data->zoom *= 1.1;
		data->offset_x -= new_x * 0.1 * prev_scale;
		data->offset_y -= new_y * 0.1 * prev_scale;
	}
	else if (button == SCROLL_DOWN)
	{
		data->zoom *= 0.9;
		data->offset_x += new_x * 0.1 * prev_scale;
		data->offset_y += new_y * 0.1 * prev_scale;
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
	if (data->is_animating)
	{
		ft_animation(data);
		ft_render(data, data->ft_draw_fractal);
	}
	mlx_put_image_to_window(data->mlx, data->window, data->img.img, 0, 0);
	return (EXIT_SUCCESS);
}
