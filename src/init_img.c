#include "cub.h"

void	init_image(t_config *config)
{
	config->data.img = mlx_new_image(config->win.mlx,
						config->params.window_width,
						config->params.window_height);
	config->data.addr = mlx_get_data_addr(config->data.img,
						&config->data.bits_per_pixel,
						&config->data.line_length, &config->data.endian);
}
