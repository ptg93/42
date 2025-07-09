#include "so_long.h"

static void	draw_sprite(t_map *map, char tile, int x, int y)
{
	void	*img;
	int		sprite_index;

	img = NULL;
	sprite_index = map->moves % 2;
	if (tile == '1')
		img = map->textures.wall.img;
	else if (tile == 'C')
		img = map->textures.collectible.img;
	else if (tile == 'E')
		img = map->textures.exit.img;
	else if (tile == 'P')
		img = map->textures.player[sprite_index].img;
	else if (tile == 'M')
		img = map->textures.enemy[sprite_index].img;
	if (img)
		mlx_put_image_to_window(map->mlx, map->win, img, x * 32, y * 32);
}

void	draw_map(t_map *map)
{
	int	x;
	int	y;

	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			mlx_put_image_to_window(map->mlx, map->win,
				map->textures.floor.img, x * 32, y * 32);
			draw_sprite(map, map->map[y][x], x, y);
			x++;
		}
		y++;
	}
}
