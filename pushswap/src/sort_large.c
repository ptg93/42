#include "pushswap.h"

int	get_max_bits(int max_num)
{
	int	bits;

	bits = 0;
	while ((max_num >> bits) != 0)
		bits++;
	return (bits);
}

void	radix_sort_bit(t_list **stack_a, t_list **stack_b, int bit)
{
	int	size;
	int	i;
	int	num;

	size = get_stack_size(*stack_a);
	i = 0;
	while (i < size)
	{
		num = *(int *)(*stack_a)->content;
		if (((num >> bit) & 1) == 1)
			ra(stack_a);
		else
			pb(stack_a, stack_b);
		i++;
	}
	while (get_stack_size(*stack_b) > 0)
		pa(stack_a, stack_b);
}

int	find_max_value(t_list *stack)
{
	int	max;
	int	current;

	if (!stack)
		return (0);
	max = *(int *)stack->content;
	while (stack)
	{
		current = *(int *)stack->content;
		if (current > max)
			max = current;
		stack = stack->next;
	}
	return (max);
}

void	sort_large_algorithm(t_list **stack_a, t_list **stack_b, int len)
{
	int	max_bits;
	int	bit;
	int	max_value;

	if (len <= 5)
	{
		sort_small_sets(stack_a, stack_b, len);
		return ;
	}
	if (check_order_stack(*stack_a))
		return ;
	max_value = find_max_value(*stack_a);
	max_bits = get_max_bits(max_value);
	bit = 0;
	while (bit < max_bits)
	{
		radix_sort_bit(stack_a, stack_b, bit);
		bit++;
	}
}
