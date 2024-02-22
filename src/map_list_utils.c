/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_list_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inicole- <inicole-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 21:33:06 by inicole-          #+#    #+#             */
/*   Updated: 2023/11/17 01:02:49 by inicole-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_move_line_while_white_space(char **line)
{
	while (**line && ft_strchr(" \t\r\n\v", **line))
		(*line)++;
}

void	ft_return_line_while_white_space(char *start_ptr, char **line)
{
	while (ft_strchr(" \t\r\n\v", **line))
	{
		if (*line == start_ptr)
			break ;
		(*line)--;
	}
}

int	is_new_line(char *line)
{
	return (line && ft_strcmp(line, "\n") == 0);
}

int	ft_lstsize_no_new_line(t_list *lst)
{
	int	size;

	size = 0;
	while (lst)
	{
		if (!is_new_line((char *)lst->content))
			size++;
		lst = lst->next;
	}
	return (size);
}
