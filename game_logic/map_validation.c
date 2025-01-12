/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrigo <rodrigo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 12:35:01 by rodrigo           #+#    #+#             */
/*   Updated: 2025/01/12 19:03:05 by rodrigo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	validate_tile(t_complete *game, int height, int width)
{
	char	tile;
	char	valid_chars[6];

	valid_chars[0] = '0';
	valid_chars[1] = '1';
	valid_chars[2] = 'P';
	valid_chars[3] = 'C';
	valid_chars[4] = 'E';
	valid_chars[5] = '\n';
	tile = game->map[height][width];
	if (!strchr(valid_chars, tile))
	{
		printf("Error\n");
		exit_point(game);
	}
	if (tile == 'C')
		game->columncount++;
	else if (tile == 'P')
		game->playercount++;
	else if (tile == 'E')
		game->exitcount++;
}

static void	check_map_content(t_complete *game)
{
	if (!(game->playercount == 1 && game->columncount >= 1
			&& game->exitcount == 1))
	{
		printf("Error\n");
		exit_point(game);
	}
}

static void	process_map_line(t_complete *game, int height)
{
	int	width;

	if (!game->map[height])
	{
		printf("Error\n");
		exit_point(game);
	}
	width = 0;
	while (width <= game->widthmap)
	{
		validate_tile(game, height, width);
		width++;
	}
}

void	validate_map_characters(t_complete *game)
{
	int	height;

	if (!game->map)
	{
		printf("Error\n");
		exit(1);
	}
	height = 0;
	while (height < game->heightmap - 1)
	{
		process_map_line(game, height);
		height++;
	}
	check_map_content(game);
}
