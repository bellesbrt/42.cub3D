/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   imgs.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inicole- <inicole-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 16:11:38 by inicole-          #+#    #+#             */
/*   Updated: 2023/11/17 01:01:52 by inicole-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	init_texture(t_cubd *cub3d, t_img *img, char *path)
{
	img->mlx_img = mlx_xpm_file_to_image(cub3d->mlx_ptr, path,
			&img->width, &img->height);
	img->color_buffer = (int *)mlx_get_data_addr(img->mlx_img,
			&img->bits_per_pixel, &img->line_length, &img->endian);
}

void	init_textures(t_cubd *cub3d)
{
	init_texture(cub3d, &cub3d->textures[SO], cub3d->map.so_file);
	init_texture(cub3d, &cub3d->textures[NO], cub3d->map.no_file);
	init_texture(cub3d, &cub3d->textures[WE], cub3d->map.we_file);
	init_texture(cub3d, &cub3d->textures[EA], cub3d->map.ea_file);
}

void	create_img(t_cubd *cub3d, t_img *img, int width, int height)
{
	img->mlx_img = mlx_new_image(cub3d->mlx_ptr, width, height);
	img->addr = mlx_get_data_addr(
			img->mlx_img,
			&img->bits_per_pixel,
			&img->line_length,
			&img->endian);
}

void	render_img_to_window(t_cubd *cub3d, t_img *img, int x, int y)
{
	mlx_put_image_to_window(
		cub3d->mlx_ptr,
		cub3d->win_ptr,
		img->mlx_img,
		x, y);
}
