#include "so_long.h"

void	game_update(t_map *map)
{
	draw_map(map);
	display_score(map);
	if (map->game_over)
		check_game_over(map->game_over, map);
}
