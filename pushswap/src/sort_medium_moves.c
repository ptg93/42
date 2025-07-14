/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_medium_moves.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptraba-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 17:40:23 by ptraba-d          #+#    #+#             */
/*   Updated: 2025/07/14 17:40:24 by ptraba-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	bring_to_top_a(t_list **stack_a, int pos)
{
	int	size;
	int	i;

	size = get_stack_size(*stack_a);
	if (pos <= size / 2)
	{
		i = 0;
		while (i < pos)
		{
			ra(stack_a);
			i++;
		}
	}
	else
	{
		i = 0;
		while (i < size - pos)
		{
			rra(stack_a);
			i++;
		}
	}
}

void	bring_to_top_b(t_list **stack_b, int pos)
{
	int	size;
	int	i;

	size = get_stack_size(*stack_b);
	if (pos <= size / 2)
	{
		i = 0;
		while (i < pos)
		{
			rb(stack_b);
			i++;
		}
	}
	else
	{
		i = 0;
		while (i < size - pos)
		{
			rrb(stack_b);
			i++;
		}
	}
}

void	push_chunk_to_b(t_list **stack_a, t_list **stack_b, t_chunk *chunk)
{
	int	min;
	int	max;
	int	pos;
	int	val;
	int	median;

	min = chunk->sorted[chunk->lower];
	max = chunk->sorted[chunk->upper];
	median = chunk->sorted[(chunk->lower + chunk->upper) / 2];
	while (1)
	{
		pos = find_nearest_chunk_position(*stack_a, min, max);
		if (pos == -1)
			break ;
		bring_to_top_a(stack_a, pos);
		val = *(int *)(*stack_a)->content;
		pb(stack_a, stack_b);
		if (*stack_b && get_stack_size(*stack_b) > 1 && val < median)
			rb(stack_b);
	}
}

void	push_back_to_a(t_list **stack_a, t_list **stack_b)
{
	int	pos_max;

	while (*stack_b)
	{
		pos_max = find_max_position(*stack_b);
		bring_to_top_b(stack_b, pos_max);
		pa(stack_a, stack_b);
	}
}
