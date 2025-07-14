/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptraba-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 17:39:59 by ptraba-d          #+#    #+#             */
/*   Updated: 2025/07/14 17:40:00 by ptraba-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	sort_small_sets(t_list **stack_a, t_list **stack_b, int len)
{
	if (check_order_stack(*stack_a))
		return ;
	if (len == 2)
		sort_two_elements(stack_a);
	else if (len == 3)
		sort_three_elements(stack_a);
	else if (len == 4)
		sort_four_elements(stack_a, stack_b);
	else if (len == 5)
		sort_five_elements(stack_a, stack_b);
}

void	free_stack(t_list **stack)
{
	t_list	*temp;

	if (!stack || !*stack)
		return ;
	while (*stack)
	{
		temp = (*stack)->next;
		free(*stack);
		*stack = temp;
	}
}

int	initialize_stacks(int *arr, int len, t_list **stack_a, int **norm)
{
	if (len == 1)
	{
		free(arr);
		return (0);
	}
	*norm = normalize_arr(arr, len);
	if (!*norm)
	{
		free(arr);
		return (0);
	}
	*stack_a = create_stack(*norm, len);
	if (!*stack_a)
	{
		free(arr);
		free(*norm);
		return (0);
	}
	return (1);
}

void	execute_push_swap(int *array, int len)
{
	t_list	*stack_a;
	t_list	*stack_b;
	int		*normalized;

	if (!initialize_stacks(array, len, &stack_a, &normalized))
		return ;
	stack_b = NULL;
	if (len <= 5)
		sort_small_sets(&stack_a, &stack_b, len);
	else if (len <= 200)
		sort_medium_algorithm(&stack_a, &stack_b, len, normalized);
	else
		sort_large_algorithm(&stack_a, &stack_b, len);
	cleanup_memory(array, normalized, &stack_a, &stack_b);
}

int	main(int argc, char **argv)
{
	int	*array;
	int	i;

	if (argc < 2)
		return (0);
	if (!argv || !argv[1] || check_error(argv + 1))
	{
		write(2, "Error\n", 6);
		return (1);
	}
	array = malloc((argc - 1) * sizeof(int));
	if (!array)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	i = 1;
	while (i < argc)
	{
		array[i - 1] = ft_atoi(argv[i]);
		i++;
	}
	execute_push_swap(array, argc - 1);
	return (0);
}
