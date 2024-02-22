/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vertical_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inicole- <inicole-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 19:36:10 by inicole-          #+#    #+#             */
/*   Updated: 2023/11/16 02:18:13 by inicole-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	set_vert_intersects(t_cubd *cub3d,
	t_intersection *intersec, double ray_angle)
{
	intersec->x_intercept = get_x_vertical_intercept(cub3d->player);
	increment_x_vertical_intercept(&intersec->x_intercept, ray_angle);
	intersec->y_intercept = get_y_vertical_intercept(
			cub3d->player,
			ray_angle,
			intersec->x_intercept);
}

static void	set_vertical_steps(t_intersection *intersec, double ray_angle)
{
	intersec->x_step = 64;
	ft_invert_x_vertical(&intersec->x_step, ray_angle);
	intersec->y_step = 64 * tan(ray_angle);
	ft_invert_y_vertical(&intersec->y_step, ray_angle);
}

void	vertical_intersection(t_cubd *cub3d,
	t_intersection *intersec, double ray_angle)
{
	set_vert_intersects(cub3d, intersec, ray_angle);
	set_vertical_steps(intersec, ray_angle);
}

void	set_rays_vert(t_cubd *cub3d,
	t_intersection *intersec, int column, double angle)
{
	cub3d->rays[column].dist = intersec->dist;
	cub3d->rays[column].wall_hit_x = intersec->wall_hit_x;
	cub3d->rays[column].wall_hit_y = intersec->wall_hit_y;
	cub3d->rays[column].ray_angle = angle;
	cub3d->rays[column].has_hit_vertical = 1;
}

double	ft_dist_between_points(double x1, double y1, double x2, double y2)
{
	return (sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1)));
}
