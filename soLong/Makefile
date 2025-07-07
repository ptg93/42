NAME = so_long

SRC = main.c exit_msg.c
OBJ = $(SRC:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

MLX_DIR = minilibx-linux
MLX = $(MLX_DIR)/libmlx.a

INCLUDES = -I$(LIBFT_DIR) -I$(MLX_DIR)

MLX_FLAGS = -lXext -lX11 -lm

MAP_CHARS_DEF = -DMAP_CHARS=\"01CEP\"

all: CFLAGS += $(MAP_CHARS_DEF)
all: $(NAME)

$(NAME): $(OBJ)
	$(MAKE) -C $(LIBFT_DIR)
	$(MAKE) -C $(MLX_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -o $(NAME) $(OBJ) $(LIBFT) $(MLX) $(MLX_FLAGS)

bonus: CFLAGS += -DMAP_CHARS=\"01CEPM\"
bonus: fclean $(NAME)

clean:
	rm -f $(OBJ)
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(MLX_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(MAKE) -C $(MLX_DIR) clean

re: fclean all
