#include "ft_printf.h"

int	ft_puthex(unsigned long n, char *base)
{
	char	buffer[16];
	int		i;
	int		count;

	if (n == 0)
		return (ft_putchar('0'));
	i = 0;
	while (n)
	{
		buffer[i++] = base[n % 16];
		n /= 16;
	}
	count = 0;
	while (--i >= 0)
		count += ft_putchar(buffer[i]);
	return (count);
}
