/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrigo <rodrigo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 23:00:00 by rtari-ca          #+#    #+#             */
/*   Updated: 2025/01/21 18:32:47 by rodrigo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

static void	handle_exit(t_complete *game, int x, int y)
{
	void	*img;

	img = game->floor;
	mlx_put_image_to_window(game->mlxpointer, game->winpointer,
		img, x * TILE_SIZE, y * TILE_SIZE);
	if (game->collectables == 0)
	{
		img = game->exit;
		mlx_put_image_to_window(game->mlxpointer, game->winpointer,
			img, x * TILE_SIZE, y * TILE_SIZE);
	}
}

void	render_tile(t_complete *game, char tile_type, int x, int y)
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
	{
		handle_exit(game, x, y);
		return ;
	}
	else if (tile_type == 'C')
		img = game->collectable;
	if (img)
		mlx_put_image_to_window(game->mlxpointer, game->winpointer,
			img, x * TILE_SIZE, y * TILE_SIZE);
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

void cleanup_game(t_complete *game)
{
	if (!game)
		return;
	free_textures(game);
	if (game->winpointer && game->mlxpointer)
	{
		#ifdef __linux__
		mlx_destroy_window(game->mlxpointer, game->winpointer);
		if (game->mlxpointer)
		{
			mlx_loop_end(game->mlxpointer);
			mlx_destroy_display(game->mlxpointer);
			free(game->mlxpointer);
		}
		#else
		mlx_destroy_window(game->mlxpointer, game->winpointer);
		if (game->mlxpointer)
			free(game->mlxpointer);
		#endif
	}
	// Free map
	if (game->map)
	{
		for (int i = 0; i < game->heightmap; i++)
			free(game->map[i]);
		free(game->map);
	}
}
