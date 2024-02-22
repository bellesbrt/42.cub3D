/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_loaders.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oburato <oburato@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 21:29:20 by inicole-          #+#    #+#             */
/*   Updated: 2023/11/14 23:48:22 by oburato          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	ft_set_rows_and_colums_vars(t_cubd *cub3D,
	t_map_dimensions *dim, t_list *h_list)
{
	int		map_width;
	int		fst_col_map;
	char	*line;
	int		total_rows;

	dim->columns = 0;
	dim->col_offset = INT_MAX;
	total_rows = ft_lstsize_no_new_line(h_list);
	while (h_list)
	{
		line = (char *)h_list->content;
		if (ft_is_new_line_in_list(h_list))
			exit_with_message_and_free(cub3D, 1, "Can only contain valid char");
		if (total_rows != dim->rows
			&& !ft_check_player_and_content(cub3D, line, total_rows
				== dim->rows + 1 || dim->rows == 0))
			exit_with_message_and_free(cub3D, 1, "Can only contain valid char");
		map_width = ft_str_trim_len(line);
		fst_col_map = ft_find_char_position(line);
		dim->columns = ft_delta(dim->columns, map_width, 1);
		dim->col_offset = ft_delta(dim->col_offset, fst_col_map, 0);
		h_list = h_list->next;
		if (!is_new_line(line))
			dim->rows = dim->rows + 1;
	}
}

static int	ft_copy_to_matrix(t_cubd *cub3D, t_list *h_list)
{
	int	index;

	index = 0;
	ft_set_rows_and_colums_vars(cub3D, &cub3D->map.dimensions, h_list);
	cub3D->map.matrix = (char **)
		malloc(sizeof(char *) * cub3D->map.dimensions.rows);
	while (index < cub3D->map.dimensions.rows)
	{
		cub3D->map.matrix[index] = (char *)
			malloc(sizeof(char) * cub3D->map.dimensions.columns + 1);
		ft_strclp_new_line(cub3D->map.matrix[index],
			((char *)h_list->content) + cub3D->map.dimensions.col_offset,
			cub3D->map.dimensions.columns + 1);
		h_list = h_list->next;
		index++;
	}
	return (1);
}

static int	ft_load_properties(t_cubd *cub3D, char *line, int *index)
{
	int	is_ok;

	ft_move_line_while_white_space(&line);
	is_ok = 1;
	if (ft_strncmp(line, "SO ", 3) == 0)
		set_texture_path(cub3D, &cub3D->map.so_file, line);
	else if (ft_strncmp(line, "NO ", 3) == 0)
		set_texture_path(cub3D, &cub3D->map.no_file, line);
	else if (ft_strncmp(line, "EA ", 3) == 0)
		set_texture_path(cub3D, &cub3D->map.ea_file, line);
	else if (ft_strncmp(line, "WE ", 3) == 0)
		set_texture_path(cub3D, &cub3D->map.we_file, line);
	else if (ft_strncmp(line, "F ", 2) == 0)
		set_floor_ceiling_color(cub3D, &cub3D->map.floor_color, line);
	else if (ft_strncmp(line, "C ", 2) == 0)
		set_floor_ceiling_color(cub3D, &cub3D->map.ceiling_color, line);
	else if (ft_strcmp(line, "\n") == 0 || !*line)
	{
		if (*index == 0)
			*index = -1;
		is_ok = 1;
	}
	else
		is_ok = 0;
	return (is_ok);
}

static int	ft_iterate_list(t_cubd *cub3D, t_list *h_list)
{
	char	*line;
	int		index;
	int		is_ok;

	index = 0;
	while (h_list)
	{
		line = (char *)h_list->content;
		if (ft_check_map_properties(cub3D) && ft_strcmp(line, "\n") == 0)
		{
			h_list = h_list->next;
			index++;
			continue ;
		}
		is_ok = ft_load_properties(cub3D, line, &index);
		if (index == 0 && !is_ok)
			exit_with_message_and_free(cub3D, 1,
				"Map must start with map properties");
		if (!is_ok && ft_check_map_properties(cub3D))
			return (ft_copy_to_matrix(cub3D, h_list));
		h_list = h_list->next;
		index++;
	}
	return (1);
}

void	ft_load_map(t_cubd *cub3D, t_list *h_list)
{
	t_cord	cord;

	ft_iterate_list(cub3D, h_list);
	if (ft_check_map_properties(cub3D) == 0)
		exit_with_message_and_free(cub3D, 1, "It's missing map property");
	if (ft_valid_wall(cub3D->map.matrix) == 0)
		exit_with_message_and_free(cub3D, 1, "Map must be surrounded by walls");
	if (cub3D->map.dimensions.rows <= 2 || cub3D->map.dimensions.columns <= 2)
		exit_with_message_and_free(cub3D, 1, "Map dimensions are not correct!");
	if (cub3D->map.found_player != 1)
		exit_with_message_and_free(cub3D, 1, "It must have one Player!");
	cord = ft_search_player_in_map(cub3D->map.matrix,
			&cub3D->map.dimensions);
	if (!ft_check_player_cord(cord))
		exit_with_message_and_free(cub3D, 1, "Player must be inside map!");
	ft_init_player_position(cub3D->map.matrix, cub3D->player, cord);
}
