/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstat.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inicole- <inicole-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 15:42:22 by inicole-          #+#    #+#             */
/*   Updated: 2023/11/09 19:34:22 by inicole-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstat(t_list *list, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (i++ < n)
	{
		if (!list)
			break ;
		list = list->next;
	}
	return (list);
}
