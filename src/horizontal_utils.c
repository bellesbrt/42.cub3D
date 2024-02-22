/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   horizontal_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inicole- <inicole-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 22:18:36 by inicole-          #+#    #+#             */
/*   Updated: 2023/11/16 02:17:50 by inicole-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	set_horz_intersects(t_cubd *cub3d,
	t_intersection *intersec, double ray_angle)
{
	intersec->y_intercept = get_y_horizontal_intercept(cub3d->player);
	increment_y_horizontal_intercept(&intersec->y_intercept, ray_angle);
	intersec->x_intercept = get_x_horizontal_intercept(cub3d->player,
			ray_angle, intersec->y_intercept);
}

static void	set_horz_steps(t_intersection *intersec, double ray_angle)
{
	intersec->y_step = 64;
	ft_invert_y_horizontal(&intersec->y_step, ray_angle);
	intersec->x_step = 64 / tan(ray_angle);
	ft_invert_x_horizontal(&intersec->x_step, ray_angle);
}

void	horizontal_intersection(t_cubd *cub3d,
	t_intersection *intersec, double ray_angle)
{
	set_horz_intersects(cub3d, intersec, ray_angle);
	set_horz_steps(intersec, ray_angle);
}

void	set_rays_horz(t_cubd *cub3d,
	t_intersection *intersec, int column, double angle)
{
	cub3d->rays[column].dist = intersec->dist;
	cub3d->rays[column].wall_hit_x = intersec->wall_hit_x;
	cub3d->rays[column].wall_hit_y = intersec->wall_hit_y;
	cub3d->rays[column].ray_angle = angle;
	cub3d->rays[column].has_hit_vertical = 0;
}

int	ft_offset(t_ray *ray)
{
	if (ray->has_hit_vertical)
		return ((int)ray->wall_hit_y % 64);
	return ((int)ray->wall_hit_x % 64);
}
