/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akasha <akasha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 21:09:14 by akasha            #+#    #+#             */
/*   Updated: 2021/01/07 14:18:02 by akasha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	cast_rays(t_config *config, int x)
{
	t_ray	*ray;
	int		map_x;
	int		map_y;
	int		hit;
	int		side;
	int		line_height;

	size_t				tex_color;
	int					y;
	int 				tex_x;
	int 				tex_y;
	int 				tex_num;
	double				wall_x;
	double				step;
	double				tex_pos;


	
	ray = &config->ray;
	hit = 0;
	ray->deltaX = fabs(1 / ray->ray_dir_x);
	ray->deltaY = fabs(1 / ray->ray_dir_y);
	map_x = (int)config->hero.x;
	map_y = (int)config->hero.y;

	if (ray->ray_dir_x < 0)
	{
		ray->stepX = -1;
		ray->sideX = (config->hero.x - map_x) * ray->deltaX;
	}
	else
	{
		ray->stepX = 1;
		ray->sideX = (map_x + 1 - config->hero.x) * ray->deltaX;
	}
	if (ray->ray_dir_y < 0)
	{
		ray->stepY = -1;
		ray->sideY = (config->hero.y - map_y) * ray->deltaY;
	}
	else
	{
		ray->stepY = 1;
		ray->sideY = (map_y + 1 - config->hero.y) * ray->deltaY;
	}

	while (hit == 0)
	{
		if (ray->sideX < ray->sideY)
		{
			ray->sideX += ray->deltaX;
			map_x += ray->stepX;
			side = 0;
		}
		else
		{
			ray->sideY += ray->deltaY;
			map_y += ray->stepY;
			side = 1;
		}
		if (config->map.map[map_y][map_x] == '1')
			hit = 1;
	}

	tex_num = get_texture_number(config, map_y, map_x, side);

	if (side == 0)
		ray->perp_wall_dist = (map_x - config->hero.x + (1 - ray->stepX) / 2) / ray->ray_dir_x;
	else
		ray->perp_wall_dist = (map_y - config->hero.y + (1 - ray->stepY) / 2) / ray->ray_dir_y;


	if (!side)
		wall_x = config->hero.y + ray->perp_wall_dist * ray->ray_dir_y;
	else
		wall_x = config->hero.x + ray->perp_wall_dist * ray->ray_dir_x;
	wall_x -= floor(wall_x);
	tex_x = (int)(wall_x * config->img.width[tex_num]);
	if(side == 0 && ray->ray_dir_x > 0)
		tex_x = config->img.width[tex_num] - tex_x - 1;
	if(side == 1 && ray->ray_dir_y < 0)
		tex_x = config->img.width[tex_num] - tex_x - 1;

	line_height = (int)(config->settings.window_height / ray->perp_wall_dist);

	ray->start = -line_height / 2 + config->settings.window_height / 2;
	if (ray->start < 0) 
		ray->start = 0;

	ray->end = line_height / 2 + config->settings.window_height / 2;
	if (ray->end >= config->settings.window_height)
		ray->end = config->settings.window_height - 1; 

	step = 1.0 * config->img.height[tex_num] / line_height;

	tex_pos = (ray->start - (config->settings.window_height / 2) + (line_height / 2)) * step;

	y = 0;
	while (y < config->settings.window_height)
	{
		if (y > ray->end)
			fast_pixel_put(&config->data, x, y, config->settings.floor_color);
		else if (y < ray->start)
			fast_pixel_put(&config->data, x, y, config->settings.celling_color);
		else if (y >= ray->start && y <= ray->end)
		{
			tex_y = (int)tex_pos & (config->img.height[tex_num] - 1);
			tex_pos += step;
			if (tex_num != 4)
			{
				tex_color = config->img.texture[tex_num][config->img.height[tex_num] * tex_y + tex_x];
				fast_pixel_put(&config->data, x, y, tex_color);
			}
		}
		y++;
	}
}


int		get_texture_number(t_config *config, int y,int x, int side)
{
	if (config->map.map[y][x] == '1')
	{
		if (y < config->hero.y && side)
			return (0);
		if (y > config->hero.y && side)
			return (1);
		if (x > config->hero.x && !side)
			return (2);
		if (x < config->hero.x && !side)
			return (3);
	}
	if (config->map.map[y][x] == '2')
		return (4);
	return (0);
}
