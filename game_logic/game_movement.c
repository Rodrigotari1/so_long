/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_movement.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrigo <rodrigo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 12:35:30 by rodrigo           #+#    #+#             */
/*   Updated: 2025/01/12 19:17:29 by rodrigo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	update_position(t_complete *game, t_pos new, t_pos old)
{
	game->map[new.y][new.x] = 'P';
	game->map[old.y][old.x] = '0';
	game->x_axis = new.x;
	game->y_axis = new.y;
	game->counter++;
}

int	handle_move_to_position(t_complete *game, t_pos new, t_pos old)
{
	if (game->map[new.y][new.x] == 'E')
	{
		if (game->collectables == 0)
		{
			printf("\nVictory! You've completed the level!\n");
			exit_point(game);
		}
		return (0);
	}
	if (game->map[new.y][new.x] == '0' || game->map[new.y][new.x] == 'C')
	{
		if (game->map[new.y][new.x] == 'C')
			game->collectables--;
		update_position(game, new, old);
		return (1);
	}
	return (0);
}

int	handle_movement(t_complete *game, int dx, int dy)
{
	t_pos	new;
	t_pos	old;

	new.x = game->x_axis + dx;
	new.y = game->y_axis + dy;
	printf("Attempting move to: x=%d, y=%d (tile: %c)\n",
		new.x, new.y, game->map[new.y][new.x]);
	if (new.x < 0 || new.x >= game->widthmap
		|| new.y < 0 || new.y >= game->heightmap)
	{
		printf("Move blocked: Out of bounds\n");
		return (0);
	}
	if (game->map[new.y][new.x] == '1')
	{
		printf("Move blocked: Wall\n");
		return (0);
	}
	old.x = game->x_axis;
	old.y = game->y_axis;
	return (handle_move_to_position(game, new, old));
}
