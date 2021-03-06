#include "cub.h"

void	run_window(t_config *config)
{
	config->win.mlx = mlx_init();
	parce_param(config);
	parce_map(config);
	init_map_objects(config);
	load_images(config);
	config->win.window = mlx_new_window(config->win.mlx,
						config->params.window_width,
						config->params.window_height,
						"Cub3D");
	render(config);
	mlx_hook(config->win.window, 02, 1L << 0, hooks, config);
	mlx_hook(config->win.window, 17, 1L << 17, close_win, config);
	mlx_loop(config->win.mlx);
}
