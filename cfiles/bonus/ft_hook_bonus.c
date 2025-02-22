/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hook_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarini <tarini@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 13:54:48 by tarini            #+#    #+#             */
/*   Updated: 2025/02/21 18:30:06 by tarini           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

int ft_key_hook(int keysym, t_data *data)
{
    if (keysym == ESC)
    {
        ft_free_data(data);
        exit(0);
    }
    else if (keysym == SPACE)
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
    else if (keysym == DEL)
    {
        if (data->psychedelic == 1)
            data->psychedelic = 0;
        else
            data->psychedelic = 1;
    }
    else if (keysym == UP)
        data->offset_y -= 0.1 * data->zoom;
    else if (keysym == DOWN)
        data->offset_y += 0.1 * data->zoom;
    else if (keysym == LEFT)
        data->offset_x -= 0.1 * data->zoom;
    else if (keysym == RIGHT)
        data->offset_x += 0.1 * data->zoom;
    else if (keysym == PLUS)
        data->zoom *= 1.1;
    else if (keysym == MINUS)
        data->zoom *= 0.9;
    ft_render(data, data->ft_draw_fractal);
    return (EXIT_SUCCESS);
}

int ft_mouse_hook(int button, int x, int y, t_data *data)
{
    double new_x;
    double new_y;
    
    new_x = (x - (ULTRA_WIDTH >> 1)) * data->zoom;
    new_y = (y - (ULTRA_HEIGHT >> 1)) * data->zoom;
    if (button == SCROLL_UP)
    {
        data->zoom *= 1.1;
        data->offset_x -= new_x * 0.1;
        data->offset_y -= new_y * 0.1;
    }
    else if (button == SCROLL_DOWN)
    {
        data->zoom *= 0.9;
        data->offset_x += new_x * 0.1;
        data->offset_y += new_y * 0.1;
    }
    ft_render(data, data->ft_draw_fractal);
    return (EXIT_SUCCESS);
}

int ft_close_hook(t_data *data)
{
    ft_free_data(data);
    exit(0);
    return (EXIT_SUCCESS);
}

int ft_loop_hook(t_data *data)
{
    if (data->is_animating)
    {
        ft_animation(data);
        ft_render(data, data->ft_draw_fractal);
    }
    mlx_put_image_to_window(data->mlx, data->window, data->img.img, 0, 0);
    return (EXIT_SUCCESS);
}