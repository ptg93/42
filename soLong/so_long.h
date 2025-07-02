#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <string.h>
# include <errno.h>
# include "minilibx-linux/mlx.h"
# define BUFFER_SIZE 1024
# define MAP_CHARS "01CEP" // Characters allowed in the map: 0 (empty), 1 (wall), C (collectible), E (exit), P (player)

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
}	t_map;

#endif