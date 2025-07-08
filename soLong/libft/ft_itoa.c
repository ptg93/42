/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptraba-d <ptraba-d@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 15:56:32 by ptraba-d          #+#    #+#             */
/*   Updated: 2025/01/16 15:55:14 by ptraba-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_num_len(int n)
{
	size_t	len;

	len = 1;
	if (n < 0)
		len++;
	while (n / 10 != 0)
	{
		len++;
		n /= 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char			*s;
	size_t			len;
	unsigned int	num;
	size_t			i;

	len = get_num_len(n);
	s = malloc(len + 1);
	if (!s)
		return (NULL);
	s[len] = '\0';
	if (n < 0)
	{
		s[0] = '-';
		num = -n;
	}
	else
		num = n;
	i = len;
	while (i-- > 0 && s[i] != '-')
	{
		s[i] = (num % 10) + '0';
		num /= 10;
	}
	return (s);
}
