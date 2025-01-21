/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_loader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrigo <rodrigo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 12:35:39 by rodrigo           #+#    #+#             */
/*   Updated: 2025/01/21 15:44:39 by rodrigo          ###   ########.fr       */
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
		ft_printf("Error\n");
		exit_point(game);
	}
}

static void	handle_map_error(t_complete *game, int fd)
{
	ft_printf("Error\nCould not open map file\n");
	close(fd);
	exit_point(game);
}

static void	read_map_lines(t_complete *game, int fd)
{
	char	*line;
	int		height;

	height = 0;
	line = get_next_line(fd);
	while (line)
	{
		process_map_line(game, line);
		height++;
		line = get_next_line(fd);
	}
	game->heightmap = height;
}

int	map_reading(t_complete *game, char *path)
{
	int		fd;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		handle_map_error(game, fd);
	read_map_lines(game, fd);
	close(fd);
	return (0);
}
