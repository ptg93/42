#include "so_long.h"

int	handle_keypress(int keycode, t_map *map)
{
	if (keycode == 65307)
		exit_msg("Game closed", map);
	if (map->game_over)
		return (0);
	if (keycode == 119)
		move_player(map, 0, -1);
	else if (keycode == 115)
		move_player(map, 0, 1);
	else if (keycode == 97)
		move_player(map, -1, 0);
	else if (keycode == 100)
		move_player(map, 1, 0);
	return (0);
}
