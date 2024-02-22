/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdup_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inicole- <inicole-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 15:45:02 by inicole-          #+#    #+#             */
/*   Updated: 2023/11/09 19:34:53 by inicole-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstdup_int(t_list *list)
{
	t_list	*new;
	t_list	*temp;
	int		*content;

	new = 0;
	while (list)
	{
		content = (int *)malloc(sizeof(*content));
		if (!content)
			return (0);
		*content = *(int *)list->content;
		temp = ft_lstnew(content);
		if (!temp)
			return (0);
		ft_lstadd_back(&new, temp);
		list = list->next;
	}
	return (new);
}
