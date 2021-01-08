/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_window.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akasha <akasha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 15:50:44 by akasha            #+#    #+#             */
/*   Updated: 2021/01/08 19:52:39 by akasha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	run_window(t_config *config)
{
	config->win.mlx = mlx_init();
	parce_param(config);
	parce_map(config);
	init_map_objects(config);
	config->win.window = mlx_new_window(config->win.mlx,
						config->params.window_width,
						config->params.window_height,
						"Cub3D");
	render(config);
	// mlx_loop_hook(config->win.mlx, render, config);
	mlx_hook(config->win.window, 02, 1L<<0, move_hero_hook, config); //TODO mlx_loop
	mlx_key_hook(config->win.window, close_win, config);
	// mlx_loop(config->win.mlx);
}
