/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptraba-d <ptraba-d@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 15:18:58 by ptraba-d          #+#    #+#             */
/*   Updated: 2025/01/16 15:19:00 by ptraba-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new_entry;

	new_entry = (t_list *)malloc(sizeof(t_list));
	if (!new_entry)
		return (NULL);
	new_entry->content = content;
	new_entry->next = NULL;
	return (new_entry);
}
