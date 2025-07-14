/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptraba-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 17:40:54 by ptraba-d          #+#    #+#             */
/*   Updated: 2025/07/14 17:40:55 by ptraba-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	find_min_position(t_list *stack)
{
	int	min_val;
	int	min_pos;
	int	pos;

	if (!stack)
		return (-1);
	min_val = *((int *)stack->content);
	min_pos = 0;
	pos = 0;
	while (stack)
	{
		if (*((int *)stack->content) < min_val)
		{
			min_val = *((int *)stack->content);
			min_pos = pos;
		}
		stack = stack->next;
		pos++;
	}
	return (min_pos);
}

int	find_max_position(t_list *stack)
{
	int	max_val;
	int	max_pos;
	int	pos;

	if (!stack)
		return (-1);
	max_val = *((int *)stack->content);
	max_pos = 0;
	pos = 0;
	while (stack)
	{
		if (*((int *)stack->content) > max_val)
		{
			max_val = *((int *)stack->content);
			max_pos = pos;
		}
		stack = stack->next;
		pos++;
	}
	return (max_pos);
}

void	cleanup_stack_on_error(t_list **stack)
{
	t_list	*temp;

	while (*stack)
	{
		temp = (*stack)->next;
		free(*stack);
		*stack = temp;
	}
}

void	cleanup_memory(int *arr, int *norm, t_list **stack_a, t_list **stack_b)
{
	free_stack(stack_a);
	free_stack(stack_b);
	free(arr);
	free(norm);
}

t_list	*create_stack(int *array, int len)
{
	t_list	*stack;
	t_list	*node;
	int		i;

	if (!array || len <= 0)
		return (NULL);
	i = 0;
	stack = ft_lstnew(&array[i]);
	if (!stack)
		return (NULL);
	while (++i < len)
	{
		node = ft_lstnew(&array[i]);
		if (!node)
		{
			cleanup_stack_on_error(&stack);
			return (NULL);
		}
		ft_lstadd_back(&stack, node);
	}
	return (stack);
}
