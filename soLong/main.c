/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptraba-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 16:52:03 by ptraba-d          #+#    #+#             */
/*   Updated: 2025/07/03 16:52:13 by ptraba-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "minilibx-linux/mlx.h"

int move_player(t_map *map, int dx, int dy)
{
	int new_x = map->player_x + dx;
	int new_y = map->player_y + dy;

	if (new_x < 0 || new_x >= map->width || new_y < 0 || new_y >= map->height)
		return (0);
	if (map->map[new_y][new_x] == '1') // Wall
		return (0);
	if (map->map[new_y][new_x] == 'C') // Collectible
	{
		map->collectibles--;
		printf("Collectible found! Remaining: %d\n", map->collectibles);
	}
	if (map->map[map->player_y][map->player_x] == map->map[map->exit_y][map->exit_x])
		map->map[map->player_y][map->player_x] = 'E'; // Clear old position
	else
		map->map[map->player_y][map->player_x] = '0';
	map->player_x = new_x;
	map->player_y = new_y;
	map->moves++;
	map->map[map->player_y][map->player_x] = 'P'; // Set new position
	printf("Moves: %d\n", map->moves);
	if ((map->player_x == map->exit_x && map->player_y == map->exit_y) && map->collectibles == 0)
	{
		map->game_over = 1;
		printf("You won in %d moves!\n", map->moves);
	}
	draw_map(map);
	return (1);
}

int	handle_keypress(int keycode, t_map *map)
{
	if (keycode == 65307) // ESC
		exit_msg("Game closed", map);
	else if (map->game_over)
		return (0);
	else if (keycode == 119) // W
		move_player(map, 0, -1);
	else if (keycode == 115) // S
		move_player(map, 0, 1);
	else if (keycode == 97)  // A
		move_player(map, -1, 0);
	else if (keycode == 100) // D
		move_player(map, 1, 0);
	return (0);
}

void display_score(t_map *map)
{
	char	*moves_str;
	char	*display_str;

	moves_str = ft_itoa(map->moves);
	display_str = ft_strjoin("Moves: ", moves_str);
	free(moves_str);
	mlx_string_put(map->mlx, map->win,
		map->width * 32 - (ft_strlen(display_str) * 10),
		20,
		0x000000,
		display_str);

	free(display_str);
}

void draw_map(t_map *map)
{
	int x;
	int y;
	int sprite_index = map->moves % 2;

	y = 0;
	while(y < map->height)
	{
		x = 0;
		while(x < map->width)
		{
			mlx_put_image_to_window(map->mlx, map->win, map->textures.floor.img, x * 32, y * 32);
			if (map->map[y][x] == '1')
				mlx_put_image_to_window(map->mlx, map->win, map->textures.wall.img, x * 32, y * 32);
			else if (map->map[y][x] == 'C')
				mlx_put_image_to_window(map->mlx, map->win, map->textures.collectible.img, x * 32, y * 32);
			else if (map->map[y][x] == 'E')
				mlx_put_image_to_window(map->mlx, map->win, map->textures.exit.img, x * 32, y * 32);
			else if (map->map[y][x] == 'P')
				mlx_put_image_to_window(map->mlx, map->win, map->textures.player[sprite_index].img, x * 32, y * 32);
			x++;
		}
		y++;
	}
	display_score(map);
	if (map->game_over)
		mlx_string_put(map->mlx, map->win,
	(map->width * 32) / 2 - 40,
	(map->height * 32) / 2,
	0xFF0000,
	"You won! Press ESC");
}

void load_textures(t_map *map)
{
	map->textures.wall.img = mlx_xpm_file_to_image(map->mlx, "textures/wall.xpm", &map->textures.wall.width, &map->textures.wall.height);
	if (!map->textures.wall.img)
		exit_msg("Error loading wall texture", map);
	map->textures.floor.img = mlx_xpm_file_to_image(map->mlx, "textures/floor.xpm", &map->textures.floor.width, &map->textures.floor.height);
	if (!map->textures.floor.img)
		exit_msg("Error loading floor texture", map);
	map->textures.collectible.img = mlx_xpm_file_to_image(map->mlx, "textures/collectible.xpm", &map->textures.collectible.width, &map->textures.collectible.height);
	if (!map->textures.collectible.img)
		exit_msg("Error loading collectible texture", map);
	map->textures.exit.img = mlx_xpm_file_to_image(map->mlx, "textures/exit.xpm", &map->textures.exit.width, &map->textures.exit.height);
	if (!map->textures.exit.img)
		exit_msg("Error loading exit texture", map);
	map->textures.player[0].img  = mlx_xpm_file_to_image(map->mlx, "textures/player.xpm", &map->textures.player[0].width, &map->textures.player[0].height);
	if (!map->textures.player[0].img)
		exit_msg("Error loading player texture", map);
	map->textures.player[1].img  = mlx_xpm_file_to_image(map->mlx, "textures/player.xpm", &map->textures.player[1].width, &map->textures.player[1].height);
	if (!map->textures.player[1].img)
		exit_msg("Error loading player texture", map);
}

int	load_game(t_map *map)
{
	map->mlx = mlx_init();
	if (!map->mlx)
		exit_msg("Error initializing mlx", map);
	map->win = mlx_new_window(map->mlx, map->width * 32, map->height * 32, "so_long");
	if (!map->win)
		exit_msg("Error creating window", map);
	load_textures(map);
	draw_map(map);
	mlx_key_hook(map->win, handle_keypress, map);
	mlx_hook(map->win, 17, 0, handle_close, map);
	map->game_over = 0;
	mlx_loop(map->mlx);
	return (0);
}

void	dfs(char **map, int x, int y, int *c_found, int *e_found)
{
	if (y < 0 || x < 0 || !map[y] || !map[y][x])
		return ;
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

	map_copy = copy_map(map, map->height);
	c_found = 0;
	e_found = 0;
	dfs(map_copy, map->player_x, map->player_y, &c_found, &e_found);
	if (c_found != map->collectibles || !e_found)
	{
		int i = 0;
		while (map_copy[i])
			free(map_copy[i++]);
		free(map_copy);
		exit_msg("Error: No valid path to all collectibles and exit", map);
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
	printf("Map height: %d\n", map->height);
	map->width = ft_strlen(map->map[0]);
	printf("First row width: %d\n", map->width);
	i = 0;
	while (i < map->height)
	{
		if ((int)ft_strlen(map->map[i]) != map->width)
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
	printf("Map width: %d\n", map->width);
	printf("Player count: %d, Exit count: %d, Collectibles: %d\n",
		player_count, exit_count, map->collectibles);
	if (player_count != 1 || exit_count != 1 || map->collectibles < 1)
		return (0);
	validate_borders(map);
	printf("DFS start at (%d, %d): char='%c'\n", map->player_y, map->player_x,
	map->map[map->player_y][map->player_x]);
	for (int k = 0; map->map[k]; k++)
		printf("[%d] %s\n", k, map->map[k]);
	
	validate_path(map);
	return (1);
}

void check_characters(t_map *map)
{
	int i;
	int j;

	i = 0;
	while (map->map[i] != NULL)
	{
		j = 0;
		while (map->map[i][j] != '\0')
		{
			if (!ft_strchr(MAP_CHARS, map->map[i][j]) && map->map[i][j] != '\n')
				exit_msg("Error: Invalid character in map", map);
			j++;
		}
		i++;
	}
}

void	get_map_lines(char *file_name, t_map *map)
{
	int		fd;
	int		line_count;
	int		i;
	char	*line;

	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		exit_msg("Error opening map file", NULL);
	line_count = 0;
	while ((line = get_next_line(fd)))
	{
		free(line);
		line_count++;
	}
	close(fd);
	map->map = malloc(sizeof(char *) * (line_count + 1));
	if (!map->map)
		exit_msg("Error: Memory allocation failed", map);
	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		exit_msg("Error reopening map file", map);
	i = 0;
	while ((line = get_next_line(fd)))
	{
		size_t len = ft_strlen(line);
		if (len > 0 && line[len - 1] == '\n')
			line[len - 1] = '\0';
		map->map[i++] = line;
	}
	map->map[i] = NULL;
	close(fd);
}

int	check_map(char **argv, t_map *map)
{
	printf("Checking map: %s\n", argv[1]);
	get_map_lines(argv[1], map);
	if (!map->map)
		exit_msg("Error: Failed to read map file", map);
	// Delete this later
	printf("Map read successfully, checking characters...\n");
	int i = 0;
	while (map->map[i])
	{
		printf("[%d] %s\n", i, map->map[i]);
		i++;
	}
	// End of delete
	check_characters(map);
	printf("Characters checked, validating map...\n");
	if (map->map[0] == NULL)
		exit_msg("Error: Map is empty", map);
	if (!validate_map(map))
		exit_msg("Error: Invalid map", map);
	return (1);
}

int	main(int argc, char **argv)
{
	t_map map;

	if (argc != 2)
		exit_msg("Error: Usage: ./so_long <map_file>", NULL);
	if (ft_strncmp(argv[1] + ft_strlen(argv[1]) - 4, ".ber", 4) != 0)
		exit_msg("Error: Map file must have a .ber extension", NULL);
	check_map(argv, &map);
	load_game(&map);
	return (0);
}
