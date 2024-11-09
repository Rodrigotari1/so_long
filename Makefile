# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rtari-ca <rtari-ca@student.42lausanne.c    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/08 19:02:17 by rtari-ca          #+#    #+#              #
#    Updated: 2024/11/09 18:10:25 by rtari-ca         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CC = cc
CFLAGS = -Wall -Wextra -Werror -Iminilibx  # Include path for mlx.h
MLX_FLAGS = -Lminilibx -lmlx -framework OpenGL -framework AppKit

SRC = main.c

all: $(NAME)

$(NAME): $(SRC)
	$(CC) $(CFLAGS) $(SRC) $(MLX_FLAGS) -o $(NAME)

clean:
	rm -f $(NAME)

re: clean all
