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

static void	validate_arguments(int argc, char **argv)
{
	size_t	len;

	if (argc != 2)
		exit_msg("Error: Usage: ./so_long <map_file>", NULL);
	if (!argv[1])
		exit_msg("Error: Invalid map file argument", NULL);
	len = ft_strlen(argv[1]);
	if (len < 5)
		exit_msg("Error: Map file name too short", NULL);
	if (ft_strncmp(argv[1] + len - 4, ".ber", 4) != 0)
		exit_msg("Error: Map file must have a .ber extension", NULL);
}

static void	initialize_map(t_map *map)
{
	map->mlx = NULL;
	map->win = NULL;
	map->map = NULL;
	map->enemies = NULL;
}

int	main(int argc, char **argv)
{
	t_map	map;

	validate_arguments(argc, argv);
	initialize_map(&map);
	check_map(argv, &map);
	load_game(&map);
	return (0);
}
