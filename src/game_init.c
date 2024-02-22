/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inicole- <inicole-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 16:09:26 by inicole-          #+#    #+#             */
/*   Updated: 2023/11/16 02:46:19 by inicole-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	init_mlx(t_cubd *cub3D)
{
	cub3D->mlx_ptr = mlx_init();
	if (cub3D->mlx_ptr == NULL)
		return (exit_with_message(1, "MLX Error"));
	cub3D->win_ptr = mlx_new_window(cub3D->mlx_ptr,
			1280, 645, "Cub3D");
	if (cub3D->win_ptr == NULL)
	{
		free(cub3D->mlx_ptr);
		return (exit_with_message(1, "MLX Error"));
	}
	return (0);
}

static void	init_game_variables(t_cubd *cub3D)
{
	cub3D->game->window = ft_get_window(&cub3D->map);
	cub3D->game->window.win_ptr = cub3D->win_ptr;
	cub3D->game->mlx_ptr = cub3D->mlx_ptr;
	cub3D->game->map = cub3D->map.matrix;
}

static void	init_colors(t_color *color)
{
	color->color_str = NULL;
	color->r = -1;
	color->g = -1;
	color->b = -1;
	color->alpha = 1;
}

static void	init_map(t_map *map)
{
	map->map_list = NULL;
	map->dimensions.columns = 0;
	map->dimensions.rows = 0;
	map->dimensions.col_offset = 0;
	map->matrix = NULL;
	map->map_file.name = NULL;
	map->map_file.fd = -2;
	map->so_file = NULL;
	map->no_file = NULL;
	map->we_file = NULL;
	map->ea_file = NULL;
	map->found_player = 0;
	init_colors(&map->floor_color);
	init_colors(&map->ceiling_color);
}

int	init_game(t_cubd *cub3D, char *argv[])
{
	cub3D->mlx_ptr = NULL;
	cub3D->win_ptr = NULL;
	init_map(&cub3D->map);
	init_player(cub3D);
	ft_read_and_validate_map(cub3D, argv[1]);
	init_mlx(cub3D);
	init_game_variables(cub3D);
	return (1);
}
