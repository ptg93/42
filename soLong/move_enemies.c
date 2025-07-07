#include "so_long.h"

void	update_enemy_position(t_map *map, int i, int new_x, int new_y)
{
	t_enemy	*enemy;

	enemy = &map->enemies[i];
	map->map[enemy->y][enemy->x] = '0';
	map->map[new_y][new_x] = 'M';
	enemy->x = new_x;
	enemy->y = new_y;
}

void	process_enemy_move(t_map *map, int i, int danger, int r)
{
	int		new_x;
	int		new_y;
	t_enemy	*enemy;

	enemy = &map->enemies[i];
	new_x = enemy->x + map->dx[r];
	new_y = enemy->y + map->dy[r];
	if (enemy_can_move_to(map, new_x, new_y, *enemy))
	{
		if (danger && map->player_x == new_x && map->player_y == new_y)
			map->game_over = 2;
		update_enemy_position(map, i, new_x, new_y);
	}
}

void	move_enemies(int danger, t_map *map)
{
	int	i;
	int	r;

	i = 0;
	while (i < map->enemy_count)
	{
		r = pseudo_random(map->moves + i);
		process_enemy_move(map, i, danger, r);
		i++;
	}
}
