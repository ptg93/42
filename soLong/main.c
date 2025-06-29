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
	// Load game resources, initialize game state, etc.
	// This is a placeholder function for future implementation.
	return (0);
}

void get_map_dimensions(t_map *map, char *buff)
{
	int i;
	int j;

	map->width = 0;
	map->height = 1;
	map->collectibles = 0;
	i = 0;
	while (buff[i] != '\0')
	{
		if (!(buff[i] == '1' || buff[i] == '0' || buff[i] == 'C' ||
			buff[i] == 'E' || buff[i] == 'P'))
			exit_msg("Invalid character in map");
		else if (buff[i] == '\n')
		{
			if (map->height == 1)
				map->width = i + 1;
			else if (map->width != ((i + 1) / map->height))
				exit_msg("Inconsistent row lengths in map");
			map->height++;
		}
		else if (buff[i] == 'C')
			map->collectibles++;
		i++;
	}
}

char **allocate_map(int width, int height)
{
	char **map;
	int i;

	map = malloc(sizeof(char *) * (height + 1));
	if (!map)
		exit_msg("Memory allocation failed for map");
	for (i = 0; i < height; i++)
	{
		map[i] = malloc(sizeof(char) * (width + 1));
		if (!map[i])
			exit_msg("Memory allocation failed for map row");
	}
	map[height] = NULL; // Null-terminate the array of strings
	return (map);
}

int	check_map(int argc, char **argv, t_map *map)
{
	int	fd;
	char *buff [BUFFER_SIZE];

	if (argc != 2)
		exit_msg("Usage: ./so_long <map_file>");
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		exit_msg("Error opening map file");
	if (read(fd, buff, BUFFER_SIZE) < 0)
		exit_msg("Error reading map file");
	close(fd);
	get_map_dimensions(map, buff);
	map->map = allocate_map(map->width, map->height);
	if (!map->map)
		exit_msg("Memory allocation failed for map");
	if (!validate_map(map))
		exit_msg("Invalid map");
	return (1);
}

int	main(int argc, char **argv)
{
	t_map map;

	check_map(argc, argv, &map);
	load_game();
	return (0);
}
