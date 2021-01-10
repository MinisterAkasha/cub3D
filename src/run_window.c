/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_window.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 15:50:44 by akasha            #+#    #+#             */
/*   Updated: 2021/01/10 12:49:54 by user             ###   ########.fr       */
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
	load_image(config);
	render(config);
	mlx_loop_hook(config->win.mlx, render, config);
	mlx_hook(config->win.window, 02, 1L<<0, hooks, config); //TODO mlx_loop
	mlx_hook(config->win.window, 17, 1L<<17, close_win, config);
	create_bmp_header(config);//!DEL
	mlx_loop(config->win.mlx);
	destroy_images(config);
}
