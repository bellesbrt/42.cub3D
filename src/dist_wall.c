/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dist_wall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inicole- <inicole-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 19:40:16 by inicole-          #+#    #+#             */
/*   Updated: 2023/11/17 00:59:46 by inicole-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

double	ft_perpendicular_distance(t_ray *ray, t_player *player)
{
	return (ray->dist * cos(ray->ray_angle - player->rotation_angle));
}

double	ft_projection_on_the_plane(void)
{
	return ((1280 / 2) / tan(FOV_ANGLE / 2));
}

double	get_projected_wall_height(double perp_dist, double dist_project_plan)
{
	return ((64 / perp_dist) * dist_project_plan);
}

int	ft_ceil_pixel(int wall_strip_height)
{
	int	wall_top_pixel;

	wall_top_pixel = (645 / 2) - (wall_strip_height / 2);
	if (wall_top_pixel < 0)
		return (0);
	return (wall_top_pixel);
}

int	ft_floor_pixel(int wall_strip_height)
{
	int	wall_bottom_pixel;

	wall_bottom_pixel = (645 / 2) + (wall_strip_height / 2);
	if (wall_bottom_pixel > 645)
		return (645);
	return (wall_bottom_pixel);
}
