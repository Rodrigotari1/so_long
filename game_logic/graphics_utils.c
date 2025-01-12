/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrigo <rodrigo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 23:00:00 by rtari-ca          #+#    #+#             */
/*   Updated: 2025/01/12 19:02:48 by rodrigo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
