/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrigo <rodrigo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 12:35:47 by rodrigo           #+#    #+#             */
/*   Updated: 2025/01/21 00:56:14 by rodrigo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*ft_memset(void *b, int c, size_t length)
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
		free(game->mlxpointer);
	while (game->map && line < game->heightmap)
	{
		if (game->map[line])
			free(game->map[line]);
		line++;
	}
	if (game->map)
		free(game->map);
	exit(0);
	return (0);
}

int	main(int argc, char **argv)
{
	t_complete	game;

	if (argc != 2)
	{
		ft_printf("Error\nInvalid number of arguments\n");
		return (1);
	}
	ft_memset(&game, 0, sizeof(t_complete));
	check_file_validity(argv[1]);
	map_reading(&game, argv[1]);
	check_errors(&game);
	game.mlxpointer = mlx_init();
	game.winpointer = mlx_new_window(game.mlxpointer, game.widthmap * TILE_SIZE,
			game.heightmap * TILE_SIZE, "solong");
	place_images_in_game(&game);
	adding_in_graphics(&game);
	mlx_key_hook(game.winpointer, controls_working, &game);
	mlx_hook(game.winpointer, 33, 1L << 17, exit_point, &game);
	mlx_loop(game.mlxpointer);
}
