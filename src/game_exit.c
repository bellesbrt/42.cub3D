/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oburato <oburato@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 16:05:39 by inicole-          #+#    #+#             */
/*   Updated: 2023/11/15 20:58:28 by oburato          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	destroy_window(t_cubd *cub3D)
{
	if (cub3D->mlx_ptr == NULL && cub3D->win_ptr == NULL)
		return ;
	mlx_destroy_window(cub3D->mlx_ptr, cub3D->win_ptr);
	cub3D->win_ptr = NULL;
}

static void	destroy_display(t_cubd *cub3D)
{
	if (cub3D->mlx_ptr == NULL)
		return ;
	mlx_destroy_display(cub3D->mlx_ptr);
	ft_free_ptr((void **)&cub3D->mlx_ptr);
}

static void	clear_map(t_cubd *cub3D)
{
	ft_free_ptr((void **)&cub3D->map.ceiling_color.color_str);
	ft_free_ptr((void **)&cub3D->map.floor_color.color_str);
	ft_free_ptr((void **)&cub3D->map.we_file);
	ft_free_ptr((void **)&cub3D->map.so_file);
	ft_free_ptr((void **)&cub3D->map.ea_file);
	ft_free_ptr((void **)&cub3D->map.no_file);
	ft_lstclear(&cub3D->map.map_list, free);
	clear_matrix(cub3D);
}

void	game_clear(t_cubd *cub3D)
{
	clear_map(cub3D);
	clear_player(cub3D);
	destroy_window(cub3D);
	destroy_display(cub3D);
}

int	game_exit(t_cubd *cub3D)
{
	game_clear(cub3D);
	exit(0);
}
