/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_horizontal_coordinates.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inicole- <inicole-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 22:08:54 by inicole-          #+#    #+#             */
/*   Updated: 2023/11/06 15:43:47 by inicole-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

double	get_y_horizontal_intercept(t_player *player)
{
	return (floor(player->y / 64) * 64);
}

double	get_x_horizontal_intercept(t_player *player,
	double angle, double y_intercept)
{
	return (player->x + (y_intercept - player->y) / tan(angle));
}

void	increment_y_horizontal_intercept(double *y_intercept, double angle)
{
	if (ft_point_down(angle))
		*y_intercept += 64;
}
