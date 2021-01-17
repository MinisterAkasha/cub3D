/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akasha <akasha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 17:14:04 by akasha            #+#    #+#             */
/*   Updated: 2021/01/17 18:23:37 by akasha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"//TODO проверить напровление игрока и стороны текстур

void	fill_depth(t_config *config, int x)
{
	config->sprite.depth[x] = config->ray.perp_wall_dist;
}

int		render(t_config *config)
{
	int	x;

	init_image(config);
	if (!(config->sprite.depth = (double *)malloc(sizeof(double)
								* config->params.window_width)))
		exit_cub(15, config);
	x = 0;
	while (x < config->params.window_width)
	{
		cast_rays(config, x);
		fill_depth(config, x);
		x++;
	}
	sprite_cast(config);
	free(config->sprite.depth);
	mlx_put_image_to_window(config->win.mlx, config->win.window,
										config->data.img, 0, 0);
	return (1);
}

void	make_screenshot(t_config *config)
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
	generate_bmp_image(config);
	destroy_images(config);
}

int		main(int argc, char *argv[])
{
	int			fd;
	t_config	*config;

	if (!(config = (t_config *)malloc(sizeof(t_config))))
		exit_cub(15, config);
	init_error(config);
	check_arguments(argc, argv, config);
	if ((fd = open(argv[1], O_RDONLY)) == -1)
		exit_cub(15, config);
	check_file_name(argv[1], config);
	fill_param_list(config, fd);
	fill_map_list(config, fd);
	close(fd);
	init_struct(config);
	if (config->params.screenshot)
		make_screenshot(config);
	else
		run_window(config);
	free_all(config);
	return (0);
}
