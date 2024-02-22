/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_rays.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inicole- <inicole-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 22:13:55 by inicole-          #+#    #+#             */
/*   Updated: 2023/11/16 02:20:31 by inicole-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	cast_ray(t_cubd *cub3d, double ray_angle, int column)
{
	t_intersection	*intersec_horz;
	t_intersection	*intersec_vert;

	intersec_horz = malloc(sizeof(t_intersection));
	intersec_vert = malloc(sizeof(t_intersection));
	normalize_angle(&ray_angle);
	horizontal_intersection(cub3d, intersec_horz, ray_angle);
	calc_wall_hit(cub3d, intersec_horz, ray_angle, 1);
	vertical_intersection(cub3d, intersec_vert, ray_angle);
	calc_wall_hit(cub3d, intersec_vert, ray_angle, 0);
	if (intersec_horz->dist <= intersec_vert->dist)
		set_rays_horz(cub3d, intersec_horz, column, ray_angle);
	else
		set_rays_vert(cub3d, intersec_vert, column, ray_angle);
	ft_free_ptr((void **)&intersec_horz);
	ft_free_ptr((void **)&intersec_vert);
}

void	cast_all_rays(t_cubd *cub3d, t_player *player)
{
	double	ray_angle;
	int		column;

	ray_angle = player->rotation_angle - FOV_ANGLE / 2;
	column = 0;
	while (column < 1280)
	{
		cast_ray(cub3d, ray_angle, column);
		ray_angle += FOV_ANGLE / 1280;
		column++;
	}
}
