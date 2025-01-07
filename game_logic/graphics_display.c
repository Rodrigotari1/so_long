/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics_display.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrigo <rodrigo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 23:00:00 by rtari-ca          #+#    #+#             */
/*   Updated: 2024/12/19 17:11:45 by rodrigo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	load_game_textures(t_complete *game)
{
	int	width;
	int	height;

	game->floor = mlx_xpm_file_to_image(game->mlxpointer,
			"game_images/floor.xpm", &width, &height);
	if (!game->floor)
		exit_point(game);
	game->barrier = mlx_xpm_file_to_image(game->mlxpointer,
			"game_images/wall.xpm", &width, &height);
	if (!game->barrier)
		exit_point(game);
	game->player = mlx_xpm_file_to_image(game->mlxpointer,
			"game_images/player.xpm", &width, &height);
	if (!game->player)
		exit_point(game);
	game->exit = mlx_xpm_file_to_image(game->mlxpointer,
			"game_images/exit.xpm", &width, &height);
	if (!game->exit)
		exit_point(game);
	game->collectable = mlx_xpm_file_to_image(game->mlxpointer,
			"game_images/item.xpm", &width, &height);
	if (!game->collectable)
		exit_point(game);
}

static void	render_tile(t_complete *game, char tile_type, int x, int y)
{
	void	*img;

	img = NULL;
	if (tile_type == '1')
		img = game->barrier;
	else if (tile_type == '0')
		img = game->floor;
	else if (tile_type == 'P')
	{
		img = game->player;
		game->x_axis = x;
		game->y_axis = y;
	}
	else if (tile_type == 'E')
		img = game->exit;
	else if (tile_type == 'C')
	{
		img = game->collectable;
		game->collectables++;
	}
	if (img)
		mlx_put_image_to_window(game->mlxpointer, game->winpointer,
			img, x * TILE_SIZE, y * TILE_SIZE);
}

void	place_images_in_game(t_complete *game)
{
	load_game_textures(game);
}

void	adding_in_graphics(t_complete *game)
{
	int	x;
	int	y;

	game->collectables = 0;
	y = 0;
	while (y < game->heightmap)
	{
		x = 0;
		while (x < game->widthmap)
		{
			render_tile(game, game->map[y][x], x, y);
			x++;
		}
		y++;
	}
}

void	free_textures(t_complete *game)
{
	if (game->floor)
		mlx_destroy_image(game->mlxpointer, game->floor);
	if (game->barrier)
		mlx_destroy_image(game->mlxpointer, game->barrier);
	if (game->player)
		mlx_destroy_image(game->mlxpointer, game->player);
	if (game->exit)
		mlx_destroy_image(game->mlxpointer, game->exit);
	if (game->collectable)
		mlx_destroy_image(game->mlxpointer, game->collectable);
}