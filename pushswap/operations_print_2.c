#include "pushswap.h"

void	ra(t_list **stack_a)
{
	rotate_stack(stack_a);
	ft_printf("ra\n");
}

void	rb(t_list **stack_b)
{
	rotate_stack(stack_b);
	ft_printf("rb\n");
}

void	rra(t_list **stack_a)
{
	reverse_rotate_stack(stack_a);
	ft_printf("rra\n");
}

void	rrb(t_list **stack_b)
{
	reverse_rotate_stack(stack_b);
	ft_printf("rrb\n");
}
