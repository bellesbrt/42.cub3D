/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inicole- <inicole-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 21:31:51 by inicole-          #+#    #+#             */
/*   Updated: 2023/11/17 01:02:14 by inicole-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	ft_check_map_properties(t_cubd *cub3D)
{
	return (cub3D->map.so_file && cub3D->map.no_file && cub3D->map.ea_file
		&& cub3D->map.we_file && cub3D->map.floor_color.color_str
		&& cub3D->map.ceiling_color.color_str);
}

static int	ft_valid_color_rgb(int color_atoi, char *color_str)
{
	char	*color_trimmed;
	int		is_valid;

	is_valid = 1;
	if (color_atoi < 0)
		return (0);
	color_trimmed = ft_strtrim(color_str, " \t\r\n\v");
	if (color_atoi == 0 && ft_strcmp(color_trimmed, "0") != 0)
		is_valid = 0;
	else if (!(color_atoi >= 0 && color_atoi <= 255))
		is_valid = 0;
	else if (!ft_is_all_something(color_trimmed, ft_isdigit))
		is_valid = 0;
	ft_free_ptr((void **)&color_trimmed);
	return (is_valid);
}

static int	ft_valid_colors(t_color *color, char **colors_split)
{
	return (ft_valid_color_rgb(color->r, colors_split[0])
		&& ft_valid_color_rgb(color->g, colors_split[1])
		&& ft_valid_color_rgb(color->b, colors_split[2]));
}

int	ft_load_color_rgb(char **colors_split, t_color *color)
{
	color->r = ft_atoi(colors_split[0]);
	color->g = ft_atoi(colors_split[1]);
	color->b = ft_atoi(colors_split[2]);
	return (ft_valid_colors(color, colors_split));
}
