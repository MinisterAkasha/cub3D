/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akasha <akasha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 21:09:14 by akasha            #+#    #+#             */
/*   Updated: 2021/01/07 18:39:49 by akasha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	get_map_coordinates(t_config *config)
{
	config->ray_casting.map_x = (int)config->hero.x;
	config->ray_casting.map_y = (int)config->hero.y;
}

void	get_side_and_step_x(t_config *config)
{
	if (config->ray.ray_dir_x < 0)
	{
		config->ray.step_x = -1;
		config->ray.side_x = (config->hero.x - config->ray_casting.map_x) * config->ray.delta_x;
	}
	else
	{
		config->ray.step_x = 1;
		config->ray.side_x = (config->ray_casting.map_x + 1 - config->hero.x) * config->ray.delta_x;
	}
}

void	get_side_and_step_y(t_config *config)
{
	if (config->ray.ray_dir_y < 0)
	{
		config->ray.step_y = -1;
		config->ray.side_y = (config->hero.y - config->ray_casting.map_y) * config->ray.delta_y;
	}
	else
	{
		config->ray.step_y = 1;
		config->ray.side_y = (config->ray_casting.map_y + 1 - config->hero.y) * config->ray.delta_y;
	}
}

void	get_hit(t_config *config)
{
	int hit;

	hit = 0;
	while (hit == 0)
	{
		if (config->ray.side_x < config->ray.side_y)
		{
			config->ray.side_x += config->ray.delta_x;
			config->ray_casting.map_x += config->ray.step_x;
			config->ray_casting.side = 0;
		}
		else
		{
			config->ray.side_y += config->ray.delta_y;
			config->ray_casting.map_y += config->ray.step_y;
			config->ray_casting.side = 1;
		}
		if (config->map.map[config->ray_casting.map_y][config->ray_casting.map_x] == '1')
			hit = 1;
	}
}

void	get_ray_delta(t_config *config)
{
	config->ray.delta_x = fabs(1 / config->ray.ray_dir_x);
	config->ray.delta_y = fabs(1 / config->ray.ray_dir_y);
}

void	get_distance(t_config *config)
{
	if (config->ray_casting.side == 0)
		config->ray.perp_wall_dist = (config->ray_casting.map_x - config->hero.x + (1 - config->ray.step_x) / 2) / config->ray.ray_dir_x;
	else
		config->ray.perp_wall_dist = (config->ray_casting.map_y - config->hero.y + (1 - config->ray.step_y) / 2) / config->ray.ray_dir_y;
}

int		get_texture_number(t_config *config, int y,int x)
{
	if (config->map.map[y][x] == '1')
	{
		if (y < config->hero.y && config->ray_casting.side)
			return (0);
		if (y > config->hero.y && config->ray_casting.side)
			return (1);
		if (x > config->hero.x && !config->ray_casting.side)
			return (2);
		if (x < config->hero.x && !config->ray_casting.side)
			return (3);
	}
	if (config->map.map[y][x] == '2')
		return (4);
	return (0);
}

void	get_hit_coordinate(t_config *config)
{
	if (!config->ray_casting.side)
		config->ray_casting.wall_x = config->hero.y + config->ray.perp_wall_dist * config->ray.ray_dir_y;
	else
		config->ray_casting.wall_x = config->hero.x + config->ray.perp_wall_dist * config->ray.ray_dir_x;
	config->ray_casting.wall_x -= floor(config->ray_casting.wall_x);
}

void	get_x_tex_coordinate(t_config *config, int tex_num)
{
	config->ray_casting.tex_x = (int)(config->ray_casting.wall_x * config->img.width[tex_num]);
	if (config->ray_casting.side == 0 && config->ray.ray_dir_x > 0)
		config->ray_casting.tex_x = config->img.width[tex_num] - config->ray_casting.tex_x - 1;
	if (config->ray_casting.side == 1 && config->ray.ray_dir_y < 0)
		config->ray_casting.tex_x = config->img.width[tex_num] - config->ray_casting.tex_x - 1;
}

void	get_y_tex_coordinate(t_config *config, int tex_num)
{
	config->ray_casting.tex_y = (int)config->ray_casting.tex_pos & (config->img.height[tex_num] - 1);
}

void	get_line_height(t_config *config)
{
	config->ray_casting.line_height = (int)(config->params.window_height / config->ray.perp_wall_dist);
}

void	get_wall_range(t_config * config)
{
	config->ray.start = -config->ray_casting.line_height / 2 + config->params.window_height / 2;
	if (config->ray.start < 0)
		config->ray.start = 0;
	config->ray.end = config->ray_casting.line_height / 2 + config->params.window_height / 2;
	if (config->ray.end >= config->params.window_height)
		config->ray.end = config->params.window_height - 1;
}

void	get_step_value(t_config *config, int tex_num)
{
	config->ray_casting.step = 1.0 * config->img.height[tex_num] / config->ray_casting.line_height;
}

void	get_tex_pos(t_config *config)
{
	config->ray_casting.tex_pos = (config->ray.start - 
								(config->params.window_height / 2) + 
								(config->ray_casting.line_height / 2)) * 
								config->ray_casting.step;
}

void	drow_vertical_line(t_config *config, int tex_num, int x)
{
	int y;

	y = 0;
	while (y < config->params.window_height)
	{
		if (y > config->ray.end)
			fast_pixel_put(&config->data, x, y, config->params.floor_color);
		else if (y < config->ray.start)
			fast_pixel_put(&config->data, x, y, config->params.ceiling_color);
		else if (y >= config->ray.start && y <= config->ray.end)
		{
			get_y_tex_coordinate(config, tex_num);
			config->ray_casting.tex_pos += config->ray_casting.step;
			if (tex_num != 4)
			{
				config->ray_casting.tex_color = config->img.texture[tex_num][config->img.height[tex_num] * config->ray_casting.tex_y + config->ray_casting.tex_x];
				fast_pixel_put(&config->data, x, y, config->ray_casting.tex_color);
			}
		}
		y++;
	}
}

void	cast_rays(t_config *config, int x)
{
	int 	tex_num;

	get_ray_delta(config);
	get_map_coordinates(config);
	get_side_and_step_x(config);
	get_side_and_step_y(config);
	get_hit(config);
	get_distance(config);
	tex_num = get_texture_number(config,
				config->ray_casting.map_y, config->ray_casting.map_x);
	get_hit_coordinate(config);
	get_x_tex_coordinate(config, tex_num);
	get_line_height(config);
	get_wall_range(config);
	get_step_value(config, tex_num);
	get_tex_pos(config);
	drow_vertical_line(config, tex_num, x);
}