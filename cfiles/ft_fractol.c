/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fractol.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarini <tarini@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 11:20:59 by tarini            #+#    #+#             */
/*   Updated: 2025/01/31 20:22:25 by tarini           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"
#include "../libft/includes/libft.h"

void ft_free_tab(t_type *data)
{
    if (data->window && data->mlx)
	    mlx_destroy_window(data->mlx, data->window);
    if (data->mlx)
	{
		mlx_destroy_display(data->mlx);
        free(data->mlx);
	}
}

t_type ft_init_data()
{
    t_type	data;
	
    data.mlx = NULL;
    data.window = NULL;
    return data;
}

int	ft_stop(int keysym, t_type *data)
{
    if (keysym == 65307)
    {
        ft_free_tab(data);
        exit(0);
    }
    return (1);
}

int	main(void)
{
    t_type	data;

    data = ft_init_data();
    data.mlx = mlx_init();
    if (!data.mlx)
        return (1);
    data.window = mlx_new_window(data.mlx, 1000, 1000, "TheMap");
    if (!data.window)
        return (ft_free_tab(&data), 1);
    mlx_key_hook(data.window, (int (*)(int, void *))ft_stop, &data);
    mlx_loop(data.mlx);
    return (0);
}
