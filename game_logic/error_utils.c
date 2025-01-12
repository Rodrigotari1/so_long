/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrigo <rodrigo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 12:35:01 by rodrigo           #+#    #+#             */
/*   Updated: 2025/01/12 19:04:43 by rodrigo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_horizontal_walls(t_complete *game)
{
	int	j;

	j = 0;
	while (j < game->widthmap)
	{
		if (!(game->map[0][j] == '1' && game->map[game->heightmap - 1][j]
			== '1'))
		{
			printf("Error\n");
			return (0);
		}
		j++;
	}
	return (1);
}

int	check_vertical_walls(t_complete *game)
{
	int	height;

	height = 0;
	while (height < game->heightmap)
	{
		if (!(game->map[height][0] == '1'
			&& game->map[height][game->widthmap - 1] == '1'))
		{
			printf("Error\n");
			return (0);
		}
		height++;
	}
	return (1);
}

void	validate_walls(t_complete *game)
{
	if (!check_vertical_walls(game) || !check_horizontal_walls(game))
	{
		printf("Error\n");
		exit_point(game);
	}
}
