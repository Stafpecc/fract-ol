/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarini <tarini@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 18:29:49 by tarini            #+#    #+#             */
/*   Updated: 2025/02/26 21:14:57 by tarini           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

t_data	ft_init_data(void)
{
	t_data	data;

	data.mlx = mlx_init();
	if (!data.mlx)
		exit(EXIT_FAILURE);
	data.window = NULL;
	data.img.img = NULL;
	data.img.addr = NULL;
	data.img.bits_per_pixel = 0;
	data.img.line_length = 0;
	data.img.endian = 0;
	data.zoom = 1.0;
	data.offset_x = 0.0;
	data.offset_y = 0.0;
	data.time = 0.0;
	data.tcount = 0.0;
	data.flag_traveling = 0;
	data.ft_draw_fractal = NULL;
	data.julia_constant.zr = 0.0;
	data.julia_constant.zi = 0.0;
	data.origin = NULL;
	data.dest = NULL;
	data.psychedelic = 0;
	data.is_animating = 0;
	return (data);
}

void	ft_free_data(t_data *data)
{
	if (data->window)
	{
		mlx_destroy_window(data->mlx, data->window);
		data->window = NULL;
	}
	if (data->img.img)
	{
		mlx_destroy_image(data->mlx, data->img.img);
		data->img.img = NULL;
	}
	if (data->mlx)
	{
		mlx_destroy_display(data->mlx);
		free(data->mlx);
		data->mlx = NULL;
	}
	if (data->origin)
		free(data->origin);
	if (data->dest)
		free(data->dest);
	data->origin = NULL;
	data->dest = NULL;
}

int	ft_fractal_formula(t_complex *z, t_complex *c)
{
	double	tmp;

	tmp = z->zr * z->zr - z->zi * z->zi + c->zr;
	z->zi = 2 * z->zr * z->zi + c->zi;
	z->zr = tmp;
	return (1);
}

void	ft_init_fractal(t_fractal *fract, t_data *data)
{
	fract->y = 0;
	fract->x = 0;
	fract->iterations = 0;
	fract->scale = (4.0 / ULTRA_WIDTH) / data->zoom;
	fract->center_x = (ULTRA_WIDTH >> 1) + data->offset_x;
	fract->center_y = (ULTRA_HEIGHT >> 1) + data->offset_y;
}

void	ft_init_color(t_color *color)
{
	color->g = 0;
	color->b = 0;
	color->brightness = 0.0;
	color->cx = 0.0;
	color->cy = 0.0;
	color->dx = 0.0;
	color->dy = 0.0;
	color->dist = 0.0;
	color->t = 0.0;
	color->iter_t = 0.0;
	color->angle = 0.0;

}