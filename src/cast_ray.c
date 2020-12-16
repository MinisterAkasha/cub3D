/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akasha <akasha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 21:09:14 by akasha            #+#    #+#             */
/*   Updated: 2020/12/16 19:51:49 by akasha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	cast_rays(t_config *config, int x, int (buffer)[HEIGHT][WIDTH], int texture[2][TEX_HEIGHT * TEX_WIDTH])
{
	t_ray	*ray;
	int		map_x;
	int		map_y;
	int		hit;
	int		side;
	int		line_height;
	int		color = 0xFFFFFF;

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

	tex_num = config->map.map[map_y][map_x] == '1' ? 0 : 1;

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

	// printf("%f\n", ray->start);
	// if (config->map.map[map_y][map_x] == '1')
	// 	color = 0x0000FF;
	// else if (config->map.map[map_y][map_x] == '2')
	// 	color = 0xFFFF22;
	// if (side == 1)
	// 	color /= 2;
	
	step = TEX_HEIGHT / line_height;

	tex_pos = (ray->start - (HEIGHT / 2) + (line_height / 2)) * step;

	// printf("%f\n", tex_pos);

	// y = ray->start;
	y = 0;
	while (y < HEIGHT)
	{
		if (y > ray->end)
			buffer[y][x] = 0x00FF00;
		else if (y < ray->start)
			buffer[y][x] = 0x99CCFF;
		else if (y >= ray->start && y <= ray->end)
		{
			tex_y = (int)tex_pos & (TEX_HEIGHT - 1);
			tex_pos += step;
			tex_color = texture[0][TEX_HEIGHT * tex_y + tex_x];
			if (side)
				tex_color = (tex_color >> 1) & 8355711;
			buffer[y][x] = tex_color;
			printf("Y: %-5d X: %-5d color: %-12zu buffer: %-5d \n", tex_y, tex_x, tex_color, buffer[y][x]);

		}
		my_mlx_pixel_put(&config->data, x, y, buffer[y][x]);
		y++;
	}
}

void	drow_vertical_line(int x, double start, double end, int color, t_config *config, uint32_t (buffer)[HEIGHT][WIDTH])
{
	int i;
	int	x_copy;

	i = 0;
	x_copy = x;
	while (HEIGHT > i)
	{
		if (i >= start && i <= end)
		{
			my_mlx_pixel_put(&config->data, x, i, buffer[i][x]);
			// my_mlx_pixel_put(&config->data, x, i, color);
		}
		else if (i > end)
			my_mlx_pixel_put(&config->data, x, i, 0x00FF00);
		else if (i < start)
			my_mlx_pixel_put(&config->data, x, i, 0x99CCFF);
		i++;
	}
}
