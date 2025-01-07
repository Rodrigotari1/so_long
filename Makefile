NAME := so_long
CC := gcc
CFLAGS := -Wall -Wextra -Werror

UNAME := $(shell uname)

ifeq ($(UNAME), Linux)
    LIBS := -lmlx -lXext -lX11 -lm -lz
    INCLUDES := -Iheaders -I/usr/include
    MINILIBX := minilibx-linux
    INSTALL_DIR := /usr/local/bin
else ifeq ($(UNAME), Darwin)
    LIBS := -lmlx -framework OpenGL -framework AppKit -lm -lz
    INCLUDES := -Iheaders
    MINILIBX := minilibx
    INSTALL_DIR := /usr/local/bin
else
    $(error Unsupported operating system: $(UNAME))
endif

SRC_DIR := game_logic
GNL_DIR := get_next_line
SRC_FILES := $(wildcard $(SRC_DIR)/*.c) $(wildcard $(GNL_DIR)/*.c)
LIBRARY := -L$(MINILIBX)

MAP_FILE := game_maps/map1.ber

all: $(NAME)

$(NAME): $(SRC_FILES)
	@$(MAKE) -C $(MINILIBX)
	$(CC) $(CFLAGS) $(INCLUDES) $^ $(LIBRARY) $(LIBS) -o $@

clean:
	@$(MAKE) clean -C $(MINILIBX)
	@rm -f $(NAME)

fclean: clean

re: fclean all

debug: CFLAGS += -g
debug: all

install: all
	cp $(NAME) $(INSTALL_DIR)

run: all
	./$(NAME) $(MAP_FILE)

.PHONY: all clean fclean re debug install run