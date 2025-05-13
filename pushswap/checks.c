#include "pushswap.h"

int	check_order(int *a)
{
	int	i;

	i = 0;
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
	long	result;
	int		sign;

	result = 0;
	sign = 1;
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
	int	i;
	int	j;

	i = 0;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
    		if (!ft_isdigit(argv[i][j]))
			{
				if(!(j == 0 && (argv[i][j] == '-' || argv[i][j] == '+')))
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
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = 1;
		while (j < i)
		{
			if (ft_strncmp(argv[i], argv[j], 11))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
	
int	check_error(char **argv)
{
	int	i;

	if (check_digits(argv) || check_duplicates(argv))
		return (1);
	i = 1;
	while (argv[i])
	{
		if(check_int_range(argv[i]))
			return (1);
		i++;
	}
	return (0);
}
