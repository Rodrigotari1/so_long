/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrigo <rodrigo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 12:35:39 by rodrigo           #+#    #+#             */
/*   Updated: 2025/01/12 19:06:06 by rodrigo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

void	check_file_validity(char *filename)
{
	int	len;

	if (access(filename, F_OK) != 0)
	{
		printf("Error\n");
		exit(1);
	}
	len = ft_strlen(filename);
	if (len < 5)
	{
		printf("Error\n");
		exit(1);
	}
	if (strncmp(filename + len - 4, ".ber", 4) != 0)
	{
		printf("Error\n");
		exit(1);
	}
}

void	check_map_dimensions(t_complete *game)
{
	if (!game->heightmap || !game->widthmap
		|| game->heightmap < 3 || game->widthmap < 3)
	{
		printf("Error\n");
		exit_point(game);
	}
}
