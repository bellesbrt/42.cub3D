/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inicole- <inicole-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 15:59:17 by inicole-          #+#    #+#             */
/*   Updated: 2023/11/09 19:35:10 by inicole-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*buf;

	if (dest == src || !n)
		return (dest);
	buf = (char *)dest;
	while (n--)
		*(char *)dest++ = *(char *)src++;
	return (buf);
}
