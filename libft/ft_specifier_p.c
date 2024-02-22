/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_specifier_p.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inicole- <inicole-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 19:45:21 by inicole-          #+#    #+#             */
/*   Updated: 2023/11/09 19:35:54 by inicole-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_specifier_p(va_list arg_ptr)
{
	char	*string;
	int		length;

	string = ft_utoa_base((va_arg(arg_ptr, unsigned long)), HEX);
	if (*string == '0')
	{
		ft_putstr("(nil)");
		free(string);
		return (5);
	}
	length = ft_strlen(string);
	if (string && *string)
		ft_putstr("0x");
	ft_putstr(string);
	if (string)
		free(string);
	return (2 + length);
}
