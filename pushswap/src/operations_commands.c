/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_commands.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptraba-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 17:39:17 by ptraba-d          #+#    #+#             */
/*   Updated: 2025/07/14 17:39:18 by ptraba-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	sa(t_list **stack_a)
{
	swap_stack(stack_a);
	ft_printf("sa\n");
}

void	sb(t_list **stack_b)
{
	swap_stack(stack_b);
	ft_printf("sb\n");
}

void	ss(t_list **stack_a, t_list **stack_b)
{
	swap_stack(stack_a);
	swap_stack(stack_b);
	ft_printf("ss\n");
}

void	pa(t_list **stack_a, t_list **stack_b)
{
	push_stack(stack_b, stack_a);
	ft_printf("pa\n");
}

void	pb(t_list **stack_a, t_list **stack_b)
{
	push_stack(stack_a, stack_b);
	ft_printf("pb\n");
}
