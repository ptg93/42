#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include <stdlib.h>
# include <limits.h>
# include "libft/libft.h"
# include "ft_printf/ft_printf.h"

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

int		ft_is_min(int *a, int c, int len, int nulint);
int		ft_get_min_pos(int *a, int len, int nulint);
int		create_nulint(int *a, int len);
int		*normalize_arr(int *a, int len);

int		check_order(int *a);
int		check_order_stack(t_list *stack);
int		check_int_range(const char *str);
int		check_digits(char **argv);
int		check_duplicates(char **argv);
int		check_error(char **argv);

void	swap(t_list **stack);
void	push(t_list **from_stack, t_list **to_stack);
void	rotate(t_list **stack);
void	reverse_rotate(t_list **stack);

char	**add_op(char **solution, char *instruction);
t_list	*populate_stack(int *a, int len);
void	sort_small(t_list **stack_a, t_list **stack_b, int len, char ***ops);
void	sort_large(t_list **stack_a, t_list **stack_b, int len, char ***ops);
void	push_swap(int *a, int len);

#endif
