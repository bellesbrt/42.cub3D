/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_matrix.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inicole- <inicole-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 15:30:59 by inicole-          #+#    #+#             */
/*   Updated: 2023/11/09 19:33:34 by inicole-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free_matrix(void ***matrix)
{
	size_t	row_index;
	size_t	col_index;

	row_index = 0;
	col_index = 0;
	if (!matrix || !matrix[row_index])
		return ;
	while (matrix[row_index][col_index])
	{
		ft_free_ptr((void **)&(matrix[row_index][col_index]));
		col_index++;
	}
	free(matrix[row_index]);
	matrix[row_index] = NULL;
}
