#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include <stdlib.h>
# include "libft/libft.h"
# include "ft_printf/ft_printf.h"
# include <limits.h>

/* Input validation functions */
int		create_nulint(int *a, int len);
int		*normalize_arr(int *a, int len);
int		ft_get_min_pos(int *a, int len, int nulint);
int		ft_is_min(int *a, int c, int len, int nulint);
int		check_order(int *a);
int		check_int_range(const char *str);
int		check_digits(char **argv);
int		check_duplicates(char **argv);
int		check_error(char **argv);
int		check_order_stack(t_list *stack);
int		get_stack_size(t_list *stack);

/* Basic stack operations */
void	swap_stack(t_list **stack);
void	push_stack(t_list **from_stack, t_list **to_stack);
void	rotate_stack(t_list **stack);
void	reverse_rotate_stack(t_list **stack);

/* Operation wrappers with output */
void	sa(t_list **stack_a);
void	sb(t_list **stack_b);
void	pa(t_list **stack_a, t_list **stack_b);
void	pb(t_list **stack_a, t_list **stack_b);
void	ra(t_list **stack_a);
void	rb(t_list **stack_b);
void	rra(t_list **stack_a);
void	rrb(t_list **stack_b);

/* Small set sorting algorithms */
void	sort_two_elements(t_list **stack_a);
void	sort_three_elements(t_list **stack_a);
void	sort_four_elements(t_list **stack_a, t_list **stack_b);
void	sort_five_elements(t_list **stack_a, t_list **stack_b);
void	sort_small_sets(t_list **stack_a, t_list **stack_b, int len);

/* Large set sorting algorithms */
int		calculate_max_bits(int max_num);
void	process_bit(t_list **stack_a, t_list **stack_b, int bit, int len);
void	radix_sort_algorithm(t_list **stack_a, t_list **stack_b, int len);
void	sort_large_set(t_list **stack_a, t_list **stack_b, int len);

/* Utility functions */
int		find_min_position(t_list *stack);
int		find_max_position(t_list *stack);
void	cleanup_stack_on_error(t_list **stack);
t_list	*create_stack(int *array, int len);

/* Main functions */
void	cleanup_memory(int *arr, int *norm, t_list **stack_a, t_list **stack_b);
int		initialize_stacks(int *arr, int len, t_list **stack_a, int **norm);
void	execute_push_swap(int *array, int len);
void	free_stack(t_list **stack);

#endif
