/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fractol.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarini <tarini@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 11:20:59 by tarini            #+#    #+#             */
/*   Updated: 2025/02/15 20:52:43 by tarini           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void show_menu()
{
    ft_printf("Usage: ./fractol [fractal_name]\n");
    ft_printf("Available fractals:\n");
    ft_printf("  mandelbrot\n");
    ft_printf("  julia\n");
    ft_printf("  burning_ship\n");
}

int main(int argc, char **argv)
{
    t_data data;
    
    if (argc != 2)
    {
        show_menu();
        return (EXIT_FAILURE);
    }
    data = ft_init_window();
    data.zoom = 1.0;
    data.offset_x = 0.0;
    data.offset_y = 0.0;
    

    if (ft_strcmp(argv[1], "mandelbrot") == 0)
        ft_mandelbrot(&data);
    else if (ft_strcmp(argv[1], "julia") == 0)
        ft_julia(&data);
    else if (ft_strcmp(argv[1], "burning_ship") == 0)
        ft_burning_ship(&data);
    else
    {
        ft_printf("Error: Unknown fractal '%s'\n", argv[1]);
        show_menu();
        return (EXIT_FAILURE);
    }
    int (*draw_fractal)(t_data *data);
    if (ft_strcmp(argv[1], "mandelbrot") == 0)
        draw_fractal = ft_mandelbrot;
    else if (ft_strcmp(argv[1], "julia") == 0)
        draw_fractal = ft_julia;
    else if (ft_strcmp(argv[1], "burning_ship") == 0)
        draw_fractal = ft_burning_ship;
    mlx_put_image_to_window(data.mlx, data.window, data.img.img, 0, 0);
    mlx_key_hook(data.window, ft_key_hook, &data);
    mlx_mouse_hook(data.window, ft_mouse_hook, &draw_fractal);
    mlx_hook(data.window, 17, 0, ft_close_hook, &data);
    mlx_loop(data.mlx);
    ft_free_data(&data);
    return (EXIT_SUCCESS);
}
