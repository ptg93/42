#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "libft/libft.h"
#include "ft_printf/ft_printf.h"
#include <limits.h>
#include "pushswap.h"

void swap(t_list **stack)
{
	t_list	*temp;

	temp = (*stack)->next;
	(*stack)->next = temp->next;
	temp->next = *stack;
	*stack = temp;
}

void push(t_list **from_stack, t_list **to_stack)
{
	t_list	*temp;

	if (!from_stack || !(*from_stack))
		return;
	temp = *from_stack;
	*from_stack = (*from_stack)->next;
	temp->next = *to_stack;
	*to_stack = temp;  
}

void	rotate(t_list **stack)
{
	if (!stack || !(*stack) || !((*stack)->next))
		return;
	t_list	*first = *stack;
	*stack = first->next;
	first->next = NULL;
	t_list	*last = *stack;
	while (last->next)
		last = last->next;
	last->next = first;
}

void	reverse_rotate(t_list **stack)
{
	if (!stack || !(*stack) || !((*stack)->next))
		return;
	t_list	*prev = NULL;
	t_list	*last = *stack;
	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	prev->next = NULL;
	last->next = *stack;
	*stack = last;
}

void sort_small(t_list **stack_a, t_list **stack_b, int len)
{
	if (len == 2)
		swap(stack_a);
	if (len == 3)
	{


}

void sort_large(t_list **stack_a, t_list **stack_b, int len);
char **add_op(char **solution, char *instruction)
{
	int	count;
	char	**new_solution;
	int	i;

	count = 0;
	if (solution)
	{
		while (solution[count])
				count++;
	}
	new_solution = malloc((count + 2) * sizeof(char *));
	if (!new_solution)
		return NULL;
	i = 0;
	while (i++ < count)
		new_solution[i] = solution[i];
	new_solution[i] = ft_strdup(instruction);
	new_solution[i + 1] = '\0';
	if (solution)
		free(solution);
	return (new_solution);
}

t_list	*populate_stack(int *a, int len)
{
	t_list	*stack;
	t_list	*node;
	int		i;

	i = 0;
	stack = ft_lstnew(&a[i]);
	while (++i < len)
	{
		node = ft_lstnew(&a[i]);
		ft_lstadd_back(&stack, node);
	}
	return (stack);
}

void	push_swap(int *a, int len)
{
	int	i;
	t_list	*stack_a;
	t_list	*stack_b;
	//char	**solution;

	/*i = 0;
	while (i < len)
	{
		ft_printf("%i \n", a[i]);
		i++;
	}*/
	a = normalize_arr(a, len);
	/*i = 0;
	while (i < len)
	{
		ft_printf("Normalized: %i \n", a[i]);
		i++;
	}*/
	stack_a = populate_stack(a, len);
	/*i = 0;
	stack_b = stack_a;
	while (i++ < len)
	{
		ft_printf("Stacked: %i \n", *(int *)stack_b->content);
		stack_b = stack_b->next;
	}*/

}

int	main(int argc, char **argv)
{
	int	*a;
	int	i;

	if (argc < 2 || !check_error(argv))
	{
		ft_printf("Error\n");
		return (0);
	}
	a = malloc((argc - 1) * sizeof(int));
	if (!a)
		return (0);
	i = 1;
	while (argv[i])
	{
		a[i - 1] = ft_atoi(argv[i]);
		i++;
	}
	push_swap(a, argc - 1);
}
