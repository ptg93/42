/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptraba-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 11:34:34 by ptraba-d          #+#    #+#             */
/*   Updated: 2025/07/09 11:35:30 by ptraba-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	display_score(t_map *map)
{
	char	*moves_str;
	char	*display_str;

	moves_str = ft_itoa(map->moves);
	display_str = ft_strjoin("Moves: ", moves_str);
	free(moves_str);
	mlx_string_put(map->mlx, map->win,
		map->width * 32 - (ft_strlen(display_str) * 10),
		20, 0x000000, display_str);
	free(display_str);
}

void	check_game_over(int type, t_map *map)
{
	map->game_over = type;
	if (type == 1)
		mlx_string_put(map->mlx, map->win,
			(map->width * 32) / 2 - 40,
			(map->height * 32) / 2,
			0xFF0000, "You won! Press ESC");
	else if (type == 2)
		mlx_string_put(map->mlx, map->win,
			(map->width * 32) / 2 - 70,
			(map->height * 32) / 2,
			0xFF0000, "You were caught! Press ESC");
}
