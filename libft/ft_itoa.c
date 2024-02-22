/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inicole- <inicole-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 15:40:23 by inicole-          #+#    #+#             */
/*   Updated: 2023/11/09 19:34:08 by inicole-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_declen(size_t n, size_t len)
{
	if (n > 9)
		return (ft_declen(n / 10, len + 1));
	return (len);
}

static void	ft_decstr(char *str, long n)
{
	if (n > 9)
		ft_decstr(str - 1, n / 10);
	*str = n % 10 + '0';
}

char	*ft_itoa(int n)
{
	char	*str;
	long	n_l;
	size_t	len;

	n_l = (long)n;
	if (n < 0)
		n_l = -n_l;
	len = ft_declen(n_l, 1);
	if (n < 0)
		len++;
	str = (char *) malloc (len * sizeof(char) + 1);
	if (!str)
		return (NULL);
	if (n < 0)
		*str = '-';
	ft_decstr(str + len -1, n_l);
	*(str + len) = '\0';
	return (str);
}
