/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akasha <akasha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 21:09:14 by akasha            #+#    #+#             */
/*   Updated: 2020/12/20 16:57:02 by akasha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	cast_rays(t_config *config, int x, int texture[2][TEX_HEIGHT * TEX_WIDTH])
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
		if (config->map.map[map_y][map_x] == '1' || config->map.map[map_y][map_x] == '2')
			hit = 1;
	}

	if (side == 0)
		ray->perpWallDist = (map_x - config->hero.x + (1 - ray->stepX) / 2) / ray->ray_dir_x;
	else
		ray->perpWallDist = (map_y - config->hero.y + (1 - ray->stepY) / 2) / ray->ray_dir_y;

	tex_num = get_texture_number(config, map_y, map_x);

	if (!side)
		wall_x = config->hero.y + ray->perpWallDist * ray->ray_dir_y;
	else
		wall_x = config->hero.x + ray->perpWallDist * ray->ray_dir_x;
	wall_x -= floor(wall_x);
	tex_x = (int)(wall_x * TEX_WIDTH);
    if(side == 0 && ray->ray_dir_x > 0)
		tex_x = TEX_WIDTH - tex_x - 1;
    if(side == 1 && ray->ray_dir_y < 0)
		tex_x = TEX_WIDTH - tex_x - 1;

	
	line_height = (int)(HEIGHT / ray->perpWallDist);

	ray->start = -line_height / 2 + HEIGHT / 2;
	if (ray->start < 0) 
		ray->start = 0;

	ray->end = line_height / 2 + HEIGHT / 2;
	if (ray->end >= HEIGHT)
		ray->end = HEIGHT - 1; 

	step = 1.0 * TEX_HEIGHT / line_height;

	tex_pos = (ray->start - (HEIGHT / 2) + (line_height / 2)) * step;

	y = 0;
	while (y < HEIGHT)
	{
		if (y > ray->end)
			my_mlx_pixel_put(&config->data, x, y, 0x00FF00 / 5);
		else if (y < ray->start)
			my_mlx_pixel_put(&config->data, x, y, 0x99CCFF / 5);
		else if (y >= ray->start && y <= ray->end)
		{
			tex_y = (int)tex_pos & (TEX_HEIGHT - 1);
			tex_pos += step;
			tex_color = texture[tex_num][TEX_HEIGHT * tex_y + tex_x];
			if (side)
				tex_color = (tex_color >> 1) & 8355711;
			my_mlx_pixel_put(&config->data, x, y, tex_color);
			// printf("Y: %-5d X: %-5d color: %-8zu buffer: %-5d TEX_HEIGHT - 1: %-5d tex_pos: %-5d \n", tex_y, tex_x, tex_color, buffer[y][x], TEX_HEIGHT - 1, (int)tex_pos);
		}
		y++;
	}
}


int	get_texture_number(t_config *config, int y,int x)
{
	if (config->map.map[y][x] == '1')
		return (0);
	if (config->map.map[y][x] == '2')
		return (1);
	return (0);
}
