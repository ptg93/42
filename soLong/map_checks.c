/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptraba-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 11:36:12 by ptraba-d          #+#    #+#             */
/*   Updated: 2025/07/09 11:36:15 by ptraba-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	check_characters(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (map->map[i] != NULL)
	{
		j = 0;
		while (map->map[i][j] != '\0')
		{
			if (!ft_strchr(MAP_CHARS, map->map[i][j]) && map->map[i][j] != '\n')
				exit_msg("Error: Invalid character in map", map);
			if (map->map[i][j] == 'M')
				map->enemy_count++;
			j++;
		}
		i++;
	}
}

static int	count_lines(char *file_name)
{
	int		fd;
	int		line_count;
	char	*line;

	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		exit_msg("Error opening map file", NULL);
	line_count = 0;
	line = get_next_line(fd);
	while (line)
	{
		free(line);
		line_count++;
		line = get_next_line(fd);
	}
	close(fd);
	return (line_count);
}

static void	process_line(char *line, t_map *map, int i)
{
	size_t	len;

	len = ft_strlen(line);
	if (len > 0 && line[len - 1] == '\n')
		line[len - 1] = '\0';
	map->map[i] = line;
}

static void	get_map_lines(char *file_name, t_map *map)
{
	int		fd;
	int		i;
	char	*line;
	int		line_count;

	line_count = count_lines(file_name);
	map->map = malloc(sizeof(char *) * (line_count + 1));
	if (!map->map)
		exit_msg("Error: Memory allocation failed", map);
	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		exit_msg("Error reopening map file", map);
	i = 0;
	line = get_next_line(fd);
	while (line && i < line_count)
	{
		process_line(line, map, i);
		i++;
		line = get_next_line(fd);
	}
	map->map[i] = NULL;
	close(fd);
}

int	check_map(char **argv, t_map *map)
{
	ft_printf("Checking map: %s\n", argv[1]);
	get_map_lines(argv[1], map);
	if (!map->map)
		exit_msg("Error: Failed to read map file", map);
	map->enemy_count = 0;
	check_characters(map);
	ft_printf("Characters checked, validating map...\n");
	if (map->map[0] == NULL)
		exit_msg("Error: Map is empty", map);
	if (map->enemy_count > 0)
	{
		map->enemies = malloc(sizeof(t_enemy) * map->enemy_count);
		if (!map->enemies)
			exit_msg("Error: Memory allocation for enemies failed", map);
		ft_printf("Enemies found and allocated: %d\n", map->enemy_count);
	}
	if (!validate_map(map))
		exit_msg("Error: Invalid map", map);
	return (1);
}
