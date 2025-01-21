# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rodrigo <rodrigo@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/30 12:35:01 by rodrigo           #+#    #+#             #
#    Updated: 2025/01/12 18:53:07 by rodrigo          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CC = gcc
CFLAGS = -Wall -Wextra -Werror -Iheaders -g -Iminilibx-linux

SRCS = game_logic/error_utils.c \
	game_logic/game_controller.c \
	game_logic/graphics_display.c \
	game_logic/graphics_init.c \
	game_logic/graphics_utils.c \
	game_logic/map_loader.c \
	game_logic/map_utils.c \
	game_logic/map_validation.c \
	game_logic/path_validation.c \
	game_logic/so_long.c \
	game_logic/wall_validation.c \
	get_next_line/get_next_line.c \
	get_next_line/get_next_line_utils.c

OBJS = $(SRCS:.c=.o)
MLX_DIR = minilibx-linux
MLX = $(MLX_DIR)/libmlx.a
PRINTF_DIR = printf
PRINTF = $(PRINTF_DIR)/libftprintf.a

all: $(MLX) $(PRINTF) $(NAME)

$(MLX):
	make -C $(MLX_DIR)

$(PRINTF):
	make -C $(PRINTF_DIR)

$(NAME): $(OBJS) $(PRINTF)
	$(CC) $(OBJS) $(PRINTF) -L$(MLX_DIR) -lmlx -lXext -lX11 -lm -lz -o $(NAME)

clean:
	make -C $(MLX_DIR) clean
	make -C $(PRINTF_DIR) clean
	rm -f $(OBJS)

fclean: clean
	make -C $(PRINTF_DIR) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re