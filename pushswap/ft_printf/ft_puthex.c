/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptraba-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 12:59:21 by ptraba-d          #+#    #+#             */
/*   Updated: 2025/04/11 12:59:23 by ptraba-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
