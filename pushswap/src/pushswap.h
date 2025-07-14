/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptraba-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 17:39:48 by ptraba-d          #+#    #+#             */
/*   Updated: 2025/07/14 17:39:50 by ptraba-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include <stdlib.h>
# include "../libft/libft.h"
# include "../ft_printf/ft_printf.h"
# include <limits.h>

/* Structure for chunk parameters */
typedef struct s_chunk
{
	int	*sorted;
	int	lower;
	int	upper;
}	t_chunk;

/* Input validation functions */
int		create_nulint(int *a, int len);
int		*normalize_arr(int *a, int len);
int		ft_get_min_pos(int *a, int len, int nulint);
int		ft_is_min(int *a, int c, int len, int nulint);
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

/* Operation commands with output */
void	sa(t_list **stack_a);
void	sb(t_list **stack_b);
void	ss(t_list **stack_a, t_list **stack_b);
void	pa(t_list **stack_a, t_list **stack_b);
void	pb(t_list **stack_a, t_list **stack_b);
void	ra(t_list **stack_a);
void	rb(t_list **stack_b);
void	rr(t_list **stack_a, t_list **stack_b);
void	rra(t_list **stack_a);
void	rrb(t_list **stack_b);
void	rrr(t_list **stack_a, t_list **stack_b);

/* Small set sorting algorithms */
void	sort_two_elements(t_list **stack_a);
void	sort_three_elements(t_list **stack_a);
void	sort_four_elements(t_list **stack_a, t_list **stack_b);
void	sort_five_elements(t_list **stack_a, t_list **stack_b);
void	sort_small_sets(t_list **stack_a, t_list **stack_b, int len);

/* Medium set sorting algorithm (chunk-based) */
int		*copy_array(int *array_a, int size);
void	sort_medium_algorithm(t_list **stack_a, t_list **stack_b, int size,
			int *norm);
void	sort_array(int *array, int size);
int		find_chunk_position_top(t_list *stack_a, int min, int max);
int		find_chunk_position_bottom(t_list *stack_a, int min, int max);
int		find_nearest_chunk_position(t_list *stack_a, int min, int max);
void	bring_to_top_a(t_list **stack_a, int pos);
void	bring_to_top_b(t_list **stack_b, int pos);
void	push_chunk_to_b(t_list **stack_a, t_list **stack_b, t_chunk *chunk);
void	push_back_to_a(t_list **stack_a, t_list **stack_b);

/* Large set sorting algorithm (radix) */
int		get_max_bits(int max_num);
void	radix_sort_bit(t_list **stack_a, t_list **stack_b, int bit);
void	sort_large_algorithm(t_list **stack_a, t_list **stack_b, int len);

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
