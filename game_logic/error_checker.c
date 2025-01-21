/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrigo <rodrigo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 12:35:01 by rodrigo           #+#    #+#             */
/*   Updated: 2025/01/21 15:44:39 by rodrigo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_errors(t_complete *game)
{
	validate_walls(game);
	validate_map_characters(game);
}

void	check_empty_map(t_complete *game)
{
	if (game->heightmap == 0)
	{
		ft_printf("Error\nEmpty map file\n");
		exit_point(game);
	}
}
