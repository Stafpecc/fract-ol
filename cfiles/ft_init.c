/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarini <tarini@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 18:29:49 by tarini            #+#    #+#             */
/*   Updated: 2025/02/09 14:29:03 by tarini           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_data ft_init_data(void)
{
    t_data data;

    data.mlx = mlx_init();
    if (!data.mlx)
    {
        ft_printf("Error: MLX initialization failed\n");
        exit(EXIT_FAILURE);
    }
    data.window = NULL;
    data.img.img = NULL;
    return data;
}

void ft_free_data(t_data *data)
{
    if (!data)
        return;
    if (data->window)
        mlx_destroy_window(data->mlx, data->window);
    if (data->img.img)
        mlx_destroy_image(data->mlx, data->img.img);
    if (data->mlx)
    {
        mlx_destroy_display(data->mlx);
        free(data->mlx);
    }
    free(data);
}
