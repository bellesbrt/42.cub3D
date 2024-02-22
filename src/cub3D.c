/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oburato <oburato@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 19:52:59 by inicole-          #+#    #+#             */
/*   Updated: 2023/11/12 14:57:13 by oburato          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	main(int argc, char *argv[])
{
	t_cubd	cubd;
	t_game	game;

	cubd.game = &game;
	if (!has_valid_args(argc))
		exit_with_message(1, "You must run cub3D with one map!");
	init_game(&cubd, argv);
	game_loop_events(&cubd);
	mlx_loop(cubd.mlx_ptr);
	return (0);
}
