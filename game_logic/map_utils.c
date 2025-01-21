/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrigo <rodrigo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 12:35:39 by rodrigo           #+#    #+#             */
/*   Updated: 2025/01/21 18:32:15 by rodrigo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

int	width_of_map(char *string)
{
	int	width;

	width = 0;
	while (string[width] != '\0')
		width++;
	if (string[width - 1] == '\n')
		width--;
	return (width);
}

static int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && (s1[i] || s2[i]))
	{
		if ((unsigned char)s1[i] != (unsigned char)s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}

void	check_file_validity(char *filename)
{
	int	len;

	if (access(filename, F_OK) != 0)
	{
		ft_printf("Error\n");
		exit(1);
	}
	len = ft_strlen(filename);
	if (len < 5)
	{
		ft_printf("Error\n");
		exit(1);
	}
	if (ft_strncmp(filename + len - 4, ".ber", 4) != 0)
	{
		ft_printf("Error\n");
		exit(1);
	}
}

void	check_map_dimensions(t_complete *game)
{
	if (!game->heightmap || !game->widthmap
		|| game->heightmap < 3 || game->widthmap < 3)
	{
		ft_printf("Error\n");
		exit_point(game);
	}
}

void	free_visited_array(char **visited, int height)
{
	while (height--)
		free(visited[height]);
	free(visited);
}
