/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_vertical_coordinates.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oburato <oburato@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 22:13:06 by inicole-          #+#    #+#             */
/*   Updated: 2023/11/15 00:07:02 by oburato          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

double	get_y_vertical_intercept(t_player *player, double angle,
	double x_intercept)
{
	return (player->y + (x_intercept - player->x) * tan(angle));
}

double	get_x_vertical_intercept(t_player *player)
{
	return (floor(player->x / 64) * 64);
}

void	increment_x_vertical_intercept(double *x_intercept, double angle)
{
	if (ft_point_right(angle))
		*x_intercept += 64;
}
