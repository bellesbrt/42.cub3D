/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   invert_direction.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inicole- <inicole-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 22:12:11 by inicole-          #+#    #+#             */
/*   Updated: 2023/11/16 02:18:13 by inicole-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_invert_y_horizontal(double *y_step, double angle)
{
	if (ft_point_up(angle))
		*y_step *= -1;
}

void	ft_invert_y_vertical(double *y_step, double angle)
{
	if ((ft_point_up(angle) && *y_step > 0)
		|| (ft_point_down(angle) && *y_step < 0))
		*y_step *= -1;
}

void	ft_invert_x_horizontal(double *x_step, double angle)
{
	if ((ft_point_left(angle) && *x_step > 0)
		|| (ft_point_right(angle) && *x_step < 0))
		*x_step *= -1;
}

void	ft_invert_x_vertical(double *x_step, double angle)
{
	if (ft_point_left(angle))
		*x_step *= -1;
}
