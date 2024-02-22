/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cpyline.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inicole- <inicole-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 15:30:24 by inicole-          #+#    #+#             */
/*   Updated: 2023/11/09 19:33:06 by inicole-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_cpyline(char *dst, const char *src, size_t len)
{
	size_t	i;

	i = 0;
	while (src[i] != '\n' && src[i])
		dst[len++] = src[i++];
	if (src[i] == '\n')
		dst[len++] = '\n';
	dst[len] = '\0';
	return (len);
}
