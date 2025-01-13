/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_controller.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrigo <rodrigo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 12:35:30 by rodrigo           #+#    #+#             */
/*   Updated: 2025/01/13 16:14:39 by rodrigo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	handle_player_movement(t_complete *game, int new_x, int new_y)
{
	t_pos	new;
	t_pos	old;

	new.x = new_x;
	new.y = new_y;
	old.x = game->x_axis;
	old.y = game->y_axis;
	if (game->map[new.y][new.x] == 'E')
	{
		if (game->collectables != 0)
			return (0);
		printf("\nVictory! You've completed the level!\n");
		exit_point(game);
	}
	return (handle_move_to_position(game, new, old));
}

int	controls_working(int command, t_complete *game)
{
	int	success;

	success = 0;
	printf("Key pressed: %d\n", command);
	if (command == 65307)
		exit_point(game);
	if (command == 119)
		success = handle_movement(game, 0, -1);
	if (command == 115)
		success = handle_movement(game, 0, 1);
	if (command == 97)
		success = handle_movement(game, -1, 0);
	if (command == 100)
		success = handle_movement(game, 1, 0);
	if (success)
	{
		printf("Steps: %i | Collectables: %i\n",
			game->counter, game->collectables);
		printf("Position: x=%d, y=%d\n", game->x_axis, game->y_axis);
		adding_in_graphics(game);
	}
	return (1);
}
