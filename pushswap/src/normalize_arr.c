/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize_arr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptraba-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 17:38:57 by ptraba-d          #+#    #+#             */
/*   Updated: 2025/07/14 17:38:58 by ptraba-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	ft_is_min(int *a, int c, int len, int nulint)
{
	int	i;

	if (c == nulint)
		return (0);
	i = 0;
	while (i < len)
	{
		if (a[i] != nulint && c > a[i])
			return (0);
		i++;
	}
	return (1);
}

int	ft_get_min_pos(int *a, int len, int nulint)
{
	int	i;

	i = 0;
	while (i < len)
	{
		if (ft_is_min(a, a[i], len, nulint))
			return (i);
		i++;
	}
	return (-1);
}

int	create_nulint(int *a, int len)
{
	int	i;
	int	nulint;

	nulint = INT_MIN;
	while (1)
	{
		i = 0;
		while (i < len)
		{
			if (a[i] == nulint)
				break ;
			i++;
		}
		if (i == len)
			break ;
		nulint++;
	}
	return (nulint);
}

int	*normalize_arr(int *a, int len)
{
	int	i;
	int	*b;
	int	j;
	int	nulint;

	nulint = create_nulint(a, len);
	b = malloc((len) * sizeof(int));
	if (!b)
		return (NULL);
	i = 0;
	while (i < len)
	{
		j = ft_get_min_pos(a, len, nulint);
		b[j] = i;
		a[j] = nulint;
		i++;
	}
	return (b);
}
