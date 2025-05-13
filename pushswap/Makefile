NAME = pushswap
CC = cc
CFLAGS = -Wall -Wextra -Werror
INC = -Ilibft -Ift_printf

# Directorios de las librerías
LIBFT_DIR = libft
FT_PRINTF_DIR = ft_printf

# Nombres de las librerías compiladas
LIBFT = $(LIBFT_DIR)/libft.a
FT_PRINTF = $(FT_PRINTF_DIR)/libftprintf.a

# Fuentes de pushswap (agrega más archivos si los tienes)
SRC = pushswap.c checks.c normalize_arr.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@$(MAKE) -C $(LIBFT_DIR) bonus
	@$(MAKE) -C $(FT_PRINTF_DIR)
	$(CC) $(CFLAGS) $(INC) -o $(NAME) $(OBJ) $(LIBFT) $(FT_PRINTF)

%.o: %.c
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

clean:
	rm -f $(OBJ)
	@$(MAKE) -C $(LIBFT_DIR) clean
	@$(MAKE) -C $(FT_PRINTF_DIR) clean

fclean: clean
	rm -f $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@$(MAKE) -C $(FT_PRINTF_DIR) fclean

re: fclean all

.PHONY: all clean fclean re

