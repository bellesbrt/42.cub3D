/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oburato <oburato@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 21:52:05 by inicole-          #+#    #+#             */
/*   Updated: 2023/11/15 21:00:57 by oburato          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	img_pix_put(t_img *img, int x, int y, int color)
{
	char	*pixel;

	if (x < 0 || x >= 1280 || y < 0 || y >= 645)
		return ;
	pixel = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)pixel = color;
}

int	get_color_pixel(t_cubd *cub3d, int wall_point,
	int wall_offset, int text_offset_y)
{
	return (cub3d->textures[wall_point].color_buffer
		[cub3d->textures[wall_point].width * text_offset_y + wall_offset]);
}

int	rgb_to_hex(t_color color)
{
	return (color.alpha << 24 | color.r << 16 | color.g << 8 | color.b);
}

void	color_intensity(int *color, double factor)
{
	int	a;
	int	r;
	int	g;
	int	b;

	a = (*color & 0xFF000000);
	r = (*color & 0x00FF0000) * factor;
	g = (*color & 0x0000FF00) * factor;
	b = (*color & 0x000000FF) * factor;
	*color = a | (r & 0x00FF0000) | (g & 0x0000FF00) | (b & 0x000000FF);
}
