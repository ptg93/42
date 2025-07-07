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
# define MAP_CHARS "01CEP" // Characters allowed in the map: 0 (empty), 1 (wall), C (collectible), E (exit), P (player)


typedef struct s_sprite {
	void	*img;
	int		width;
	int		height;
}	t_sprite;

typedef struct s_textures {
	t_sprite	wall;
	t_sprite	floor;
	t_sprite	collectible;
	t_sprite	exit;
	t_sprite	player [2];
}	t_textures;

typedef struct s_map
{
    char	**map;          // 2D array representing the map
    int		width;         // Width of the map
    int		height;        // Height of the map
    int		player_x;     // Player's x-coordinate
    int		player_y;     // Player's y-coordinate
    int		exit_x;       // Exit's x-coordinate
    int		exit_y;       // Exit's y-coordinate
    int		collectibles;  // Number of collectibles in the map
    int		moves;         // Number of moves made by the player
    int     c_found;
    int     e_found;
    void    *mlx;          // Pointer to the mlx instance
    void    *win;          // Pointer to the mlx window
    int     game_over;
    t_textures textures;   // Textures for the game
}	t_map;

int     move_player(t_map *map, int dx, int dy);
int		handle_keypress(int keycode, t_map *map);
void	draw_map(t_map *map);
int		handle_close(void *param);
int		load_game(t_map *map);
void	load_textures(t_map *map);
int		check_map(char **argv, t_map *map);
void	exit_msg(const char *msg, t_map *map);
void	free_map(char **map);
void	check_characters(t_map *map);
int		validate_map(t_map *map);
void	get_map_lines(char *file_name, t_map *map);
void	validate_borders(t_map *map);
void	validate_path(t_map *map);
void	dfs(char **map, int x, int y, int *c_found, int *e_found);
char	**copy_map(t_map *src, int height);
void	free_all_textures(t_map *map);


#endif
