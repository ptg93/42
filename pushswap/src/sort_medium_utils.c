#include "pushswap.h"

int	*copy_array(int *array_a, int size)
{
	int		*array_b;
	int		i;

	array_b = malloc(sizeof(int) * (size));
	if (!array_b)
		return (NULL);
	i = 0;
	while (i < size)
	{
		array_b[i] = array_a[i];
		i++;
	}
	return (array_b);
}

void	sort_array(int *array, int size)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (array[i] > array[j])
			{
				tmp = array[i];
				array[i] = array[j];
				array[j] = tmp;
			}
			j++;
		}
		i++;
	}
}

int	find_chunk_position_top(t_list *stack_a, int min, int max)
{
	int		i;
	t_list	*node;

	node = stack_a;
	i = 0;
	while (node)
	{
		if (*(int *)node->content >= min && *(int *)node->content <= max)
			return (i);
		node = node->next;
		i++;
	}
	return (-1);
}

int	find_chunk_position_bottom(t_list *stack_a, int min, int max)
{
	int		i;
	int		pos;
	t_list	*node;

	node = stack_a;
	pos = -1;
	i = 0;
	while (node)
	{
		if (*(int *)node->content >= min && *(int *)node->content <= max)
			pos = i;
		node = node->next;
		i++;
	}
	return (pos);
}

int	find_nearest_chunk_position(t_list *stack_a, int min, int max)
{
	int	pos_top;
	int	pos_bottom;
	int	size;

	pos_top = find_chunk_position_top(stack_a, min, max);
	if (pos_top == -1)
		return (-1);
	pos_bottom = find_chunk_position_bottom(stack_a, min, max);
	size = get_stack_size(stack_a);
	if (pos_top <= (size - 1 - pos_bottom))
		return (pos_top);
	return (pos_bottom);
}
