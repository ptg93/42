/*char **allocate_map(int width, int height)
{
	char **map;
	int i;

	map = malloc(sizeof(char *) * (height + 1));
	if (!map)
		exit_msg("Memory allocation failed for map");
	i = 0;
	while (i < height)
	{
		map[i] = malloc(sizeof(char) * (width + 1));
		if (!map[i])
			exit_msg("Memory allocation failed for map row");
		i++;
	}
	map[height] = NULL; // Null-terminate the array of strings
	return (map);
}*/

	//map->map = allocate_map(map->width, map->height);
