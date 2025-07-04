/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_msg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptraba-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 16:52:59 by ptraba-d          #+#    #+#             */
/*   Updated: 2025/07/03 16:53:00 by ptraba-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <fcntl.h>
#include <stdio.h>  // For perror
#include <unistd.h> // For close
#include <stdlib.h> // For exit
#include <string.h> // For strerror

void	free_map(char **map)
{
	int	i;

	if (!map)
		return ;
	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	exit_msg(const char *msg, t_map *map)
{
	if (map)
	{
		if (map->map)
			free_map(map->map);
		if (map->win)
			mlx_destroy_window(map->mlx, map->win);
		if (map->mlx)
			mlx_destroy_display(map->mlx); // Linux
	}
	if (msg)
		perror(msg);
	exit(EXIT_FAILURE);
}

