/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_replace_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oburato <oburato@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 16:07:45 by inicole-          #+#    #+#             */
/*   Updated: 2023/11/10 08:00:19 by oburato          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_advance_ptr(char **s, size_t len)
{
	while (len)
	{
		len--;
		(*s)++;
	}
}

void	ft_copy_char(char **new_str, char **to_copy)
{
	**new_str = **to_copy;
	(*to_copy)++;
	(*new_str)++;
}

void	ft_copy_str(char **new_str, char **to_copy)
{
	while (**to_copy)
		ft_copy_char(new_str, to_copy);
}

size_t	ft_load_strlen(size_t lens[3], char *s, char *to_find,
			char *to_replace)
{
	lens[0] = ft_strlen(to_replace);
	lens[1] = ft_strlen(to_find);
	lens[2] = ft_strlen(s);
	return (lens[2] - lens[1] + lens[0]);
}

char	*ft_replace_str(char *s, char *to_find, char *to_replace)
{
	char	*pos;
	size_t	lens[3];
	char	*new_str;
	size_t	new_len;

	if (!s || !to_find || !to_replace)
		return (s);
	pos = ft_strnstr(s, to_find, ft_strlen(s));
	new_len = ft_load_strlen(lens, s, to_find, to_replace);
	if (!pos)
		return (s);
	new_str = (char *)malloc(sizeof(char) * new_len + 1);
	while (*s)
	{
		if (s == pos)
		{
			ft_advance_ptr(&s, lens[1]);
			ft_copy_str(&new_str, &to_replace);
			if (!*s)
				break ;
		}
		ft_copy_char(&new_str, &s);
	}
	*new_str = '\0';
	return (new_str - new_len);
}
