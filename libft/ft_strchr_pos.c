/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr_pos.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inicole- <inicole-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 19:54:14 by inicole-          #+#    #+#             */
/*   Updated: 2023/11/09 19:36:19 by inicole-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strchr_pos(const char *s, int c)
{
	size_t	index;

	index = 0;
	while (*s != (char)c)
	{
		if (!*s)
			return (-1);
		s++;
		index++;
	}
	return (index);
}
