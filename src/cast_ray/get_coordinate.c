/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_coordinate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akasha <akasha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 17:15:32 by akasha            #+#    #+#             */
/*   Updated: 2021/01/16 19:15:37 by akasha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	ft_get_camera_coordinate(t_config *config, int x)
{
	config->hero.camera_x = 2 * (x / (double)config->params.window_width) - 1;
	config->ray.ray_dir_y = config->hero.dir_y
						+ config->hero.plane_y * config->hero.camera_x;
	config->ray.ray_dir_x = config->hero.dir_x
						+ config->hero.plane_x * config->hero.camera_x;
}

void	get_map_coordinates(t_config *config)
{
	config->ray_casting.map_x = (int)config->hero.x;
	config->ray_casting.map_y = (int)config->hero.y;
}

void	get_hit_coordinate(t_config *config)
{
	if (!config->ray_casting.side)
		config->ray_casting.wall_x = config->hero.y +
									config->ray.perp_wall_dist *
									config->ray.ray_dir_y;
	else
		config->ray_casting.wall_x = config->hero.x +
									config->ray.perp_wall_dist *
									config->ray.ray_dir_x;
	config->ray_casting.wall_x -= floor(config->ray_casting.wall_x);
}

void	get_x_tex_coordinate(t_config *config, int tex_num)
{
	config->ray_casting.tex_x = (int)(config->ray_casting.wall_x *
										config->img.width[tex_num]);
	if (config->ray_casting.side == 0 && config->ray.ray_dir_x > 0)
		config->ray_casting.tex_x = config->img.width[tex_num] -
									config->ray_casting.tex_x - 1;
	if (config->ray_casting.side == 1 && config->ray.ray_dir_y < 0)
		config->ray_casting.tex_x = config->img.width[tex_num] -
									config->ray_casting.tex_x - 1;
}

void	get_y_tex_coordinate(t_config *config, int tex_num)
{
	config->ray_casting.tex_y = (int)config->ray_casting.tex_pos &
								(config->img.height[tex_num] - 1);
}
