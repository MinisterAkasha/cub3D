/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_step.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akasha <akasha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 17:20:28 by akasha            #+#    #+#             */
/*   Updated: 2021/01/15 17:25:54 by akasha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	get_side_and_step_x(t_config *config)
{
	if (config->ray.ray_dir_x < 0)
	{
		config->ray.step_x = -1;
		config->ray.side_x = (config->hero.x - config->ray_casting.map_x) *
							config->ray.delta_x;
	}
	else
	{
		config->ray.step_x = 1;
		config->ray.side_x = (config->ray_casting.map_x + 1 - config->hero.x) *
								config->ray.delta_x;
	}
}

void	get_side_and_step_y(t_config *config)
{
	if (config->ray.ray_dir_y < 0)
	{
		config->ray.step_y = -1;
		config->ray.side_y = (config->hero.y - config->ray_casting.map_y) *
								config->ray.delta_y;
	}
	else
	{
		config->ray.step_y = 1;
		config->ray.side_y = (config->ray_casting.map_y + 1 - config->hero.y) *
								config->ray.delta_y;
	}
}

void	get_step_value(t_config *config, int tex_num)
{
	config->ray_casting.step = 1.0 * config->img.height[tex_num] /
								config->ray_casting.line_height;
}
