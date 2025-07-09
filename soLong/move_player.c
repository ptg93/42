/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptraba-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 11:37:16 by ptraba-d          #+#    #+#             */
/*   Updated: 2025/07/09 11:37:17 by ptraba-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	is_valid_move(t_map *map, int x, int y)
{
	if (x < 0 || x >= map->width || y < 0 || y >= map->height)
		return (0);
	if (map->map[y][x] == '1')
		return (0);
	return (1);
}

static void	update_position(t_map *map, int new_x, int new_y)
{
	if (map->player_x == map->exit_x && map->player_y == map->exit_y)
		map->map[map->player_y][map->player_x] = 'E';
	else
		map->map[map->player_y][map->player_x] = '0';
	map->player_x = new_x;
	map->player_y = new_y;
	map->map[new_y][new_x] = 'P';
	map->moves++;
	ft_printf("Moves: %d\n", map->moves);
}

static void	check_collectibles(t_map *map, int new_x, int new_y)
{
	if (map->map[new_y][new_x] == 'C')
	{
		map->collectibles--;
		ft_printf("Collectible found! Remaining: %d\n", map->collectibles);
	}
}

int	move_player(t_map *map, int dx, int dy)
{
	int	new_x;
	int	new_y;

	new_x = map->player_x + dx;
	new_y = map->player_y + dy;
	map->player_prev_x = map->player_x;
	map->player_prev_y = map->player_y;
	if (!is_valid_move(map, new_x, new_y))
		return (0);
	check_collectibles(map, new_x, new_y);
	update_position(map, new_x, new_y);
	move_enemies(map);
	if (map->player_x == map->exit_x && map->player_y == map->exit_y
		&& map->collectibles == 0)
	{
		map->game_over = 1;
		ft_printf("You won in %d moves!\n", map->moves);
	}
	game_update(map);
	return (1);
}
