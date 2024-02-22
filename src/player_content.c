/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_content.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inicole- <inicole-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 21:27:28 by inicole-          #+#    #+#             */
/*   Updated: 2023/11/17 01:03:24 by inicole-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	ft_set_angle_by_direction(t_player *player)
{
	if (player->player_char == 'N')
		player->rotation_angle = PI * 1.5;
	else if (player->player_char == 'S')
		player->rotation_angle = PI * 0.5;
	else if (player->player_char == 'W')
		player->rotation_angle = PI;
	else if (player->player_char == 'E')
		player->rotation_angle = PI * 2;
}

void	ft_init_player_position(char **map, t_player *player, t_cord cord)
{
	player->player_char = map[cord.y][cord.x];
	player->x = (double)(cord.x * 64) + 64 / 2;
	player->y = (double)(cord.y * 64) + 64 / 2;
	ft_set_angle_by_direction(player);
}

int	ft_check_player_cord(t_cord cord)
{
	return (cord.x >= 0 && cord.y >= 0);
}
