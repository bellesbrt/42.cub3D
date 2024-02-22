/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_specifier_upperx.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inicole- <inicole-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 19:51:33 by inicole-          #+#    #+#             */
/*   Updated: 2023/11/09 19:36:12 by inicole-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_specifier_upperx(va_list arg_ptr)
{
	char	*string;
	int		length;
	int		i;

	i = -1;
	string = ft_utoa_base(va_arg(arg_ptr, unsigned int), HEX);
	length = ft_strlen(string);
	while (string[++i])
	{
		if (string[i] >= 'a' && string[i] <= 'z')
			string[i] -= 32;
	}
	ft_putstr(string);
	if (string)
		free(string);
	return (length);
}
