#include "ft_printf.h"

int	format(va_list args, char const *str)
{
	if (*str == 'p')
		return (ft_putptr(va_arg(args, void *)));
	else if (*str == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if (*str == 'i' || *str == 'd')
		return (ft_putnbr(va_arg(args, int)));
	else if (*str == 'c')
		return (ft_putchar(va_arg(args, int)));
	else if (*str == 'u')
		return (ft_put_unsigned(va_arg(args, unsigned int)));
	else if (*str == 'x')
		return (ft_puthex(va_arg(args, unsigned int), "0123456789abcdef"));
	else if (*str == 'X')
		return (ft_puthex(va_arg(args, unsigned int), "0123456789ABCDEF"));
	else
		return (ft_putchar('%'));
}
