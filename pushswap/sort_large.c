#include "pushswap.h"

int	calculate_max_bits(int max_num)
{
	int	bits;

	bits = 0;
	while (max_num > 0)
	{
		max_num >>= 1;
		bits++;
	}
	return (bits);
}

void	process_bit(t_list **stack_a, t_list **stack_b, int bit, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		if (((*(int *)((*stack_a)->content)) >> bit) & 1)
			ra(stack_a);
		else
			pb(stack_a, stack_b);
		i++;
	}
	while (*stack_b)
		pa(stack_a, stack_b);
}

void	radix_sort_algorithm(t_list **stack_a, t_list **stack_b, int len)
{
	int	max_bits;
	int	bit;

	max_bits = calculate_max_bits(len - 1);
	bit = 0;
	while (bit < max_bits)
	{
		process_bit(stack_a, stack_b, bit, len);
		bit++;
	}
}

void	sort_large_set(t_list **stack_a, t_list **stack_b, int len)
{
	radix_sort_algorithm(stack_a, stack_b, len);
}
