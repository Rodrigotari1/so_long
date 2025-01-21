/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_movement.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrigo <rodrigo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 12:35:30 by rodrigo           #+#    #+#             */
/*   Updated: 2025/01/21 01:06:17 by rodrigo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "../printf/ft_printf.h"

static void	update_position(t_complete *game, t_pos new, t_pos old)
{
	static char	last_tile = '0';

	if (game->map[new.y][new.x] == 'C')
		last_tile = '0';
	else
		last_tile = game->map[new.y][new.x];
	game->map[old.y][old.x] = last_tile;
	game->map[new.y][new.x] = 'P';
	game->x_axis = new.x;
	game->y_axis = new.y;
	game->counter++;
	adding_in_graphics(game);
}

int	handle_move_to_position(t_complete *game, t_pos new, t_pos old)
{
	char	target_tile;

	target_tile = game->map[new.y][new.x];
	if (target_tile == 'E')
	{
		if (game->collectables == 0)
		{
			ft_printf("Good stuff!\n");
			exit_point(game);
		}
	}
	if (target_tile == '0' || target_tile == 'C' || target_tile == 'E')
	{
		if (target_tile == 'C')
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
	if (new.x < 0 || new.x >= game->widthmap
		|| new.y < 0 || new.y >= game->heightmap)
		return (0);
	if (game->map[new.y][new.x] == '1')
		return (0);
	old.x = game->x_axis;
	old.y = game->y_axis;
	return (handle_move_to_position(game, new, old));
}
