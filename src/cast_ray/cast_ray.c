/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akasha <akasha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 21:09:14 by akasha            #+#    #+#             */
/*   Updated: 2021/01/16 19:15:43 by akasha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	get_wall_hit(t_config *config)
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
		if (config->map.map[config->ray_casting.map_y]
			[config->ray_casting.map_x] == '1')
			hit = 1;
	}
}

int		get_texture_number(t_config *config, int y, int x)
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

void	draw_vertical_line(t_config *config, int tex_num, int x)
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
				config->ray_casting.tex_color = config->img.texture[tex_num]
												[config->img.height[tex_num] *
												config->ray_casting.tex_y +
												config->ray_casting.tex_x];
				fast_pixel_put(&config->data, x, y,
								config->ray_casting.tex_color);
			}
		}
		y++;
	}
}

void	cast_rays(t_config *config, int x)
{
	int	tex_num;

	ft_get_camera_coordinate(config, x);
	get_ray_delta(config);
	get_map_coordinates(config);
	get_side_and_step_x(config);
	get_side_and_step_y(config);
	get_wall_hit(config);
	get_distance(config);
	tex_num = get_texture_number(config,
				config->ray_casting.map_y, config->ray_casting.map_x);
	get_hit_coordinate(config);
	get_x_tex_coordinate(config, tex_num);
	get_line_height(config);
	get_draw_wall_range(config);
	get_step_value(config, tex_num);
	get_tex_pos(config);
	draw_vertical_line(config, tex_num, x);
}
