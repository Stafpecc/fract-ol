/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_hook_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarini <tarini@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 17:56:25 by tarini            #+#    #+#             */
/*   Updated: 2025/02/27 17:59:09 by tarini           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

static void	key_hook_part_space(t_data *data)
{
	if (data->ft_draw_fractal == ft_julia_anime)
	{
		data->is_animating = !data->is_animating;
		if (data->is_animating)
			mlx_loop_hook(data->mlx, ft_loop_hook, data);
		else
			mlx_loop_hook(data->mlx, NULL, NULL);
	}
}

static void	key_hook_part_psy(t_data *data)
{
	if (data->psychedelic == 1)
		data->psychedelic = 0;
	else
		data->psychedelic = 1;
}

int	ft_key_hook(int keysym, t_data *data)
{
	if (keysym == ESC)
	{
		ft_free_data(data);
		exit(0);
	}
	else if (keysym == SPACE)
		key_hook_part_space(data);
	else if (keysym == DEL)
		key_hook_part_psy(data);
	else if (keysym == UP)
		data->offset_y += 5 * data->zoom;
	else if (keysym == DOWN)
		data->offset_y -= 5 * data->zoom;
	else if (keysym == LEFT)
		data->offset_x += 5 * data->zoom;
	else if (keysym == RIGHT)
		data->offset_x -= 5 * data->zoom;
	else if (keysym == PLUS)
		data->zoom *= 1.1;
	else if (keysym == MINUS)
		data->zoom *= 0.9;
	ft_render(data, data->ft_draw_fractal);
	return (EXIT_SUCCESS);
}
