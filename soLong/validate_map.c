#include "so_long.h"

static void	validate_borders(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->width)
	{
		if (map->map[0][i] != '1' || map->map[map->height - 1][i] != '1')
			exit_msg("Error: Map must be surrounded by walls", map);
		i++;
	}
	i = 0;
	while (i < map->height)
	{
		if (map->map[i][0] != '1' || map->map[i][map->width - 1] != '1')
			exit_msg("Error: Map must be surrounded by walls", map);
		i++;
	}
}

static void	add_instance(t_map *map, int x, int y)
{
	if (map->map[y][x] == 'P')
	{
		map->player_x = x;
		map->player_y = y;
		map->player_count++;
	}
	else if (map->map[y][x] == 'E')
	{
		map->exit_x = x;
		map->exit_y = y;
		map->exit_count++;
	}
	else if (map->map[y][x] == 'C')
		map->collectibles++;
	else if (map->map[y][x] == 'M' && map->enemy_count > 0 && map->enemies)
	{
		map->enemies[map->enemy_index].x = x;
		map->enemies[map->enemy_index].y = y;
		map->enemies[map->enemy_index].start_x = x;
		map->enemies[map->enemy_index].start_y = y;
		map->enemy_index++;
	}
}

static void	get_map_variables(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->height)
	{
		if ((int)ft_strlen(map->map[i]) != map->width)
			exit_msg("Error: Map rows must be of equal length", map);
		j = 0;
		while (j < map->width)
		{
			add_instance(map, j, i);
			j++;
		}
		i++;
	}
}

static void	initialize_map_variables(t_map *map)
{
	map->width = 0;
	map->height = 0;
	map->player_x = -1;
	map->player_y = -1;
	map->exit_x = -1;
	map->exit_y = -1;
	map->collectibles = 0;
	map->moves = 0;
	map->game_over = 0;
	map->enemy_index = 0;
	map->player_count = 0;
	map->exit_count = 0;
	map->c_found = 0;
	map->e_found = 0;
	map->dx[0] = 0;
	map->dx[1] = 0;
	map->dx[2] = -1;
	map->dx[3] = 1;
	map->dy[0] = -1;
	map->dy[1] = 1;
	map->dy[2] = 0;
	map->dy[3] = 0;
}

int	validate_map(t_map *map)
{
	initialize_map_variables(map);
	while (map->map[map->height])
		map->height++;
	if (map->height == 0)
		return (0);
	ft_printf("Map height: %d\n", map->height);
	map->width = ft_strlen(map->map[0]);
	ft_printf("First row width: %d\n", map->width);
	get_map_variables(map);
	ft_printf("Map width: %d\n", map->width);
	ft_printf("Player count: %d, Exit count: %d, Collectibles: %d\n",
		map->player_count, map->exit_count, map->collectibles);
	if (map->player_count != 1 || map->exit_count != 1 || map->collectibles < 1)
		return (0);
	validate_borders(map);
	validate_path(map);
	return (1);
}
