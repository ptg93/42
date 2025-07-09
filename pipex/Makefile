NAME		= pipex
BONUS_NAME	= pipex_bonus
CC			= cc
CFLAGS		= -Wall -Wextra -Werror
LIBFT_DIR	= ./libft
LIBFT		= $(LIBFT_DIR)/libft.a
HEADER		= pipex.h

SRCS		= main.c run_command.c cleanup.c get_path.c parse_command.c
OBJS		= $(SRCS:.c=.o)

BONUS_DIR	= ./bonus
BONUS_SRCS	= $(BONUS_DIR)/main_bonus.c \
			  $(BONUS_DIR)/run_command_bonus.c \
			  $(BONUS_DIR)/get_path_bonus.c \
			  $(BONUS_DIR)/cleanup_bonus.c
BONUS_OBJS	= $(BONUS_SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) -L$(LIBFT_DIR) -lft -o $(NAME)

bonus: $(BONUS_OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(BONUS_OBJS) -L$(LIBFT_DIR) -lft -o $(BONUS_NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

clean:
	$(MAKE) clean -C $(LIBFT_DIR)
	rm -f $(OBJS) $(BONUS_OBJS)

fclean: clean
	$(MAKE) fclean -C $(LIBFT_DIR)
	rm -f $(NAME) $(BONUS_NAME)

re: fclean all

.PHONY: all bonus clean fclean re
