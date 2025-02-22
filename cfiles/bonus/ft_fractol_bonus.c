/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fractol_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarini <tarini@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 11:20:59 by tarini            #+#    #+#             */
/*   Updated: 2025/02/21 19:06:22 by tarini           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

void show_menu()
{
    ft_printf("if you want to see the mandelbrot fractal\n");
    ft_printf("Usage: ./fractol mandelbrot\n");
    ft_printf("if you want to see the julia fractal\n");
    ft_printf("Usage: ./fractol julia [julia_constant.zr] [julia_constant.zi] \n");
	ft_printf("Usage: ./fractol [fractal_name]\n");
    ft_printf("\n");
	ft_printf("Available bonus fractals:\n");
	ft_printf("  - mandelbrot\n");
	ft_printf("  - burning_ship\n");
	ft_printf("  - newton\n");
	ft_printf("  - dragon\n");
	ft_printf("  - sierpinski\n");
    ft_printf("  - julia_anime\n");
    
}

int main(int argc, char **argv)
{
    t_data data;
    int (*draw_fractal)(t_data *data);

    if (argc == 2)
    {
        if (ft_strcmp(argv[1], "mandelbrot") == 0)
            draw_fractal = ft_mandelbrot;
        else if (ft_strcmp(argv[1], "newton") == 0)
            draw_fractal = ft_newton;
        else if (ft_strcmp(argv[1], "dragon") == 0)
            draw_fractal = ft_dragon;
        else if (ft_strcmp(argv[1], "sierpinski") == 0)
            draw_fractal = ft_sierpinski;
        else if (ft_strcmp(argv[1], "burning_ship") == 0)
            draw_fractal = ft_burning_ship;
        else if (ft_strcmp(argv[1], "julia_anime") == 0)
            draw_fractal = ft_julia_anime;
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
        data.time = 0;
        data.tcount = 0.1;
        data.flag_traveling = 0;
        if (draw_fractal == ft_julia_anime)
        {
            data.julia_constant.zr = -0.7;
            data.julia_constant.zi = 0.27015;
            data.origin = malloc(sizeof(t_complex));
            data.dest = malloc(sizeof(t_complex));
            if (!data.origin || !data.dest)
                return (EXIT_FAILURE);
            data.origin->zr = -0.7;
            data.origin->zi = 0.27015;
            data.dest->zr = -0.2;
            data.dest->zi = -0.8;
        }
        
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
            data.ft_draw_fractal = draw_fractal;
            data.time = 0;
            data.tcount = 0.1;
            data.flag_traveling = 0;
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
