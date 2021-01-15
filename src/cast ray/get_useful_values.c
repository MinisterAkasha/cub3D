/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_useful_values.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akasha <akasha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 17:23:29 by akasha            #+#    #+#             */
/*   Updated: 2021/01/15 17:25:52 by akasha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	get_ray_delta(t_config *config)
{
	config->ray.delta_x = fabs(1 / config->ray.ray_dir_x);
	config->ray.delta_y = fabs(1 / config->ray.ray_dir_y);
}

void	get_distance(t_config *config)
{
	if (config->ray_casting.side == 0)
		config->ray.perp_wall_dist = (config->ray_casting.map_x -
										config->hero.x +
										(1 - config->ray.step_x) / 2) /
										config->ray.ray_dir_x;
	else
		config->ray.perp_wall_dist = (config->ray_casting.map_y -
										config->hero.y +
										(1 - config->ray.step_y) / 2) /
										config->ray.ray_dir_y;
}

void	get_line_height(t_config *config)
{
	config->ray_casting.line_height = (int)(config->params.window_height /
										config->ray.perp_wall_dist);
}

void	get_drow_wall_range(t_config *config)
{
	config->ray.start = -config->ray_casting.line_height / 2 +
						config->params.window_height / 2;
	if (config->ray.start < 0)
		config->ray.start = 0;
	config->ray.end = config->ray_casting.line_height / 2 +
						config->params.window_height / 2;
	if (config->ray.end >= config->params.window_height)
		config->ray.end = config->params.window_height - 1;
}

void	get_tex_pos(t_config *config)
{
	config->ray_casting.tex_pos = (config->ray.start -
								(config->params.window_height / 2) +
								(config->ray_casting.line_height / 2)) *
								config->ray_casting.step;
}
