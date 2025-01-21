/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_validation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrigo <rodrigo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 20:10:01 by rodrigo           #+#    #+#             */
/*   Updated: 2025/01/21 15:45:27 by rodrigo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	check_valid_path(t_complete *game, char **visited, int y, int x)
{
	if (y < 0 || x < 0 || y >= game->heightmap || x >= game->widthmap)
		return ;
	if (visited[y][x] == '1' || game->map[y][x] == '1')
		return ;
	if (visited[y][x] != '0')
		return ;
	visited[y][x] = 'V';
	if (game->map[y][x] == 'C')
		game->valid_collectibles++;
	if (game->map[y][x] == 'E')
		game->valid_exit++;
	check_valid_path(game, visited, y - 1, x);
	check_valid_path(game, visited, y + 1, x);
	check_valid_path(game, visited, y, x - 1);
	check_valid_path(game, visited, y, x + 1);
}

static void	init_visited_row(char **visited, int i, int width)
{
	int	j;

	j = 0;
	while (j < width)
	{
		visited[i][j] = '0';
		j++;
	}
	visited[i][width] = '\0';
}

static char	**create_visited_array(t_complete *game)
{
	char	**visited;
	int		i;

	visited = (char **)malloc(sizeof(char *) * game->heightmap);
	if (!visited)
		return (NULL);
	i = 0;
	while (i < game->heightmap)
	{
		visited[i] = (char *)malloc(sizeof(char) * (game->widthmap + 1));
		if (!visited[i])
		{
			free_visited_array(visited, i);
			return (NULL);
		}
		init_visited_row(visited, i, game->widthmap);
		i++;
	}
	return (visited);
}

static void	handle_path_check(t_complete *game, char **visited, int y, int x)
{
	game->valid_collectibles = 0;
	game->valid_exit = 0;
	check_valid_path(game, visited, y, x);
	if (game->valid_collectibles != game->columncount || game->valid_exit != 1)
	{
		ft_printf("Error\nNo valid path\n");
		free_visited_array(visited, game->heightmap);
		exit_point(game);
	}
}

void	validate_path(t_complete *game)
{
	char	**visited;
	int		y;
	int		player_x;

	visited = create_visited_array(game);
	if (!visited)
	{
		ft_printf("Error\n");
		exit_point(game);
	}
	y = -1;
	while (++y < game->heightmap && game->map[y])
	{
		if (ft_strchr(game->map[y], 'P'))
		{
			player_x = ft_strchr(game->map[y], 'P') - game->map[y];
			handle_path_check(game, visited, y, player_x);
			free_visited_array(visited, game->heightmap);
			return ;
		}
	}
	ft_printf("Error\nPlayer not found\n");
	free_visited_array(visited, game->heightmap);
	exit_point(game);
}
