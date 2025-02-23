/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fractol.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarini <tarini@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 11:20:59 by tarini            #+#    #+#             */
/*   Updated: 2025/02/21 18:29:43 by tarini           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void show_menu()
{
    ft_printf("if you want to see the mandelbrot fractal\n");
    ft_printf("Usage: ./fractol mandelbrot\n");
    ft_printf("if you want to see the julia fractal\n");
    ft_printf("Usage: ./fractol julia [julia_constant.zr] [julia_constant.zi] \n");
}

int main(int argc, char **argv)
{
    t_data data;
    int (*draw_fractal)(t_data *data);

    if (argc == 2)
    {
        if (ft_strcmp(argv[1], "mandelbrot") == 0)
            draw_fractal = ft_mandelbrot;
        else
        {
            ft_printf("Error: Unknown fractal '%s'\n", argv[1]);
            show_menu();
            return (EXIT_FAILURE);
        }
        data = ft_init_window();
        data.zoom = 1.0;
        data.offset_x = 0.0;
        data.offset_y = 0.0;
        data.ft_draw_fractal = draw_fractal;
        ft_render(&data, draw_fractal);
        mlx_key_hook(data.window, ft_key_hook, &data);
        mlx_mouse_hook(data.window, ft_mouse_hook, &data);
        mlx_hook(data.window, 17, 0, ft_close_hook, &data);
        mlx_loop(data.mlx);
        return (EXIT_SUCCESS);
    }
    else if (argc == 4)
    {
        if (ft_strcmp(argv[1], "julia") == 0)
        {
            draw_fractal = ft_julia;
            data = ft_init_window();
            data.julia_constant.zr = ft_atod(argv[2]);
            data.julia_constant.zi = ft_atod(argv[3]);
            data.zoom = 1.0;
            data.offset_x = 0.0;
            data.offset_y = 0.0;
            ft_render(&data, draw_fractal);
            mlx_key_hook(data.window, ft_key_hook, &data);
            mlx_mouse_hook(data.window, ft_mouse_hook, &data);
            mlx_hook(data.window, 17, 0, ft_close_hook, &data);
            mlx_loop(data.mlx);
            return (EXIT_SUCCESS);
        }
    }
    show_menu();
    return (EXIT_FAILURE);
}
