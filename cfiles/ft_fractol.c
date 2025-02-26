/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fractol.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarini <tarini@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 11:20:59 by tarini            #+#    #+#             */
/*   Updated: 2025/02/26 20:59:36 by tarini           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	show_menu(void)
{
	ft_printf("Usage:\n");
	ft_printf(" ./fractol mandelbrot\n");
	ft_printf(" ./fractol julia [zr] [zi]\n");
	return (EXIT_FAILURE);
}

int	main(int argc, char **argv)
{
	t_data	data;
	int		(*draw_fractal)(t_data *);

	data = ft_init_window();
	if (argc == 2 && ft_strcmp(argv[1], "mandelbrot") == 0)
		draw_fractal = ft_mandelbrot;
	else if (argc == 4 && ft_strcmp(argv[1], "julia") == 0)
	{
		draw_fractal = ft_julia;
		data.julia_constant.zr = ft_atod(argv[2]); // free window si atod foire
		data.julia_constant.zi = ft_atod(argv[3]);
	}
	else
	{
		ft_free_data(&data);
		return (show_menu());
	}
	data.ft_draw_fractal = draw_fractal;
	ft_render(&data, draw_fractal);
	mlx_key_hook(data.window, ft_key_hook, &data);
	mlx_mouse_hook(data.window, ft_mouse_hook, &data);
	mlx_hook(data.window, 17, 0, ft_close_hook, &data);
	mlx_loop(data.mlx);
	return (EXIT_SUCCESS);
}
