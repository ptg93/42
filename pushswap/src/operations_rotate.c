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

void	rr(t_list **stack_a, t_list **stack_b)
{
	rotate_stack(stack_a);
	rotate_stack(stack_b);
	ft_printf("rr\n");
}
