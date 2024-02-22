/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oburato <oburato@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 21:57:38 by inicole-          #+#    #+#             */
/*   Updated: 2023/11/15 00:01:07 by oburato          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	ft_collision(char **map, double new_x, double new_y, t_cubd *cub3d)
{
	int	x;
	int	y;

	if (!is_inside_map(cub3d->game->window, new_x, new_y))
		return (1);
	x = (int)floor((new_x / 64));
	y = (int)floor((new_y / 64));
	if (x >= cub3d->map.dimensions.columns - 1
		|| y >= cub3d->map.dimensions.rows - 1)
		return (1);
	return (map[y][x] == '1');
}

int	is_inside_map(t_window window, double new_x, double new_y)
{
	return (new_x >= 0 && new_x <= window.width
		&& new_y >= 0 && new_y <= window.height);
}

void	normalize_angle(double *angle)
{
	*angle = remainder(*angle, TWO_PI);
	if (*angle < 0)
		*angle = TWO_PI + *angle;
}
