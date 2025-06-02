LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

all: $(LIBFT) pipex

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

pipex: $(LIBFT)
	$(CC) $(CFLAGS) -I. -I$(LIBFT_DIR) \
		pipex_bonus.c execute_command.c get_path.c \
		$(LIBFT) -o pipex

clean:
	$(MAKE) -C $(LIBFT_DIR) clean

fclean:
	$(MAKE) -C $(LIBFT_DIR) fclean
	rm -f pipex

re: fclean all