/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarini <tarini@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 17:21:47 by tarini            #+#    #+#             */
/*   Updated: 2025/02/16 18:07:24 by tarini           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

void ft_animation(t_data *data)
{
    data->flag_traveling = 1;
    data->time += data->tcount;
    data->julia_constant.zr = data->origin->zr + ((sin(data->time) + 1) * 0.5) * (data->dest->zr);
    data->julia_constant.zi = data->origin->zi + ((sin(data->time) + 1) * 0.5) * (data->dest->zi);
    if (data->psychedelic == 1)
        ft_render(data, ft_julia);
    else
        ft_render(data, ft_julia_anime);
    mlx_do_sync(data->mlx);
}