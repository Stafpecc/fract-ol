/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fractol_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarini <tarini@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 18:11:49 by tarini            #+#    #+#             */
/*   Updated: 2025/02/28 18:22:36 by tarini           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

static int	handle_fractal(int (**draw_fractal)(t_data *data), char **argv)
{
	if (ft_strcmp(argv[1], "mandelbrot") == 0)
		*draw_fractal = ft_mandelbrot;
	else if (ft_strcmp(argv[1], "dragon") == 0)
		*draw_fractal = ft_dragon;
	else if (ft_strcmp(argv[1], "sierpinski") == 0)
		*draw_fractal = ft_sierpinski;
	else if (ft_strcmp(argv[1], "burning_ship") == 0)
		*draw_fractal = ft_burning_ship;
	else if (ft_strcmp(argv[1], "julia_anime") == 0)
		*draw_fractal = ft_julia_anime;
	else
		return (show_menu(argv));
	return (EXIT_SUCCESS);
}

int	main(int argc, char **argv)
{
	t_data	data;
	int		(*draw_fractal)(t_data *data);

	draw_fractal = NULL;
	if (argc == 2)
	{
		data = ft_init_window();
		if (handle_fractal(&draw_fractal, argv) != 0)
			return (EXIT_FAILURE);
		if_fract(data, draw_fractal);
		return (EXIT_SUCCESS);
	}
	else if (argc == 4 && ft_strcmp(argv[1], "julia") == 0)
	{
		data = ft_init_window();
		if_julia(data, argv);
		return (EXIT_SUCCESS);
	}
	return (show_menu(argv));
}
