/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atod.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarini <tarini@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 16:07:20 by tarini            #+#    #+#             */
/*   Updated: 2025/02/21 18:24:56 by tarini           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int	is_valid_number(const char *str, int dot_count, int i)
{
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (str[i] == '\0')
		return (EXIT_SUCCESS);
	while (str[i])
	{
		if (ft_isdigit(str[i]))
		{
			i++;
			continue ;
		}
		if (str[i] == '.')
		{
			if (dot_count == 0)
			{
				i++;
				dot_count++;
				continue ;
			}
		}
		return (EXIT_SUCCESS);
	}
	return (EXIT_FAILURE);
}

double	ft_atod(const char *str)
{
	int	dot_count;
	int	i;

	dot_count = 0;
	i = 0;
	if (!is_valid_number(str, dot_count, i))
	{
		ft_printf("Error : invalid enter.\n");
		exit(0);
	}
	return (atof(str));
}
