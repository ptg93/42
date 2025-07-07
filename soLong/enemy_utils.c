#include "so_long.h"

int	pseudo_random(int seed)
{
	return ((seed * 37 + 17) % 4);
}

int	enemy_can_move_to(t_map *map, int x, int y, t_enemy enemy)
{
	int	dist_x;
	int	dist_y;

	dist_x = abs(x - enemy.start_x);
	dist_y = abs(y - enemy.start_y);
	return (
		x >= 0 && x < map->width
		&& y >= 0 && y < map->height
		&& map->map[y][x] != '1' &&
		map->map[y][x] != 'E' &&
		map->map[y][x] != 'C' &&
		dist_x + dist_y <= 2
	);
}

void	move_enemy(t_map *map, int i, int new_x, int new_y)
{
	t_enemy	*e;

	e = &map->enemies[i];
	map->map[e->y][e->x] = '0';
	map->map[new_y][new_x] = 'M';
	e->x = new_x;
	e->y = new_y;
}
