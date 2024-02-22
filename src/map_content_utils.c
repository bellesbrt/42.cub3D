/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_content_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oburato <oburato@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 16:28:51 by inicole-          #+#    #+#             */
/*   Updated: 2023/11/14 19:14:21 by oburato          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	ft_check_first_last_line(char *line)
{
	ft_move_line_while_white_space(&line);
	while (*line)
	{
		if (*line != '1' && *line != ' ')
			break ;
		line++;
	}
	ft_move_line_while_white_space(&line);
	if (*line)
		return (0);
	return (1);
}

int	ft_check_player_and_content(t_cubd *cub3D, char *line,
	int is_first_or_last_row)
{
	char	*start_line;

	start_line = line;
	if (is_first_or_last_row)
		return (ft_check_first_last_line(line));
	ft_move_line_while_white_space(&line);
	if (*line != '1')
		return (0);
	while (*line)
	{
		if (ft_strchr("NSEW", *line))
			cub3D->map.found_player += 1;
		if (ft_strchr("01NSEW \t\r\v", *line) == NULL && *line != '\n')
			return (0);
		line++;
	}
	ft_return_line_while_white_space(start_line, &line);
	if (*line != '1')
		return (0);
	return (1);
}

static int	ft_is_wall_or_floor(char map_char)
{
	return (map_char == '1' || map_char == '0');
}

static t_cord	ft_search_player(char **map, t_map_dimensions *dim)
{
	t_cord	cord;

	cord.y = 0;
	while (cord.y < dim->rows)
	{
		cord.x = 0;
		while (cord.x < dim->columns && map[cord.y][cord.x])
		{
			if (ft_strchr("NSEW", map[cord.y][cord.x]))
				return (cord);
			cord.x++;
		}
		cord.y++;
	}
	return ((t_cord){-1, -1});
}

t_cord	ft_search_player_in_map(char **map, t_map_dimensions *dim)
{
	int		x;
	int		y;
	t_cord	cord;

	cord = ft_search_player(map, dim);
	if (cord.x == -1 && cord.y == -1)
		return ((t_cord){-1, -1});
	y = cord.y;
	x = cord.x;
	if (!ft_is_wall_or_floor(map[y - 1][x])
		|| !ft_is_wall_or_floor(map[y][x - 1])
		|| !ft_is_wall_or_floor(map[y][x + 1])
		|| !ft_is_wall_or_floor(map[y + 1][x]))
		return ((t_cord){-1, -1});
	return (cord);
}
