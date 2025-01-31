/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fractol.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarini <tarini@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 11:20:59 by tarini            #+#    #+#             */
/*   Updated: 2025/01/30 11:13:58 by tarini           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	main(void)
{
	void    *mlx;
	void    *window;

	mlx = mlx_init();
	window = mlx_new_window(mlx, 1000, 1000, "TheMap");
	mlx_loop(mlx);
	return (0);
}
