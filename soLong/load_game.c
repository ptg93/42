/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptraba-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 11:36:59 by ptraba-d          #+#    #+#             */
/*   Updated: 2025/07/09 11:37:00 by ptraba-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	load_basic_textures(t_map *map)
{
	map->textures.wall.img = mlx_xpm_file_to_image(map->mlx,
			"textures/wall.xpm", &map->textures.wall.width,
			&map->textures.wall.height);
	if (!map->textures.wall.img)
		exit_msg("Error loading wall texture", map);
	map->textures.floor.img = mlx_xpm_file_to_image(map->mlx,
			"textures/floor.xpm", &map->textures.floor.width,
			&map->textures.floor.height);
	if (!map->textures.floor.img)
		exit_msg("Error loading floor texture", map);
	map->textures.collectible.img = mlx_xpm_file_to_image(map->mlx,
			"textures/collectible.xpm",
			&map->textures.collectible.width,
			&map->textures.collectible.height);
	if (!map->textures.collectible.img)
		exit_msg("Error loading collectible texture", map);
	map->textures.exit.img = mlx_xpm_file_to_image(map->mlx,
			"textures/exit.xpm", &map->textures.exit.width,
			&map->textures.exit.height);
	if (!map->textures.exit.img)
		exit_msg("Error loading exit texture", map);
}

static void	load_player_textures(t_map *map)
{
	map->textures.player[0].img = mlx_xpm_file_to_image(map->mlx,
			"textures/player.xpm", &map->textures.player[0].width,
			&map->textures.player[0].height);
	if (!map->textures.player[0].img)
		exit_msg("Error loading player texture", map);
	map->textures.player[1].img = mlx_xpm_file_to_image(map->mlx,
			"textures/player.xpm", &map->textures.player[1].width,
			&map->textures.player[1].height);
	if (!map->textures.player[1].img)
		exit_msg("Error loading player texture", map);
}

static void	load_enemy_textures(t_map *map)
{
	map->textures.enemy[0].img = mlx_xpm_file_to_image(map->mlx,
			"textures/enemy_01.xpm", &map->textures.enemy[0].width,
			&map->textures.enemy[0].height);
	if (!map->textures.enemy[0].img)
		exit_msg("Error loading enemy texture", map);
	map->textures.enemy[1].img = mlx_xpm_file_to_image(map->mlx,
			"textures/enemy_02.xpm", &map->textures.enemy[1].width,
			&map->textures.enemy[1].height);
	if (!map->textures.enemy[1].img)
		exit_msg("Error loading enemy texture", map);
}

static void	load_textures(t_map *map)
{
	load_basic_textures(map);
	load_player_textures(map);
	load_enemy_textures(map);
}

int	load_game(t_map *map)
{
	map->mlx = mlx_init();
	if (!map->mlx)
		exit_msg("Error initializing mlx", map);
	map->win = mlx_new_window(map->mlx, map->width * 32,
			map->height * 32, "so_long");
	if (!map->win)
		exit_msg("Error creating window", map);
	map->game_over = 0;
	map->moves = 0;
	load_textures(map);
	draw_map(map);
	mlx_key_hook(map->win, handle_keypress, map);
	mlx_hook(map->win, 17, 0, handle_close, map);
	mlx_loop(map->mlx);
	return (0);
}
