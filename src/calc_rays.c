/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_rays.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inicole- <inicole-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 22:11:32 by inicole-          #+#    #+#             */
/*   Updated: 2023/11/09 18:36:02 by inicole-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	increment_steps(t_intersection *intersec)
{
	intersec->next_x += intersec->x_step;
	intersec->next_y += intersec->y_step;
}

static void	set_found_wall_hit(t_intersection *intersec)
{
	intersec->wall_hit_x = intersec->next_x;
	intersec->wall_hit_y = intersec->next_y;
}

static void	set_next_start_position(t_intersection *intersec)
{
	intersec->next_x = intersec->x_intercept;
	intersec->next_y = intersec->y_intercept;
}

static void	set_to_check(t_intersection *intersec, double angle, int is_horz)
{
	intersec->x_to_check = intersec->next_x;
	intersec->y_to_check = intersec->next_y;
	if (is_horz)
	{
		if (ft_point_up(angle))
			intersec->y_to_check -= 1;
	}
	else
	{
		if (ft_point_left(angle))
			intersec->x_to_check -= 1;
	}
}

void	calc_wall_hit(t_cubd *cub3d,
	t_intersection *intersec, double ray_angle, int is_horz)
{
	set_next_start_position(intersec);
	intersec->dist = INT_MAX;
	while (is_inside_map(cub3d->game->window,
			intersec->next_x, intersec->next_y))
	{
		set_to_check(intersec, ray_angle, is_horz);
		if (ft_collision(cub3d->game->map,
				intersec->x_to_check, intersec->y_to_check, cub3d))
		{
			set_found_wall_hit(intersec);
			intersec->dist = ft_dist_between_points(
					cub3d->player->x,
					cub3d->player->y,
					intersec->wall_hit_x,
					intersec->wall_hit_y);
			break ;
		}
		else
			increment_steps(intersec);
	}
}
