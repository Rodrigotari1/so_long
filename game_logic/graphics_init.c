/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtari-ca <rtari-ca@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 23:00:00 by rtari-ca          #+#    #+#             */
/*   Updated: 2025/01/21 18:32:15 by rtari-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

static void	load_floor_and_wall(t_complete *game)
{
	int	width;
	int	height;

	game->floor = mlx_xpm_file_to_image(game->mlxpointer,
			"game_images/floor.xpm", &width, &height);
	if (!game->floor)
	{
		free_textures(game);
		exit_point(game);
	}
	game->barrier = mlx_xpm_file_to_image(game->mlxpointer,
			"game_images/wall.xpm", &width, &height);
	if (!game->barrier)
		exit_point(game);
}

static void	load_player_and_exit(t_complete *game)
{
	int	width;
	int	height;

	game->player = mlx_xpm_file_to_image(game->mlxpointer,
			"game_images/player.xpm", &width, &height);
	if (!game->player)
		exit_point(game);
	game->exit = mlx_xpm_file_to_image(game->mlxpointer,
			"game_images/exit.xpm", &width, &height);
	if (!game->exit)
		exit_point(game);
}

static void	load_game_textures(t_complete *game)
{
	int	width;
	int	height;

	load_floor_and_wall(game);
	load_player_and_exit(game);
	game->collectable = mlx_xpm_file_to_image(game->mlxpointer,
			"game_images/item.xpm", &width, &height);
	if (!game->collectable)
		exit_point(game);
}

void	place_images_in_game(t_complete *game)
{
	load_game_textures(game);
} 