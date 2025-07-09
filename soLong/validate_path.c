#include "so_long.h"

void	dfs(int x, int y, char **copy, t_map *map)
{
	if (y < 0 || x < 0 || y >= map->height || x >= map->width)
		return ;
	if (!copy[y] || !copy[y][x])
		return ;
	if (copy[y][x] == '1' || copy[y][x] == 'X' || copy[y][x] == 'M')
		return ;
	if (copy[y][x] == 'C')
		map->c_found++;
	else if (copy[y][x] == 'E')
		map->e_found = 1;
	copy[y][x] = 'X';
	dfs(x + 1, y, copy, map);
	dfs(x - 1, y, copy, map);
	dfs(x, y + 1, copy, map);
	dfs(x, y - 1, copy, map);
}

char	**copy_map(char **src, int height)
{
	char	**copy;
	int		i;

	copy = malloc(sizeof(char *) * (height + 1));
	if (!copy)
		return (NULL);
	i = 0;
	while (i < height)
	{
		copy[i] = ft_strdup(src[i]);
		if (!copy[i])
		{
			while (i > 0)
				free(copy[--i]);
			free(copy);
			return (NULL);
		}
		i++;
	}
	copy[i] = NULL;
	return (copy);
}

void	validate_path(t_map *map)
{
	char	**map_copy;
	int		i;

	map->c_found = 0;
	map->e_found = 0;
	map_copy = copy_map(map->map, map->height);
	if (!map_copy)
		exit_msg("Error: Copying map failed", map);
	dfs(map->player_x, map->player_y, map_copy, map);
	if (map->c_found != map->collectibles || !map->e_found)
	{
		i = 0;
		while (map_copy[i])
			free(map_copy[i++]);
		free(map_copy);
		exit_msg("Error: No valid path to all collectibles and exit", map);
	}
	i = 0;
	while (map_copy[i])
		free(map_copy[i++]);
	free(map_copy);
}
