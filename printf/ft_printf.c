#include "ft_printf.h"
#include <stdarg.h>

int	ft_printf(char const *str, ...)
{
	int		count;
	va_list	args;

	va_start(args, str);
	count = 0;
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			count += format(args, str);
		}
		else
			count += ft_putchar(*str);
		str++;
	}
	va_end(args);
	return (count);
}

/*
#include <stdio.h>

int main() {
    ft_printf(" %p %p \n", NULL, NULL);
    printf(" %p %p \n", NULL, NULL);
    return 0;
}
*/
