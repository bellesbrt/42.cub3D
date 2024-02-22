/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oburato <oburato@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 21:56:29 by inicole-          #+#    #+#             */
/*   Updated: 2023/11/15 21:06:33 by oburato          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	init_player(t_cubd *cub3d)
{
	cub3d->player = (t_player *)malloc(sizeof(t_player));
	cub3d->player->x = cub3d->game->window.width / 2;
	cub3d->player->y = cub3d->game->window.height / 2;
	cub3d->player->width = 1;
	cub3d->player->height = 1;
	cub3d->player->turn_direction = 0;
	cub3d->player->walk_direction = 0;
	cub3d->player->walk_side_direction = 0;
	cub3d->player->rotation_angle = (PI / 2);
	cub3d->player->walk_speed = 20;
	cub3d->player->turn_speed = 10 * (PI / 180);
}

static t_coordinates	npos(t_cubd *cub3d, double move_step, double side_step)
{
	t_coordinates	coords;

	coords.x = cub3d->player->x
		+(cos(cub3d->player->rotation_angle) * move_step)
		+(cos(cub3d->player->rotation_angle + PI / 2) * side_step);
	coords.y = cub3d->player->y
		+sin(cub3d->player->rotation_angle) * move_step
		+(sin(cub3d->player->rotation_angle + PI / 2) * side_step);
	return (coords);
}

static void	move_player(t_cubd *cub3d)
{
	double			move_step;
	double			side_step;
	t_coordinates	coords;

	if (cub3d->player->turn_direction)
	{
		cub3d->player->rotation_angle += cub3d->player->turn_direction
			* cub3d->player->turn_speed;
		normalize_angle(&cub3d->player->rotation_angle);
	}
	if (cub3d->player->walk_direction || cub3d->player->walk_side_direction)
	{
		move_step = cub3d->player->walk_direction * cub3d->player->walk_speed;
		side_step = cub3d->player->walk_side_direction
			* cub3d->player->walk_speed;
		coords.x = npos(cub3d, move_step, side_step).x;
		coords.y = npos(cub3d, move_step, side_step).y;
		if (ft_collision(cub3d->game->map, coords.x, coords.y, cub3d)
			|| coords.x <= (double)64)
			return ;
		cub3d->player->x = coords.x;
		cub3d->player->y = coords.y;
	}
}

int	key_down(int key, t_cubd *cub3d)
{
	if (key == 0xff1b)
		game_exit(cub3d);
	else if (key == 0x0077)
		cub3d->player->walk_direction = +1;
	else if (key == 0x0073)
		cub3d->player->walk_direction = -1;
	else if (key == 0xFF53)
		cub3d->player->turn_direction = +1;
	else if (key == 0xFF51)
		cub3d->player->turn_direction = -1;
	else if (key == 0x0061)
		cub3d->player->walk_side_direction = -1;
	else if (key == 0x0064)
		cub3d->player->walk_side_direction = +1;
	move_player(cub3d);
	game_render(cub3d);
	return (0);
}

int	key_up(int key, t_cubd *cub3d)
{
	if (key == 0x0077)
		cub3d->player->walk_direction = 0;
	else if (key == 0x0073)
		cub3d->player->walk_direction = 0;
	else if (key == 0xFF53)
		cub3d->player->turn_direction = 0;
	else if (key == 0xFF51)
		cub3d->player->turn_direction = 0;
	else if (key == 0x0061)
		cub3d->player->walk_side_direction = 0;
	else if (key == 0x0064)
		cub3d->player->walk_side_direction = 0;
	return (0);
}
