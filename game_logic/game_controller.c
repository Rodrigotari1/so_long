/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_controller.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrigo <rodrigo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 12:35:30 by rodrigo           #+#    #+#             */
/*   Updated: 2024/12/30 12:35:30 by rodrigo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int handle_player_movement(t_complete *game, int new_x, int new_y)
{
	int old_x;
	int old_y;

	old_x = game->x_axis;
	old_y = game->y_axis;

	if (game->map[new_y][new_x] == 'E')
	{
		if (game->collectables != 0)
			return (0);
		printf("\nVictory! You've completed the level!\n");
		exit_point(game);
	}
	if (game->map[new_y][new_x] == '0' || game->map[new_y][new_x] == 'C')
	{
		if (game->map[new_y][new_x] == 'C')
			game->collectables--;
			
		game->map[new_y][new_x] = 'P';
		game->map[old_y][old_x] = '0';
		game->x_axis = new_x;
		game->y_axis = new_y;
		game->counter++;
		return (1);
	}
	return (0);
}

static int handle_movement(t_complete *game, int dx, int dy)
{
	int new_x;
	int new_y;

	new_x = game->x_axis + dx;
	new_y = game->y_axis + dy;

	if (new_x < 0 || new_x >= game->widthmap || 
		new_y < 0 || new_y >= game->heightmap)
		return (0);
	if (game->map[new_y][new_x] == '1')
		return (0);
	return (handle_player_movement(game, new_x, new_y));
}

int controls_working(int command, t_complete *game)
{
	int success;

	success = 0;
	if (command == 53)  // ESC
		exit_point(game);
	else if (command == 13)  // W
		success = handle_movement(game, 0, -1);
	else if (command == 1)   // S
		success = handle_movement(game, 0, 1);
	else if (command == 0)   // A
		success = handle_movement(game, -1, 0);
	else if (command == 2)   // D
		success = handle_movement(game, 1, 0);

	if (success)
	{
		printf("Steps: %i | Collectables: %i\n", game->counter, game->collectables);
		adding_in_graphics(game);
	}
	return (1);
}
