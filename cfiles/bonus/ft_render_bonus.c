/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarini <tarini@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 18:26:24 by tarini            #+#    #+#             */
/*   Updated: 2025/02/26 18:51:27 by tarini           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

int	ft_render(t_data *data, int (*ft_draw_fractal)(t_data *data))
{
	if (!data || !data->mlx || !data->window || !data->img.img)
		return (EXIT_FAILURE);
	ft_draw_fractal(data);
	mlx_put_image_to_window(data->mlx, data->window, data->img.img, 0, 0);
	return (EXIT_SUCCESS);
}
