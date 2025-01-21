/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics_display.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrigo <rodrigo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 23:00:00 by rtari-ca          #+#    #+#             */
/*   Updated: 2025/01/21 18:32:15 by rodrigo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

void	adding_in_graphics(t_complete *game)
{
	int	x;
	int	y;

	count_collectibles(game);
	y = -1;
	while (++y < game->heightmap)
	{
		x = -1;
		while (++x < game->widthmap)
			render_tile(game, game->map[y][x], x, y);
	}
}
