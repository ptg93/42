/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptraba-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 16:52:33 by ptraba-d          #+#    #+#             */
/*   Updated: 2025/07/03 16:52:36 by ptraba-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <string.h>
# include <errno.h>
# include "minilibx-linux/mlx.h"
# include "libft/libft.h"
# ifndef MAP_CHARS
#  define MAP_CHARS "01CEP"
# endif

typedef struct s_enemy
{
	int	x;
	int	y;
	int	start_x;
	int	start_y;
}	t_enemy;

typedef struct s_sprite
{
	void	*img;
	int		width;
	int		height;
}	t_sprite;

typedef struct s_textures
{
	t_sprite	wall;
	t_sprite	floor;
	t_sprite	collectible;
	t_sprite	exit;
	t_sprite	player [2];
	t_sprite	enemy [2];
}	t_textures;

typedef struct s_map
{
	char		**map;
	int			width;
	int			height;
	int			player_x;
	int			player_y;
	int			exit_x;
	int			exit_y;
	int			collectibles;
	int			moves;
	int			c_found;
	int			e_found;
	void		*mlx;
	void		*win;
	int			enemy_count;
	int			enemy_index;
	int			game_over;
	int			player_count;
	int			exit_count;
	int			dx[4];
	int			dy[4];
	t_textures	textures;
	t_enemy		*enemies;
}	t_map;

void	exit_msg(const char *msg, t_map *map);
int		handle_close(void *param);
void	free_all_textures(t_map *map);
void	free_map(char **map);
int		load_game(t_map *map);
void	draw_map(t_map *map);
void	game_update(t_map *map);
void	check_game_over(int type, t_map *map);
int		move_player(t_map *map, int dx, int dy);
void	move_enemies(int danger, t_map *map);
int		pseudo_random(int seed);
void	display_score(t_map *map);
int		check_map(char **argv, t_map *map);
void	validate_path(t_map *map);
int		validate_map(t_map *map);
int		handle_keypress(int keycode, t_map *map);
int		enemy_can_move_to(t_map *map, int x, int y, t_enemy enemy);

#endif
