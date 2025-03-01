/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_window.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarini <tarini@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 18:27:22 by tarini            #+#    #+#             */
/*   Updated: 2025/02/26 15:07:06 by tarini           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_data	ft_init_window(void)
{
	t_data	data;

	data = ft_init_data();
	data.window = mlx_new_window(data.mlx, ULTRA_WIDTH, \
		ULTRA_HEIGHT, "Fractol");
	if (!data.window)
	{
		ft_free_data(&data);
		exit(EXIT_FAILURE);
	}
	data.img.img = mlx_new_image(data.mlx, ULTRA_WIDTH, ULTRA_HEIGHT);
	if (!data.img.img)
	{
		ft_free_data(&data);
		exit(EXIT_FAILURE);
	}
	data.img.addr = mlx_get_data_addr(data.img.img, &data.img.bits_per_pixel, \
		&data.img.line_length, &data.img.endian);
	if (!data.img.addr)
	{
		ft_free_data(&data);
		exit(EXIT_FAILURE);
	}
	return (data);
}
