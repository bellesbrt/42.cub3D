/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inicole- <inicole-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 15:33:38 by inicole-          #+#    #+#             */
/*   Updated: 2023/11/09 19:33:47 by inicole-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_clean(char *buffer)
{
	size_t	i;
	char	*str;

	i = 0;
	while (buffer[i] != '\n')
		i++;
	ft_strlcpy(buffer, &buffer[i + 1], BUFFER_SIZE - i);
	if (!*buffer)
		return (NULL);
	str = malloc(sizeof(char) * (BUFFER_SIZE - i + 1));
	if (!str)
		return (NULL);
	ft_cpyline(str, buffer, 0);
	return (str);
}

static char	*ft_realloc(char *str, size_t len)
{
	char	*tmp;

	if (!str)
		str = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	else
	{
		tmp = (char *)malloc(sizeof(char) * (len + BUFFER_SIZE + 1));
		ft_strlcpy(tmp, str, len + 1);
		free(str);
		str = tmp;
	}
	if (!str)
		return (NULL);
	return (str);
}

static char	*ft_read(int fd, char *buffer, char *str)
{
	int		size;
	size_t	i;

	if (!str)
		i = 0;
	else
		i = ft_strlen(str);
	size = read(fd, buffer, BUFFER_SIZE);
	while (size)
	{
		if (size < 1)
			break ;
		buffer[size] = '\0';
		str = ft_realloc(str, i);
		i = ft_cpyline(str, buffer, i);
		if (ft_strchr(str, '\n'))
			break ;
		size = read(fd, buffer, BUFFER_SIZE);
	}
	if (size < 1 && !str)
		return (NULL);
	return (str);
}

char	*ft_get_next_line(int fd)
{
	char		*str;
	static char	buffer[BUFFER_SIZE + 1];

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	str = NULL;
	if (ft_strchr(buffer, '\n'))
	{
		str = ft_clean(buffer);
		if (ft_strchr(str, '\n'))
			return (str);
	}
	return (ft_read(fd, buffer, str));
}
