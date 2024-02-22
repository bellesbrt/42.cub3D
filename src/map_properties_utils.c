/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_properties_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oburato <oburato@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 21:30:50 by inicole-          #+#    #+#             */
/*   Updated: 2023/11/15 21:11:40 by oburato          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	ft_read_map(t_cubd *cub3D, int fd)
{
	char	*line;
	t_list	**h_list;

	h_list = &cub3D->map.map_list;
	while (1)
	{
		line = ft_get_next_line(fd);
		if (line == NULL)
			break ;
		ft_lstadd_back(h_list, ft_lstnew(line));
	}
	ft_load_map(cub3D, *h_list);
}

int	ft_read_and_validate_map(t_cubd *cub3D, char *map_file)
{
	set_file(&cub3D->map.map_file, map_file, ".cub");
	if (cub3D->map.map_file.fd < 0)
		exit_with_message_and_free(cub3D, 1, "File must have .cub");
	ft_read_map(cub3D, cub3D->map.map_file.fd);
	close_fd(cub3D->map.map_file.fd);
	return (0);
}

static char	*get_texture_path(t_cubd *cub3D, char *texture_path)
{
	char	*path;
	int		fd;

	if (!texture_path || ft_strlen(texture_path) < 4)
		exit_with_message_and_free(cub3D, 1, "Wrong texture file path or"
			" invalid extension (it must be .xpm)");
	path = ft_strtrim(texture_path + 3, " \t\r\n\v");
	if (!path)
	{
		ft_free_ptr((void **)&path);
		exit_with_message_and_free(cub3D, 1, "Wrong texture file path");
	}
	fd = ft_open_ext(path, ".xpm");
	if (fd < 0)
	{
		ft_free_ptr((void **)&path);
		exit_with_message_and_free(cub3D, 1, "Wrong texture file path");
	}
	close_fd(fd);
	return (path);
}

void	set_texture_path(t_cubd *cub3D, char **texture, char *texture_path)
{
	if (*texture)
		exit_with_message_and_free(cub3D, 1, "Duplicated map property!");
	*texture = get_texture_path(cub3D, texture_path);
}

void	set_floor_ceiling_color(t_cubd *cub3D, t_color *color, char *color_str)
{
	char	**colors_split;
	int		color_count;

	if (!color_str || ft_strlen(color_str) < 3)
		exit_with_message_and_free(cub3D, 1, "No color set!");
	color->color_str = ft_strtrim(color_str + 2, " \t\r\n\v");
	if (!color->color_str)
		exit_with_message_and_free(cub3D, 1, "No color set!");
	if (ft_count_char(color->color_str, ',') > 2)
		exit_with_message_and_free(cub3D, 1, "Color must be at RGB!");
	color_count = 0;
	colors_split = ft_split(color->color_str, ',');
	while (colors_split[color_count])
		color_count++;
	if (color_count != 3)
	{
		ft_free_matrix((void ***)&colors_split);
		exit_with_message_and_free(cub3D, 1, "Color must be at RGB!");
	}
	if (!ft_load_color_rgb(colors_split, color))
	{
		ft_free_matrix((void ***)&colors_split);
		exit_with_message_and_free(cub3D, 1, "Color must be at RGB!");
	}
	ft_free_matrix((void ***)&colors_split);
}
