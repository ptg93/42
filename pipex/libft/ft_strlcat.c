/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptraba-d <ptraba-d@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 16:26:22 by ptraba-d          #+#    #+#             */
/*   Updated: 2025/01/13 16:27:37 by ptraba-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t dest_size)
{
	size_t	i;
	size_t	dest_len;
	size_t	src_len;

	src_len = 0;
	while (src[src_len] != '\0')
		src_len ++;
	dest_len = 0;
	while (dest[dest_len] != '\0' && dest_len < dest_size)
		dest_len ++;
	if (dest_size <= dest_len)
		return (dest_size + src_len);
	i = 0;
	while (src[i] != '\0' && dest_len + i < dest_size - 1)
	{
		dest[dest_len + i] = src[i];
		i ++;
	}
	dest[dest_len + i] = '\0';
	return (src_len + dest_len);
}
