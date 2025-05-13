#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include <stdlib.h>
# include "libft/libft.h"
# include "ft_printf/ft_printf.h"
# include <limits.h>

int create_nulint (int *a, int len);
int *normalize_arr(int *a, int len);
int ft_get_min_pos(int *a, int len, int nulint);
int ft_is_min(int *a, int c, int len, int nulint);
int check_order(int *a);
int check_int_range(const char *str);
int check_digits(char **argv);
int check_duplicates(char **argv);
int check_error(char **argv);
void    push_swap(int *a, int len);
t_list  *populate_stack(int *a, int len);

#endif
