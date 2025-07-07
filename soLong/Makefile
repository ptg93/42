NAME = so_long

SRC = main.c exit_cleanup.c validate_map.c \
	  map_checks.c validate_path.c load_game.c \
	  move_player.c draw.c display.c \
	  enemy_utils.c move_enemies.c game_update.c \
	  handle_input.c

OBJ = $(SRC:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror
MAP_CHARS = -DMAP_CHARS=\"01CEP\"
CFLAGS_ALL = $(CFLAGS) $(MAP_CHARS)

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

MLX_DIR = minilibx-linux
MLX = $(MLX_DIR)/libmlx.a

INCLUDES = -I$(LIBFT_DIR) -I$(MLX_DIR)
MLX_FLAGS = -lXext -lX11 -lm

%.o: %.c
	$(CC) $(CFLAGS_ALL) $(INCLUDES) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ)
	$(MAKE) -C $(LIBFT_DIR)
	$(MAKE) -C $(MLX_DIR)
	$(CC) $(CFLAGS_ALL) $(INCLUDES) -o $(NAME) $(OBJ) $(LIBFT) $(MLX) $(MLX_FLAGS)

bonus: fclean
	$(MAKE) MAP_CHARS="-DMAP_CHARS=\\\"01CEPM\\\"" all

clean:
	rm -f $(OBJ)
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(MLX_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(MAKE) -C $(MLX_DIR) clean

re: fclean all

.PHONY: all clean fclean re bonus
