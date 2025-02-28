/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_formula_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarini <tarini@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 17:23:04 by tarini            #+#    #+#             */
/*   Updated: 2025/02/27 17:59:30 by tarini           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

int	ft_fractal_formula(t_complex *z, t_complex *c)
{
	double	tmp;

	tmp = z->zr * z->zr - z->zi * z->zi + c->zr;
	z->zi = 2 * z->zr * z->zi + c->zi;
	z->zr = tmp;
	return (1);
}
