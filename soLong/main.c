#include "so_long.h"
#include "minilibx-linux/mlx.h"

int	handle_close(void *param)
{
	(void)param;
	exit(0);
}

int	load_game()
{
	void	*mlx;
	void	*win;
	void	*img;
	int		img_width;
	int		img_height;

	mlx = mlx_init();
	if (!mlx)
		return (1);
	win = mlx_new_window(mlx, 800, 600, "so_long");
	if (!win)
		return (1);
	img = mlx_xpm_file_to_image(mlx, "llama.xpm", &img_width, &img_height);
	if (!img)
		return (1);
	mlx_put_image_to_window(mlx, win, img, 100, 100);
	mlx_hook(win, 17, 0, handle_close, NULL);
	mlx_loop(mlx);
	return (0);
}

void	dfs(char **map, int x, int y, int *c_found, int *e_found)
{
	if (map[y][x] == '1' || map[y][x] == 'X')
		return ;
	if (map[y][x] == 'C')
		(*c_found)++;
	else if (map[y][x] == 'E')
		*e_found = 1;
	map[y][x] = 'X';
	dfs(map, x + 1, y, c_found, e_found);
	dfs(map, x - 1, y, c_found, e_found);
	dfs(map, x, y + 1, c_found, e_found);
	dfs(map, x, y - 1, c_found, e_found);
}

char	**copy_map(t_map *src, int height)
{
	char	**copy;
	int		i;

	copy = malloc(sizeof(char *) * (height + 1));
	if (!copy)
		exit_msg("Error copying map", src);
	i = 0;
	while (i < height)
	{
		copy[i] = ft_strdup(src->map[i]);
		if (!copy[i])
			exit_msg("Error copying map row", src);
		i++;
	}
	copy[i] = NULL;
	return (copy);
}

void	validate_path(t_map *map)
{
	char	**map_copy;
	int		c_found;
	int		e_found;

	map_copy = copy_map(map->map, map->height);
	c_found = 0;
	e_found = 0;
	dfs(map_copy, map->player_x, map->player_y, &c_found, &e_found);
	if (c_found != map->collectibles || !e_found)
	{
		int i = 0;
		while (map_copy[i])
			free(map_copy[i++]);
		free(map_copy);
		exit_msg("No valid path to all collectibles and exit", map);
	}
	int i = 0;
	while (map_copy[i])
		free(map_copy[i++]);
	free(map_copy);
}

void validate_borders(t_map *map)
{
	int i;

	i = 0;
	while (i < map->width)
	{
		if (map->map[0][i] != '1' || map->map[map->height - 1][i] != '1')
			exit_msg("Map must be surrounded by walls", map);
		i++;
	}
	i = 0;
	while (i < map->height)
	{
		if (map->map[i][0] != '1' || map->map[i][map->width - 1] != '1')
			exit_msg("Map must be surrounded by walls", map);
		i++;
	}
}

int	validate_map(t_map *map)
{
	int i;
	int j;
	int player_count;
	int exit_count;

	map->collectibles = 0;
	player_count = 0;
	exit_count = 0;
	map->height = 0;
	while (map->map[map->height])
		map->height++;
	if (map->height == 0)
		return (0);
	map->width = ft_strlen(map->map[0]);
	i = 0;
	while (i < map->height)
	{
		if (ft_strlen(map->map[i]) != map->width)
			return (0);
		j = 0;
		while (j < map->width)
		{
			if (map->map[i][j] == 'P')
			{
				player_count++;
				map->player_x = j;
				map->player_y = i;
			}
			else if (map->map[i][j] == 'E')
			{
				exit_count++;
				map->exit_x = j;
				map->exit_y = i;
			}
			else if (map->map[i][j] == 'C')
				map->collectibles++;
			j++;
		}
		i++;
	}
	if (player_count != 1 || exit_count != 1 || map->collectibles < 1)
		return (0);
	validate_borders(map);
	validate_path(map);
	return (1);
}

void check_characters(char *buff, t_map *map)
{
	int i;

	i = 0;
	while (buff[i] != '\0')
	{
		if (!ft_strchr(MAP_CHARS, buff[i]) && buff[i] != '\n')
			exit_msg("Invalid character in map", map);
		i++;
	}
}

int	check_map(int argc, char **argv, t_map *map)
{
	int	fd;
	char buff [BUFFER_SIZE + 1];

	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		exit_msg("Error opening map file", map);
	if (read(fd, buff, BUFFER_SIZE) < 0)
		exit_msg("Error reading map file", map);
	buff[BUFFER_SIZE] = '\0';
	close(fd);
	check_characters(buff, map);
	map->map = ft_split(buff, '\n');
	if (!map->map)
		exit_msg("Error splitting map into lines", map);
	if (map->map[0] == NULL)
		exit_msg("Map is empty", map);
	if (!validate_map(map))
		exit_msg("Invalid map", map);
	return (1);
}

int	main(int argc, char **argv)
{
	t_map map;

	if (argc != 2)
		exit_msg("Usage: ./so_long <map_file>", &map);
	if (ft_strncmp(argv[1] + ft_strlen(argv[1]) - 4, ".ber", 4) != 0)
		exit_msg("Map file must have a .ber extension", &map);
	check_map(argc, argv, &map);
	load_game();
	return (0);
}
