NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror -Ilibft -Ift_printf -Isrc

SRCDIR = src
OBJDIR = obj

SOURCES = push_swap_main.c \
		  operations.c \
		  operations_commands.c \
		  operations_rotate.c \
		  operations_reverse_rotate.c \
		  sort_small.c \
		  sort_medium.c \
		  sort_medium_utils.c \
		  sort_medium_moves.c \
		  sort_large.c \
		  utils.c \
		  checks_validation.c \
		  checks_utils.c \
		  normalize_arr.c

SRC_FILES = $(addprefix $(SRCDIR)/, $(SOURCES))
OBJECTS = $(addprefix $(OBJDIR)/, $(SOURCES:.c=.o))

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

PRINTF_DIR = ft_printf
PRINTF = $(PRINTF_DIR)/libftprintf.a

all: $(NAME)

$(NAME): $(OBJDIR) $(OBJECTS) $(LIBFT) $(PRINTF)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJECTS) $(LIBFT) $(PRINTF)

$(OBJDIR):
	mkdir -p $(OBJDIR)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR) bonus

$(PRINTF):
	$(MAKE) -C $(PRINTF_DIR)

clean:
	rm -rf $(OBJDIR)
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(PRINTF_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(MAKE) -C $(PRINTF_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
