/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oburato <oburato@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 16:27:42 by inicole-          #+#    #+#             */
/*   Updated: 2023/11/14 23:40:33 by oburato          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	set_file(t_file *file, char *file_path, char *extension)
{
	file->fd = ft_open_ext(file_path, extension);
	file->name = file_path;
}

static int	ft_is_file_extension(char *file_path, char *extension)
{
	char	*file_extension;

	file_extension = ft_strrchr(file_path, '.');
	if (!file_extension)
		return (0);
	return (ft_strcmp(file_extension, extension) == 0);
}

int	ft_open_ext(char *file_path, char *extension)
{
	int	fd;

	if (!ft_is_file_extension(file_path, extension))
		return (-2);
	fd = open(file_path, O_RDONLY);
	if (fd < 0)
		return (-2);
	return (fd);
}
