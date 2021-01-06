/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akasha <akasha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 15:30:40 by akasha            #+#    #+#             */
/*   Updated: 2021/01/06 15:47:35 by akasha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	init_struct(t_config *config)
{
	config->map.has_hero = 0;
	config->map.height = 0;
	config->map.map = fill_map(config, ft_lstsize(config->head_map));
	config->map.hero_set = "NSEW";
	config->map.inner_set = "012 NSEW";
	config->map.space_set = "1 ";
	config->map.sprites_num = 0;
	config->hero.move_speed = 0.2;
	config->hero.rotate_speed = M_PI / 30;
}

void	init_error_arr(t_config *config)
{
	config->error.error_arr[0] = "Passed too many arguments";
	config->error.error_arr[1] = "Passed not enough arguments";
	config->error.error_arr[2] = "Too many heros on the map";
	config->error.error_arr[3] = "Missing hero on the map";
	config->error.error_arr[4] = "Not valid map";
	config->error.error_arr[5] = "Not valid parametr for window size";
	config->error.error_arr[6] = "Not valid parametr for texture";
	config->error.error_arr[7] = "Not valid parametr for floor/celling color";
	config->error.error_arr[8] = "Not not enough parametrs";
}

int		close_win(int keycode, t_config *config)
{
	if (keycode == 53)
	{
		mlx_destroy_image(config->win.mlx, config->data.img);
		mlx_destroy_window(config->win.mlx, config->win.window);
		// free(config->sprite);
		exit(0);
	}
	return (1);
}

void	run_window(t_config *config)
{
	config->win.mlx = mlx_init();
	if (!parce_param(config))
		return ;//TODO add error and exit programm
	if (!parce_map(config))
		return ;//TODO add error and exit programm
	init_map_objects(config);
	config->win.window = mlx_new_window(config->win.mlx, config->settings.window_width, config->settings.window_height, "Cub3D");
	render(config);
	mlx_hook(config->win.window, 02, 1L<<0,  move_hero, config);
	mlx_key_hook(config->win.window, close_win, config);
	mlx_loop(config->win.mlx);
}
