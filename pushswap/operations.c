#include "pushswap.h"

void	swap_stack(t_list **stack)
{
	t_list	*temp;

	if (!stack || !(*stack) || !((*stack)->next))
		return ;
	temp = (*stack)->next;
	(*stack)->next = temp->next;
	temp->next = *stack;
	*stack = temp;
}

void	push_stack(t_list **from_stack, t_list **to_stack)
{
	t_list	*temp;

	if (!from_stack || !(*from_stack))
		return ;
	temp = *from_stack;
	*from_stack = (*from_stack)->next;
	temp->next = *to_stack;
	*to_stack = temp;
}

void	rotate_stack(t_list **stack)
{
	t_list	*first;
	t_list	*last;

	if (!stack || !(*stack) || !((*stack)->next))
		return ;
	first = *stack;
	*stack = first->next;
	first->next = NULL;
	last = *stack;
	while (last->next)
		last = last->next;
	last->next = first;
}

void	reverse_rotate_stack(t_list **stack)
{
	t_list	*prev;
	t_list	*last;

	if (!stack || !(*stack) || !((*stack)->next))
		return ;
	prev = NULL;
	last = *stack;
	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	prev->next = NULL;
	last->next = *stack;
	*stack = last;
}
