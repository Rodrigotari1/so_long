/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrigo <rodrigo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 12:35:01 by rodrigo           #+#    #+#             */
/*   Updated: 2024/12/30 12:35:01 by rodrigo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int check_horizontal_walls(t_complete *game)
{
	int j;

	j = 0;
	while (j < game->widthmap)
	{
		if (!(game->map[0][j] == '1' && game->map[game->heightmap - 1][j] == '1'))
		{
			printf("Error\n");
			return (0);
		}
		j++;
	}
	return (1);
}

static int check_vertical_walls(t_complete *game)
{
	int height;

	height = 0;
	while (height < game->heightmap)
	{
		if (!(game->map[height][0] == '1' && 
			  game->map[height][game->widthmap - 1] == '1'))
		{
			printf("Error\n");
			return (0);
		}
		height++;
	}
	return (1);
}

static void validate_walls(t_complete *game)
{
	if (!check_vertical_walls(game) || !check_horizontal_walls(game))
	{
		printf("Error\n");
		exit_point(game);
	}
}

static void validate_tile(t_complete *game, int height, int width)
{
	char tile;
	char valid_chars[] = "01PCE\n";
	
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

void validate_map_characters(t_complete *game)
{
	int height;
	int width;

	if (!game->map)
	{
		printf("Error\n");
		exit(1);
	}

	height = 0;
	while (height < game->heightmap - 1)
	{
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
		height++;
	}

	if (!(game->playercount == 1 && game->columncount >= 1 && game->exitcount == 1))
	{
		printf("Error\n");
		exit_point(game);
	}
}

void check_errors(t_complete *game)
{
	validate_walls(game);
	validate_map_characters(game);
}
