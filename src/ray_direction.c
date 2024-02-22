/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_direction.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inicole- <inicole-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 22:19:33 by inicole-          #+#    #+#             */
/*   Updated: 2023/11/17 01:03:54 by inicole-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	ft_point_down(double angle)
{
	return (angle > 0 && angle < PI);
}

int	ft_point_up(double angle)
{
	return (!ft_point_down(angle));
}

int	ft_point_right(double angle)
{
	return (angle < 0.5 * PI || angle > 1.5 * PI);
}

int	ft_point_left(double angle)
{
	return (!ft_point_right(angle));
}
