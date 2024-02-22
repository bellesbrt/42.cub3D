/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inicole- <inicole-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 01:00:17 by inicole-          #+#    #+#             */
/*   Updated: 2023/11/17 01:00:21 by inicole-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	print_error(char *message)
{
	ft_printf("%s\n%s\n", "Error", message);
}

int	exit_with_message(int status_code, char *message)
{
	print_error(message);
	exit(status_code);
}

int	has_valid_args(int argc)
{
	if (argc != 2)
		return (0);
	return (1);
}

void	exit_with_message_and_free(t_cubd *cub3d,
	int status_code, char *message)
{
	game_clear(cub3d);
	exit_with_message(status_code, message);
}
