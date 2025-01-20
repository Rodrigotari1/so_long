/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrigo <rodrigo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 17:20:40 by rtari-ca          #+#    #+#             */
/*   Updated: 2025/01/20 19:46:00 by rodrigo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../printf/ft_printf.h"
# define TILE_SIZE 32
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <errno.h>
# include <string.h>
# include "get_next_line.h"
# include <mlx.h>

typedef struct t_start
{
	int		fd;
	int		heightmap;
	int		widthmap;
	int		playercount;
	int		columncount;
	int		exitcount;
	int		x_axis;
	int		y_axis;
	int		counter;
	int		collectables;

	char	**map;

	void	*floor;
	void	*barrier;
	void	*player;
	void	*exit;
	void	*collectable;
	void	*mlxpointer;
	void	*winpointer;

}	t_complete;

typedef struct s_pos
{
	int	x;
	int	y;
}	t_pos;

int		exit_point(t_complete *game);
int		map_reading(t_complete *game, char **argv);
int		controls_working(int command, t_complete *game);
void	adding_in_graphics(t_complete *game);
void	place_images_in_game(t_complete *game);
void	check_errors(t_complete *game);
void	free_textures(t_complete *game);
int		width_of_map(char *string);
void	check_file_validity(char *filename);
void	check_map_dimensions(t_complete *game);
void	render_tile(t_complete *game, char tile_type, int x, int y);
int		handle_movement(t_complete *game, int dx, int dy);
int		handle_move_to_position(t_complete *game, t_pos new, t_pos old);
void	validate_walls(t_complete *game);
void	validate_map_characters(t_complete *game);
int		check_horizontal_walls(t_complete *game);
int		check_vertical_walls(t_complete *game);
int		handle_player_movement(t_complete *game, int new_x, int new_y);

#endif
