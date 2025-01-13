/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrigo <rodrigo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 12:35:47 by rodrigo           #+#    #+#             */
/*   Updated: 2025/01/13 16:14:39 by rodrigo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	*ft_memset(void *b, int c, size_t length)
{
	unsigned char	*p;

	p = (unsigned char *)b;
	while (length--)
		*p++ = (unsigned char)c;
	return (b);
}

int	exit_point(t_complete *game)
{
	int	line;

	line = 0;
	if (game->winpointer && game->mlxpointer)
	{
		free_textures(game);
		mlx_destroy_window(game->mlxpointer, game->winpointer);
	}
	if (game->mlxpointer)
	{
		free(game->mlxpointer);
	}
	while (game->map && line < game->heightmap)
	{
		if (game->map[line])
			free(game->map[line]);
		line++;
	}
	if (game->map)
		free(game->map);
	exit(0);
}

int	main(int argc, char **argv)
{
	t_complete	game;

	if (argc != 2)
		return (0);
	ft_memset(&game, 0, sizeof(t_complete));
	map_reading(&game, argv);
	check_errors(&game);
	game.mlxpointer = mlx_init();
	game.winpointer = mlx_new_window(game.mlxpointer, game.widthmap * TILE_SIZE,
			game.heightmap * TILE_SIZE, "solong");
	place_images_in_game(&game);
	adding_in_graphics(&game);
	mlx_key_hook(game.winpointer, controls_working, &game);
	mlx_hook(game.winpointer, 33, 1L<<17, (void *)exit, 0);
	mlx_loop(game.mlxpointer);
}
