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

int	main(int argc, char **argv)
{
	t_map	map;

	if (argc != 2)
		exit_msg("Error: Usage: ./so_long <map_file>", NULL);
	if (ft_strncmp(argv[1] + ft_strlen(argv[1]) - 4, ".ber", 4) != 0)
		exit_msg("Error: Map file must have a .ber extension", NULL);
	map.mlx = NULL;
	map.win = NULL;
	map.map = NULL;
	check_map(argv, &map);
	load_game(&map);
	return (0);
}
