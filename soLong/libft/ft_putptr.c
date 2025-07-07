#include "ft_printf.h"

int	ft_putptr(void *ptr)
{
	unsigned long	p;
	int				count;

	if (!ptr)
		return (ft_putstr("(nil)"));
	count = 0;
	count += ft_putstr("0x");
	p = (unsigned long)ptr;
	count += ft_puthex(p, "0123456789abcdef");
	return (count);
}
