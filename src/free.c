/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inicole- <inicole-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 16:05:44 by inicole-          #+#    #+#             */
/*   Updated: 2023/11/17 01:01:23 by inicole-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	close_fd(int fd)
{
	if (fd < 0)
		return ;
	close(fd);
}

void	clear_matrix(t_cubd *cub3D)
{
	int	index;

	if (cub3D->map.matrix == NULL)
		return ;
	index = 0;
	while (index < cub3D->map.dimensions.rows)
	{
		free(cub3D->map.matrix[index]);
		index++;
	}
	free(cub3D->map.matrix);
}

void	clear_player(t_cubd *cub3D)
{
	ft_free_ptr((void **)&cub3D->player);
}

void	destroy_textures(t_cubd *cub3D)
{
	mlx_destroy_image(cub3D->mlx_ptr, cub3D->textures[SO].mlx_img);
	mlx_destroy_image(cub3D->mlx_ptr, cub3D->textures[NO].mlx_img);
	mlx_destroy_image(cub3D->mlx_ptr, cub3D->textures[EA].mlx_img);
	mlx_destroy_image(cub3D->mlx_ptr, cub3D->textures[WE].mlx_img);
}
