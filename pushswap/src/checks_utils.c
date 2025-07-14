/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptraba-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 17:38:38 by ptraba-d          #+#    #+#             */
/*   Updated: 2025/07/14 17:38:39 by ptraba-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	check_order(int *a)
{
	int	i;

	i = 0;
	while (a[i])
		i++;
	while (i > 0)
	{
		if (!(a[i] > a[i - 1]))
			return (0);
		i--;
	}
	return (1);
}

int	check_order_stack(t_list *stack)
{
	if (!stack)
		return (1);
	while (stack->next)
	{
		if (*((int *)stack->next->content) <= *((int *)stack->content))
			return (0);
		stack = stack->next;
	}
	return (1);
}

int	get_stack_size(t_list *stack)
{
	int	size;

	size = 0;
	while (stack)
	{
		size++;
		stack = stack->next;
	}
	return (size);
}
