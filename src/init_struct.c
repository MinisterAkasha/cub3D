/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akasha <akasha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 15:30:40 by akasha            #+#    #+#             */
/*   Updated: 2020/12/19 17:35:26 by akasha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	init_struct(t_config *config, t_list *head)
{
	config->map.height = 0;
	config->map.map = fill_map(head, ft_lstsize(head), config);
	config->map.hero_set = "NSEW";
	config->map.inner_set = "012 NSEW";
	config->map.space_set = "1 ";
	config->map.scale = 30;


	config->hero.dir_x = -1;
	config->hero.dir_y = 0;
	config->hero.plane_x = 0;
	config->hero.plane_y = 0.66;
	config->hero.move_speed = 0.5;
	config->hero.rotate_speed = M_PI / 30;
}

int             close_win(int keycode, t_config *config)
{
	if (keycode == 53)
	{
		mlx_destroy_image(config->win.mlx, config->data.img);
		mlx_destroy_window(config->win.mlx, config->win.window);
		exit(0);
	}
	return (1);
}

void	run_window(t_config *config)
{
	config->win.mlx = mlx_init();
	config->win.window = mlx_new_window(config->win.mlx, WIDTH, HEIGHT, "Cub3D");
	if (!parcer(config))
		return ;//TODO add error and exit programm
	write_2d_map(config);
	mlx_hook(config->win.window, 02, 1L<<0,  move_hero, config);
	mlx_key_hook(config->win.window, close_win, config);
	// mlx_hook(config->win.window, 02, 1L<<0,  rotate_hero, config);
	// mlx_loop_hook (config->win.mlx, write_2d_map, config);
	mlx_loop(config->win.mlx);
}
