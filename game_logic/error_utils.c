/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrigo <rodrigo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 12:35:01 by rodrigo           #+#    #+#             */
/*   Updated: 2025/01/21 18:32:15 by rodrigo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"
#include "../printf/ft_printf.h"

void	check_errors(t_complete *game)
{
	if (!game)
	{
		ft_printf("Error\nInvalid game structure\n");
		exit(1);
	}
	check_map_dimensions(game);
	validate_walls(game);
	validate_map_characters(game);
}

void	check_empty_map(t_complete *game)
{
	if (!game || game->heightmap == 0)
	{
		ft_printf("Error\nEmpty map file\n");
		exit_point(game);
	}
}

int	error_message(char *message)
{
	if (!message)
		return (-1);
	ft_printf("%s\n", message);
	return (-1);
}
