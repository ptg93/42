#include "pushswap.h"

void	sort_two_elements(t_list **stack_a)
{
	int	first;
	int	second;

	first = *((int *)((*stack_a)->content));
	second = *((int *)((*stack_a)->next->content));
	if (first > second)
		sa(stack_a);
}

void	sort_three_elements(t_list **stack_a)
{
	int	first;
	int	second;
	int	third;

	first = *((int *)((*stack_a)->content));
	second = *((int *)((*stack_a)->next->content));
	third = *((int *)((*stack_a)->next->next->content));
	if (first > second && second < third && first < third)
		sa(stack_a);
	else if (first > second && second > third)
	{
		sa(stack_a);
		rra(stack_a);
	}
	else if (first > second && second < third && first > third)
		ra(stack_a);
	else if (first < second && second > third && first < third)
	{
		sa(stack_a);
		ra(stack_a);
	}
	else if (first < second && second > third && first > third)
		rra(stack_a);
}

void	sort_four_elements(t_list **stack_a, t_list **stack_b)
{
	int	min_pos;
	int	size;

	min_pos = find_min_position(*stack_a);
	size = get_stack_size(*stack_a);
	if (min_pos <= size / 2)
	{
		while (min_pos-- > 0)
			ra(stack_a);
	}
	else
	{
		while (min_pos++ < size)
			rra(stack_a);
	}
	pb(stack_a, stack_b);
	sort_three_elements(stack_a);
	pa(stack_a, stack_b);
}

void	sort_five_elements(t_list **stack_a, t_list **stack_b)
{
	int	min_pos;
	int	size;

	min_pos = find_min_position(*stack_a);
	size = get_stack_size(*stack_a);
	if (min_pos <= size / 2)
	{
		while (min_pos-- > 0)
			ra(stack_a);
	}
	else
	{
		while (min_pos++ < size)
			rra(stack_a);
	}
	pb(stack_a, stack_b);
	sort_four_elements(stack_a, stack_b);
	pa(stack_a, stack_b);
}
