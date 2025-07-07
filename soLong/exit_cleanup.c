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

int	handle_close(void *param)
{
	exit_msg("Game closed", (t_map *)param);
	return (0);
}

void	free_all_textures(t_map *map)
{
	int	i;

	if (map->textures.wall.img)
		mlx_destroy_image(map->mlx, map->textures.wall.img);
	if (map->textures.floor.img)
		mlx_destroy_image(map->mlx, map->textures.floor.img);
	if (map->textures.collectible.img)
		mlx_destroy_image(map->mlx, map->textures.collectible.img);
	if (map->textures.exit.img)
		mlx_destroy_image(map->mlx, map->textures.exit.img);
	i = 0;
	while (map->textures.player[i].img && i < 2)
	{
		if (map->textures.player[i].img)
			mlx_destroy_image(map->mlx, map->textures.player[i].img);
		i++;
	}
	i = 0;
	while (map->textures.enemy[i].img && i < 2)
	{
		if (map->textures.enemy[i].img)
			mlx_destroy_image(map->mlx, map->textures.enemy[i].img);
		i++;
	}
}

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
		if (map->mlx)
		{
			free_all_textures(map);
			if (map->win)
				mlx_destroy_window(map->mlx, map->win);
			mlx_destroy_display(map->mlx);
			free(map->mlx);
		}
	}
	if (ft_strncmp(msg, "Error", 5) == 0)
	{
		perror(msg);
		exit(EXIT_FAILURE);
	}
	else
		exit(EXIT_SUCCESS);
}
