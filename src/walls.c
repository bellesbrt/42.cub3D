/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oburato <oburato@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 19:46:26 by inicole-          #+#    #+#             */
/*   Updated: 2023/11/15 00:55:55 by oburato          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	ft_wall_point(t_ray *ray)
{
	if (ray->has_hit_vertical && ft_point_right(ray->ray_angle))
		return (EA);
	else if (ray->has_hit_vertical && ft_point_left(ray->ray_angle))
		return (WE);
	else if (!ray->has_hit_vertical && ft_point_up(ray->ray_angle))
		return (NO);
	else if (!ray->has_hit_vertical && ft_point_right(ray->ray_angle))
		return (SO);
	return (0);
}

static void	draw_ceil(t_cubd *cub3d, int wall_top_pixel, int x)
{
	int	y;
	int	color;

	y = -1;
	color = rgb_to_hex(cub3d->map.ceiling_color);
	while (++y < wall_top_pixel)
		img_pix_put(&cub3d->img_game, x, y, color);
}

static void	draw_floor(t_cubd *cub3d, int wall_bottom_pixel, int x)
{
	int	y;
	int	color;

	y = wall_bottom_pixel;
	color = rgb_to_hex(cub3d->map.floor_color);
	while (++y < 645)
		img_pix_put(&cub3d->img_game, x, y, color);
}

static void	draw_walls(t_cubd *cub3d, int x, t_wall *wall)
{
	int	y;

	y = wall->wall_top_pixel;
	wall->wall_point = ft_wall_point(&cub3d->rays[x]);
	wall->wall_offset = ft_offset(&cub3d->rays[x]);
	while (y < wall->wall_bottom_pixel)
	{
		wall->dist_from_top = y + (wall->wall_height / 2) - (645 / 2);
		wall->text_offset_y = wall->dist_from_top
			*((double)cub3d->textures[wall->wall_point].height
				/ wall->wall_height);
		wall->color = get_color_pixel(cub3d, wall->wall_point,
				wall->wall_offset, wall->text_offset_y);
		if (cub3d->rays[x].has_hit_vertical)
			color_intensity(&wall->color, 0.6);
		img_pix_put(&cub3d->img_game, x, y, wall->color);
		y++;
	}
}

void	ft_draw_wall(t_cubd *cub3d)
{
	t_wall	wall;
	int		x;

	x = -1;
	while (++x < 1280)
	{
		wall.wall_height = (int)get_projected_wall_height(
				ft_perpendicular_distance(&cub3d->rays[x], cub3d->player),
				ft_projection_on_the_plane());
		wall.wall_top_pixel = ft_ceil_pixel(wall.wall_height);
		wall.wall_bottom_pixel = ft_floor_pixel(wall.wall_height);
		draw_ceil(cub3d, wall.wall_top_pixel, x);
		draw_walls(cub3d, x, &wall);
		draw_floor(cub3d, wall.wall_bottom_pixel, x);
	}
}
