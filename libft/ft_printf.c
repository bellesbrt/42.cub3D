/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oburato <oburato@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 16:00:31 by inicole-          #+#    #+#             */
/*   Updated: 2023/11/12 15:33:44 by oburato          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	assign_specifiers(t_specifier *specifiers)
{
	*specifiers++ = ft_specifier_c;
	*specifiers++ = ft_specifier_s;
	*specifiers++ = ft_specifier_p;
	*specifiers++ = ft_specifier_d;
	*specifiers++ = ft_specifier_d;
	*specifiers++ = ft_specifier_u;
	*specifiers++ = ft_specifier_x;
	*specifiers++ = ft_specifier_upperx;
	*specifiers++ = ft_specifier_percent;
}

int	ft_printf(const char *format, ...)
{
	int			length;
	va_list		arg_ptr;
	t_specifier	specifiers[9];

	assign_specifiers(specifiers);
	length = 0;
	va_start(arg_ptr, format);
	while (*format)
	{
		if (*format == '%' && ft_strnchr(FORMATS, *(format +1)) != -1)
			length += specifiers[ft_strnchr(FORMATS, *(++format))](arg_ptr);
		else
		{
			ft_putchar(*format);
			length++;
		}
		format++;
	}
	va_end(arg_ptr);
	return (length);
}
