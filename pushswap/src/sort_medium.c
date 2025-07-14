#include "pushswap.h"

void	sort_medium_algorithm(t_list **stack_a, t_list **stack_b, int size,
		int *norm)
{
	int		*sorted;
	int		chunk_size;
	int		lower;
	int		upper;
	t_chunk	chunk;

	if (check_order_stack(*stack_a))
		return ;
	sorted = copy_array(norm, size);
	sort_array(sorted, size);
	chunk_size = 11;
	lower = 0;
	while (lower < size)
	{
		upper = lower + chunk_size - 1;
		if (upper >= size)
			upper = size - 1;
		chunk.sorted = sorted;
		chunk.lower = lower;
		chunk.upper = upper;
		push_chunk_to_b(stack_a, stack_b, &chunk);
		lower = upper + 1;
	}
	push_back_to_a(stack_a, stack_b);
	free(sorted);
}
