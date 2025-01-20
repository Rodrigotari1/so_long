/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrigo <rodrigo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 12:35:01 by rodrigo           #+#    #+#             */
/*   Updated: 2025/01/20 19:46:00 by rodrigo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "../printf/ft_printf.h"

int	check_horizontal_walls(t_complete *game)
{
	int	j;

	j = 0;
	while (j < game->widthmap)
	{
		if (!(game->map[0][j] == '1' && game->map[game->heightmap - 1][j]
			== '1'))
		{
			ft_printf("Error\n");
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
			ft_printf("Error\n");
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
		ft_printf("Error\n");
		exit_point(game);
	}
}

int	error_message(char *message)
{
	ft_printf("%s", message);
	return (-1);
}
