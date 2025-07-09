#include "so_long.h"

int	pseudo_random(int seed)
{
	return ((seed * 37 + 17) % 4);
}

int	enemy_can_move_to(t_map *map, int x, int y, t_enemy enemy)
{
	int	dist_x;
	int	dist_y;

	if (x < 0 || x >= map->width || y < 0 || y >= map->height)
		return (0);
	if (map->map[y][x] == '1' || map->map[y][x] == 'E')
		return (0);
	if (map->map[y][x] == 'C')
		return (0);
	dist_x = abs(x - enemy.start_x);
	dist_y = abs(y - enemy.start_y);
	if (dist_x + dist_y > 2)
		return (0);
	return (1);
}
