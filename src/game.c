/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oburato <oburato@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 15:58:13 by inicole-          #+#    #+#             */
/*   Updated: 2023/11/15 21:10:05 by oburato          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	game_loop_events(t_cubd *cub3D)
{
	mlx_expose_hook(cub3D->win_ptr, &game_render, cub3D);
	mlx_hook(cub3D->win_ptr, 3, 1L << 1, &key_up, cub3D);
	mlx_hook(cub3D->win_ptr, 2, 1L << 0, &key_down, cub3D);
	mlx_hook(cub3D->win_ptr, 17, 1L << 17, &game_exit, cub3D);
}

int	game_render(t_cubd *cub3D)
{
	init_textures(cub3D);
	create_img(cub3D, &cub3D->img_game, 1280, 645);
	cast_all_rays(cub3D, cub3D->player);
	ft_draw_wall(cub3D);
	render_img_to_window(cub3D, &cub3D->img_game, 0, 0);
	mlx_destroy_image(cub3D->mlx_ptr, cub3D->img_game.mlx_img);
	destroy_textures(cub3D);
	return (1);
}

t_window	ft_get_window(t_map *map)
{
	t_window	window;

	window.width = map->dimensions.columns * 64;
	window.height = map->dimensions.rows * 64;
	return (window);
}
