/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarini <tarini@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 13:54:48 by tarini            #+#    #+#             */
/*   Updated: 2025/02/15 20:57:22 by tarini           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int ft_key_hook(int keysym, t_data *data, int (*ft_draw_fractale)(t_data *data))
{
    if (keysym == ESC)
    {
        ft_free_data(data);
        exit(0);
    }
    else if (keysym == SPACE)
        ft_printf("Move line\n");
    else if (keysym == ENTER)
        ft_printf("New line\n");
    else if (keysym == DEL)
        ft_printf("Delete last line\n");
    else if (keysym == UP)
        data->offset_y -= 0.1 / data->zoom;
    else if (keysym == DOWN)
        data->offset_y += 0.1 / data->zoom;
    else if (keysym == LEFT)
        data->offset_x -= 0.1 / data->zoom;
    else if (keysym == RIGHT)
        data->offset_x += 0.1 / data->zoom;
    else if (keysym == PLUS)
        data->zoom *= 1.1;
    else if (keysym == MINUS)
        data->zoom /= 1.1;
    else
        ft_printf("Unhandled keysym: %d\n", keysym);

    ft_render(data, ft_draw_fractale);
    return (EXIT_SUCCESS);
}

int ft_mouse_hook(int button, int x, int y, t_data *data, int (*ft_draw_fractale)(t_data *data))
{
    double new_x;
    double new_y;
    double zoom_factor = 0.5 * data->zoom;

    new_x = (x - (ULTRA_WIDTH >> 1)) / (zoom_factor * ULTRA_WIDTH) + data->offset_x;
    new_y = (y - (ULTRA_HEIGHT >> 1)) / (zoom_factor * ULTRA_HEIGHT) + data->offset_y;

    if (button == SCROLL_UP)
    {
        data->zoom *= 1.2;
        data->offset_x = new_x; 
        data->offset_y = new_y;
    }
    else if (button == SCROLL_DOWN)
    {
        data->zoom *= 0.8;
        data->offset_x = new_x;
        data->offset_y = new_y;
    }

    ft_render(data, ft_draw_fractale);
    return (EXIT_SUCCESS);
}

int ft_close_hook(t_data *data)
{
    ft_free_data(data);
    exit(0);
    return (EXIT_SUCCESS);
}


