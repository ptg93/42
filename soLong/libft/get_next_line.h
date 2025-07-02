#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*get_next_line(int fd);
int		get_len(char *s, int mode, int *found);
char	*reshape_leftovers(char **left, char **next, int len);
char	*create_temp_buff(char *buff, char **next, int buff_len, int next_len);
void	bad_bytes_handler(char **left, char *buff, char **next, int bytes);
void	add_leftovers(char **left, char **next);
void	populate_leftovers(char **left, char *buff, char **next, int buff_len);
void	add_buffer(char **left, char *buff, char **next);
void	read_next(char **left, char *buff, char **next, int fd);

#endif
