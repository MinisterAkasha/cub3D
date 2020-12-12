/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akasha <akasha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 15:30:40 by akasha            #+#    #+#             */
/*   Updated: 2020/12/12 15:33:11 by akasha           ###   ########.fr       */
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
	config->map.scale = 50;
}

void	run_window(t_config *config)
{
	config->win.mlx = mlx_init();
	config->win.window = mlx_new_window(config->win.mlx, 1920, 1080, "Cub3D");
	if (!parcer(config))
		return ;//TODO add error and exit programm
	write_2d_map(config);
	mlx_hook(config->win.window, 02, 1L<<0,  move_hero, config);
	// mlx_hook(config->win.window, 02, 1L<<0,  rotate_hero, config);
	// mlx_key_hook(config->win.window, rotate_hero, config);
	// mlx_loop_hook (config->win.mlx, write_2d_map, config);
	mlx_loop(config->win.mlx);
}