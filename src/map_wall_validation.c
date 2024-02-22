/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_wall_validation.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inicole- <inicole-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 21:29:20 by inicole-          #+#    #+#             */
/*   Updated: 2023/11/17 01:03:16 by inicole-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	ft_valid_char_in_map(char N, char S, char E, char W)
{
	if (ft_strchr("01NSWE", N) == NULL)
		return (1);
	if (ft_strchr("01NSWE", S) == NULL)
		return (1);
	if (ft_strchr("01NSWE", E) == NULL)
		return (1);
	if (ft_strchr("01NSWE", W) == NULL)
		return (1);
	return (0);
}

static int	ft_valid_wall_border(char N, char S, char E, char W)
{
	if (ft_strchr("01", N) == NULL)
		return (1);
	if (ft_strchr("01", S) == NULL)
		return (1);
	if (ft_strchr("01", E) == NULL)
		return (1);
	if (ft_strchr("01", W) == NULL)
		return (1);
	return (0);
}

static int	ft_check_propertys(char **matrix, int i, int j)
{
	if (matrix[i][j] == '0')
	{
		if (ft_valid_char_in_map(matrix[i][j + 1],
			matrix[i][j - 1], matrix[i + 1][j],
			matrix[i - 1][j]))
			return (0);
	}
	if (ft_strchr("NSWE", matrix[i][j]) != NULL)
	{
		if (ft_valid_wall_border(matrix[i][j + 1],
			matrix[i][j - 1], matrix[i + 1][j],
			matrix[i - 1][j]))
			return (0);
	}
	return (1);
}

int	ft_valid_wall(char **matrix)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (!matrix[i])
	{
		while (matrix[i][j])
		{
			if (ft_check_propertys(matrix, i, j) == 0)
				return (0);
			j++;
		}
		j = 0;
		i++;
	}
	return (1);
}
