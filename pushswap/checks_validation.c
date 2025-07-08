#include "pushswap.h"

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
		if (!argv[i][0])
			return (1);
		j = 0;
		if (argv[i][j] == '-' || argv[i][j] == '+')
		{
			j++;
			if (!argv[i][j])
				return (1);
		}
		while (argv[i][j])
		{
			if (!ft_isdigit(argv[i][j]))
				return (1);
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

	i = 0;
	while (argv[i])
	{
		if (check_int_range(argv[i]))
			return (1);
		j = 0;
		while (j < i)
		{
			if (check_int_range(argv[j]))
				return (1);
			if (ft_atoi(argv[i]) == ft_atoi(argv[j]))
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
	i = 0;
	while (argv[i])
	{
		if (check_int_range(argv[i]))
			return (1);
		i++;
	}
	return (0);
}
