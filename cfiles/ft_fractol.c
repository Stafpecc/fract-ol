/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fractol.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarini <tarini@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 11:20:59 by tarini            #+#    #+#             */
/*   Updated: 2025/02/09 15:39:04 by tarini           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

#include "fractol.h"

int main(void)
{
    t_data data;

    data = ft_init_window();
    data.zoom = 1.0;
    data.offset_x = 0.0;
    data.offset_y = 0.0;
    ft_draw_fractal(&data);
    mlx_put_image_to_window(data.mlx, data.window, data.img.img, 0, 0);
    mlx_key_hook(data.window, ft_key_hook, &data);
    mlx_mouse_hook(data.window, ft_mouse_hook, &data);
    mlx_hook(data.window, 17, 0, ft_close_hook, &data);
    mlx_loop(data.mlx);
    ft_free_data(&data);
    return (EXIT_SUCCESS);
}

