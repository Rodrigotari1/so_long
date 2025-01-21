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

NAME := so_long
CC := gcc
CFLAGS := -Wall -Wextra -Werror -Iheaders -g

# Source directories and files
SRC_DIR := game_logic
GNL_DIR := get_next_line
SRCS := $(wildcard $(SRC_DIR)/*.c) $(wildcard $(GNL_DIR)/*.c)
OBJS := $(SRCS:.c=.o)

# OS specific configurations
UNAME := $(shell uname)

ifeq ($(UNAME), Linux)
	MLX_DIR := minilibx-linux
	MLX_FLAGS := -lmlx -lXext -lX11 -L$(MLX_DIR)
	CFLAGS += -I$(MLX_DIR)
else ifeq ($(UNAME), Darwin)
	MLX_DIR := minilibx
	MLX_FLAGS := -lmlx -framework OpenGL -framework AppKit -L$(MLX_DIR)
	CFLAGS += -I$(MLX_DIR)
endif

MLX := $(MLX_DIR)/libmlx.a
LIBS := $(MLX_FLAGS) -lm -lz

# Default map for testing
MAP_FILE := game_maps/map1.ber

# Colors for output
GREEN := \033[0;32m
RED := \033[0;31m
RESET := \033[0m

# Add printf directory and library
PRINTF_DIR = printf
PRINTF = $(PRINTF_DIR)/libftprintf.a

all: $(MLX) $(PRINTF) $(NAME)

$(MLX):
	@echo "$(GREEN)Building MinilibX...$(RESET)"
	@make -C $(MLX_DIR)

$(PRINTF):
	make -C $(PRINTF_DIR)

$(NAME): $(OBJS) $(PRINTF)
	@echo "$(GREEN)Building $(NAME)...$(RESET)"
	$(CC) $(OBJS) $(PRINTF) -L$(MLX_DIR) $(LIBS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "$(RED)Cleaning object files...$(RESET)"
	@make clean -C $(MLX_DIR)
	@make -C $(PRINTF_DIR) clean
	@rm -f $(OBJS)
	@rm -f $(SRC_DIR)/*.d

fclean: clean
	@echo "$(RED)Cleaning executables...$(RESET)"
	@make -C $(PRINTF_DIR) fclean
	@rm -f $(NAME)

re: fclean all

run: all
	./$(NAME) $(MAP_FILE)

.PHONY: all clean fclean re run
