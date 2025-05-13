#include <stdlib.h>
#include <limits.h>
#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>
#include <ctype.h>
#include <string.h>

typedef struct s_list {
    void *content;
    struct s_list *next;
} t_list;

t_list	*ft_lstnew(void *content)
{
	t_list *node = malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node->content = content;
	node->next = NULL;
	return (node);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list *temp;
	if (!lst || !new)
		return;
	if (!*lst)
	{
		*lst = new;
		return;
	}
	temp = *lst;
	while (temp->next)
		temp = temp->next;
	temp->next = new;
}

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t i = 0;
	while (i < n && (s1[i] || s2[i]))
	{
		if ((unsigned char)s1[i] != (unsigned char)s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}

int	ft_atoi(const char *str)
{
	int sign = 1;
	long res = 0;
	while (*str && (*str == ' ' || (*str >= 9 && *str <= 13)))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str && ft_isdigit(*str))
	{
		res = res * 10 + (*str - '0');
		str++;
	}
	return ((int)(res * sign));
}

char	*ft_strdup(const char *s)
{
	size_t len = strlen(s);
	char *dup = malloc(len + 1);
	if (!dup)
		return (NULL);
	strcpy(dup, s);
	return (dup);
}

void	ft_printf(const char *format, ...)
{
	va_list args;
	va_start(args, format);
	vprintf(format, args);
	va_end(args);
}

int	ft_is_min(int *a, int c, int len, int nulint)
{
	int i;
	if (c == nulint)
		return (0);
	for (i = 0; i < len; i++)
	{
		if (a[i] != nulint && c > a[i])
			return (0);
	}
	return (1);
}

int	ft_get_min_pos(int *a, int len, int nulint)
{
	int i;
	for (i = 0; i < len; i++)
	{
		if (ft_is_min(a, a[i], len, nulint))
			return (i);
	}
	return (-1);
}

int	create_nulint(int *a, int len)
{
	int i;
	int nulint = INT_MIN;
	while (1)
	{
		for (i = 0; i < len; i++)
		{
			if (a[i] == nulint)
				break;
		}
		if (i == len)
			break;
		nulint++;
	}
	return (nulint);
}

int	*normalize_arr(int *a, int len)
{
	int i, j, nulint;
	int *b;
	nulint = create_nulint(a, len);
	b = malloc(len * sizeof(int));
	if (!b)
		return (NULL);
	for (i = 0; i < len; i++)
	{
		j = ft_get_min_pos(a, len, nulint);
		b[j] = i;
		a[j] = nulint;
	}
	free(a);
	return (b);
}

