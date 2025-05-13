#include "ft_printf.h"

int	ft_put_unsigned(unsigned int n)
{
	int	count;

	count = 0;
	if (n > 9)
		count += ft_put_unsigned(n / 10);
	count += ft_putchar((n % 10) + '0');
	return (count);
}
