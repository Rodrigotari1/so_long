/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_loader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtari-ca <rtari-ca@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 12:35:39 by rodrigo           #+#    #+#             */
/*   Updated: 2025/01/17 15:51:49 by rtari-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	add_line(t_complete *game, char *line)
{
	char	**temporary;
	int		i;

	if (!line)
		return (0);
	i = 0;
	game->heightmap++;
	temporary = (char **)malloc(sizeof(char *) * (game->heightmap + 1));
	if (!temporary)
	{
		free(line);
		exit_point(game);
	}
	temporary[game->heightmap] = NULL;
	while (i < game->heightmap - 1)
	{
		temporary[i] = game->map[i];
		i++;
	}
	temporary[i] = line;
	if (game->map)
		free(game->map);
	game->map = temporary;
	return (1);
}

static void	process_map_line(t_complete *game, char *readmap)
{
	if (!add_line(game, readmap))
		return ;
	if (game->heightmap == 1)
		game->widthmap = width_of_map(game->map[0]);
	else if (game->heightmap > 1
		&& width_of_map(game->map[game->heightmap - 1]) != game->widthmap)
	{
		printf("Error\n");
		exit_point(game);
	}
}

int	map_reading(t_complete *game, char **argv)
{
	char	*readmap;

	check_file_validity(argv[1]);
	game->fd = open(argv[1], O_RDONLY);
	if (game->fd < 0)
	{
		printf("Error\n");
		exit(1);
	}
	game->heightmap = 0;
	game->widthmap = 0;
	while (1)
	{
		readmap = get_next_line(game->fd);
		if (!readmap)
			break ;
		process_map_line(game, readmap);
	}
	close(game->fd);
	check_map_dimensions(game);
	return (1);
}
