/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inicole- <inicole-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 21:33:55 by inicole-          #+#    #+#             */
/*   Updated: 2023/11/17 01:04:12 by inicole-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

size_t	ft_str_trim_len(char *str)
{
	char	*tstr;
	size_t	len;

	if (!str)
		return (0);
	tstr = ft_strtrim(str, " \t\r\n\v");
	len = ft_strlen(tstr);
	ft_free_ptr((void **)&tstr);
	return (len);
}

size_t	ft_find_char_position(char *str)
{
	size_t	index;

	index = 0;
	while (*str)
	{
		if (ft_strchr("01NSEW", *str))
			break ;
		str++;
		index++;
	}
	return (index);
}

size_t	ft_strclp_new_line(char *dst, const char *src, size_t size)
{
	size_t	src_len;
	size_t	index;
	size_t	original_size;

	src_len = ft_strlen(src);
	original_size = size;
	if (size == 0)
		return (src_len);
	index = 0;
	while (src[index] && (index < size - 1)
		&& src[index] != '\n')
	{
		dst[index] = src[index];
		index++;
	}
	while (index < size - 1)
	{
		dst[index] = ' ';
		index++;
	}
	dst[original_size - 1] = '\0';
	return (src_len);
}

int	ft_is_new_line_in_list(t_list *h_list)
{
	char	*line;

	line = (char *)h_list->content;
	if (!is_new_line(line))
		return (0);
	while (h_list)
	{
		line = (char *)h_list->content;
		while (*line)
		{
			if (!ft_strchr(" \t\r\n\v", *line))
				return (1);
			line++;
		}
		h_list = h_list->next;
	}
	return (0);
}

int	ft_delta(int current, int next, int delta)
{
	if (delta)
	{
		if (current < next)
			current = next;
		return (current);
	}
	if (current > next)
		current = next;
	return (current);
}
