//#include "so_long.h"
#include "minilibx-linux/mlx.h"
#include <stdlib.h>

/*int	main (int argc, char **argv)
{
	if (!check_map(argc, argv))
	{
		perror("map");
		return (1);
	}

}
*/ 
int	handle_close(void *param)
{
	(void)param;
	exit(0);
}

int main(void)
{
	void	*mlx;
	void	*win;
	void	*img;
	int		img_width;
	int		img_height;

	mlx = mlx_init();
	if (!mlx)
		return(1);
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
}
