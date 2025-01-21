/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_validation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtari-ca <rtari-ca@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 16:07:23 by rodrigo           #+#    #+#             */
/*   Updated: 2025/01/21 16:15:13 by rtari-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

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