int	check_order(int *a)
{
	int i = 0;
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

int	check_int_range(const char *str)
{
	long result = 0;
	int sign = 1;
	while ((*str >= 9 && *str <= 13) || *str == ' ')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (ft_isdigit(*str))
	{
		result = result * 10 + (*str - '0');
		str++;
	}
	result *= sign;
	if (result > INT_MAX || result < INT_MIN)
		return (1);
	return (0);
}

int	check_digits(char **argv)
{
	int i = 0, j;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (!ft_isdigit(argv[i][j]))
			{
				if (!(j == 0 && (argv[i][j] == '-' || argv[i][j] == '+')))
					return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	check_duplicates(char **argv)
{
	int i = 1, j;
	while (argv[i])
	{
		j = 1;
		while (j < i)
		{
			if (!ft_strncmp(argv[i], argv[j], 11))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	check_error(char **argv)
{
	int i;
	if (check_digits(argv) || check_duplicates(argv))
		return (1);
	i = 1;
	while (argv[i])
	{
		if (check_int_range(argv[i]))
			return (1);
		i++;
	}
	return (0);
}

void	swap(t_list **stack)
{
	t_list *temp;
	if (!stack || !(*stack) || !((*stack)->next))
		return;
	temp = (*stack)->next;
	(*stack)->next = temp->next;
	temp->next = *stack;
	*stack = temp;
}

void	push(t_list **from_stack, t_list **to_stack)
{
	t_list *temp;
	if (!from_stack || !(*from_stack))
		return;
	temp = *from_stack;
	*from_stack = (*from_stack)->next;
	temp->next = *to_stack;
	*to_stack = temp;
}

void	rotate(t_list **stack)
{
	t_list *first, *last;
	if (!stack || !(*stack) || !((*stack)->next))
		return;
	first = *stack;
	*stack = first->next;
	first->next = NULL;
	last = *stack;
	while (last->next)
		last = last->next;
	last->next = first;
}

void	reverse_rotate(t_list **stack)
{
	t_list *prev = NULL, *last;
	if (!stack || !(*stack) || !((*stack)->next))
		return;
	last = *stack;
	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	if (prev)
		prev->next = NULL;
	last->next = *stack;
	*stack = last;
}

char	**add_op(char **solution, char *instruction)
{
	int count = 0, i = 0;
	char **new_solution;
	if (solution)
	{
		while (solution[count])
			count++;
	}
	new_solution = malloc((count + 2) * sizeof(char *));
	if (!new_solution)
		return (NULL);
	for (i = 0; i < count; i++)
		new_solution[i] = solution[i];
	new_solution[i] = ft_strdup(instruction);
	new_solution[i + 1] = NULL;
	if (solution)
		free(solution);
	return (new_solution);
}

t_list	*populate_stack(int *a, int len)
{
	t_list *stack;
	t_list *node;
	int i = 0;
	stack = ft_lstnew(&a[i]);
	while (++i < len)
	{
		node = ft_lstnew(&a[i]);
		ft_lstadd_back(&stack, node);
	}
	return (stack);
}

void	sort_small(t_list **stack_a, t_list **stack_b, int len, char ***ops)
{
	(void)stack_b;
	int a, b, c;
	if (len == 2)
	{
		if (*((int *)((*stack_a)->content)) > *((int *)((*stack_a)->next->content)))
		{
			swap(stack_a);
			*ops = add_op(*ops, "sa");
		}
	}
	else if (len == 3)
	{
		a = *((int *)((*stack_a)->content));
		b = *((int *)((*stack_a)->next->content));
		c = *((int *)((*stack_a)->next->next->content));
		if (a > b && b < c && a < c)
		{
			swap(stack_a);
			*ops = add_op(*ops, "sa");
		}
		else if (a > b && b > c)
		{
			swap(stack_a);
			*ops = add_op(*ops, "sa");
			reverse_rotate(stack_a);
			*ops = add_op(*ops, "rra");
		}
		else if (a > b && b < c && a > c)
		{
			rotate(stack_a);
			*ops = add_op(*ops, "ra");
		}
		else if (a < b && b > c && a < c)
		{
			swap(stack_a);
			*ops = add_op(*ops, "sa");
			rotate(stack_a);
			*ops = add_op(*ops, "ra");
		}
		else if (a < b && b > c && a > c)
		{
			reverse_rotate(stack_a);
			*ops = add_op(*ops, "rra");
		}
	}
}

void	push_phase(t_list **stack_a, t_list **stack_b, int total, int chunk, int *current, char ***ops)
{
	(void)total;
	while (*stack_a)
	{
		if (*((int *)((*stack_a)->content)) <= *current)
		{
			push(stack_a, stack_b);
			*ops = add_op(*ops, "pb");
			(*current)++;
		}
		else if (*((int *)((*stack_a)->content)) <= *current + chunk)
		{
			push(stack_a, stack_b);
			*ops = add_op(*ops, "pb");
			rotate(stack_b);
			*ops = add_op(*ops, "rb");
			(*current)++;
		}
		else
		{
			rotate(stack_a);
			*ops = add_op(*ops, "ra");
		}
	}
}

void	restore_phase(t_list **stack_a, t_list **stack_b, char ***ops)
{
	int max, max_pos, size;
	while (*stack_b)
	{
		max = *((int *)((*stack_b)->content));
		max_pos = 0;
		size = 0;
		{
			int pos = 0;
			t_list *tmp = *stack_b;
			while (tmp)
			{
				if (*((int *)tmp->content) > max)
				{
					max = *((int *)tmp->content);
					max_pos = pos;
				}
				size++;
				pos++;
				tmp = tmp->next;
			}
		}
		if (max_pos <= size / 2)
		{
			while (max_pos-- > 0)
			{
				rotate(stack_b);
				*ops = add_op(*ops, "rb");
			}
		}
		else
		{
			max_pos = size - max_pos;
			while (max_pos-- > 0)
			{
				reverse_rotate(stack_b);
				*ops = add_op(*ops, "rrb");
			}
		}
		push(stack_b, stack_a);
		*ops = add_op(*ops, "pa");
	}
}

void	sort_large(t_list **stack_a, t_list **stack_b, int len, char ***ops)
{
	int total = len;
	int chunks = (total <= 100) ? 5 : 10;
	int chunk = total / chunks;
	int current = 0;
	push_phase(stack_a, stack_b, total, chunk, &current, ops);
	restore_phase(stack_a, stack_b, ops);
}

void	push_swap(int *a, int len)
{
	t_list *stack_a, *stack_b;
	char **ops = NULL;
	a = normalize_arr(a, len);
	stack_a = populate_stack(a, len);
	stack_b = NULL;
	if (len <= 3)
		sort_small(&stack_a, &stack_b, len, &ops);
	else
		sort_large(&stack_a, &stack_b, len, &ops);
	{
		int i = 0;
		while (ops && ops[i])
		{
			ft_printf("%s\n", ops[i]);
			i++;
		}
	}
	if (ops)
	{
		int i = 0;
		while (ops[i])
		{
			free(ops[i]);
			i++;
		}
		free(ops);
	}
}

int	main(int argc, char **argv)
{
	int *a;
	int i;
	if (argc < 2 || check_error(argv + 1))
	{
		ft_printf("Error\n");
		return (0);
	}
	a = malloc((argc - 1) * sizeof(int));
	if (!a)
		return (0);
	for (i = 1; i < argc; i++)
		a[i - 1] = ft_atoi(argv[i]);
	push_swap(a, argc - 1);
	return (0);
}

