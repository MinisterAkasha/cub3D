/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akasha <akasha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 21:09:14 by akasha            #+#    #+#             */
/*   Updated: 2020/12/13 18:08:01 by akasha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	cast_ray(t_config *config, t_hero ray)
{
	while (config->map.map[(int)(ray.y / config->map.scale)][(int)(ray.x / config->map.scale)] != '1' &&
		config->map.map[(int)(ray.y / config->map.scale)][(int)(ray.x / config->map.scale)] != '2')
	{
		ray.x += cos(ray.start);
		ray.y += sin(ray.start);
		my_mlx_pixel_put(&config->data, ray.x, ray.y, 0x123EED);
	}
}

void	cast_rays(t_config *config)
{
	t_ray	*ray;
	int		mapX;
	int		mapY;
	int		hit;
	int		side;
	int		lineHeight;

	hit = 0;
	ray = &config->ray;
	ray->deltaX = fabs(1 / ray->rayX);
	ray->deltaY = fabs(1 / ray->rayY);
	mapX = (int)config->ray.rayX;
	mapY = (int)config->ray.rayY;
	if (ray->rayX < 0)
	{
		ray->stepX = -1;
		ray->sideX = (ray->rayX - mapX) * ray->deltaX;
	}
	else
	{
		ray->stepX = 1;
		ray->sideX = (mapX + 1 - ray->rayX) * ray->deltaX;
	}
	if (ray->rayY < 0)
	{
		ray->stepY = -1;
		ray->sideY = (ray->rayY - mapY) * ray->deltaY;
	}
	else
	{
		ray->stepY = 1;
		ray->sideY =(mapY + 1 - ray->rayY) * ray->deltaY;
	}
	while (!hit)
	{
		if (ray->sideX < ray->sideY)
        {
          ray->sideX += ray->deltaX;
          mapX += ray->stepX;
          side = 0;
        }
        else
        {
          ray->sideY += ray->deltaY;
          mapY += ray->stepY;
          side = 1;
        }
		my_mlx_pixel_put(&config->data, 10, 10, 0xFFFF11);
        if (config->map.map[mapY][mapX]> 0) hit = 1;
	}
	if (side == 0)
		ray->perpWallDist = (mapX - config->hero.x + (1 - ray->stepX) / 2) / ray->rayX;
    else
		ray->perpWallDist = (mapY - config->hero.x + (1 - ray->stepY) / 2) / ray->rayY;
	
	lineHeight = (int)(HEIGHT / ray->perpWallDist);

	ray->start = -lineHeight / 2 + HEIGHT / 2;
	if (ray->start < 0) 
		ray->start = 0;
		
	ray->end = lineHeight / 2 + HEIGHT / 2;
	if (ray->end >= HEIGHT)
		ray->end = HEIGHT - 1;
	
	// if (config->map.map[mapY][mapX] == 1)
		// my_mlx_pixel_put(&config->data, )
	// while (ray.start <= ray.end)
	// {
	// 	ray.y = (config->hero.y + 0.5) * config->map.scale;
	// 	ray.x = (config->hero.x + 0.5) * config->map.scale;
	// 	// cast_ray(config, ray);
	// 	ray.start += (M_PI / 2) / 1920;
	// }
}
// void	cast_rays(t_config *config)
// {
// 	t_hero	ray;

// 	ray = config->hero;
// 	ray.y = (config->hero.y + 0.5) * config->map.scale;
// 	ray.x = (config->hero.x + 0.5) * config->map.scale;
// 	ray.start = config->hero.dir - (M_PI / 4);
// 	ray.end = config->hero.dir + (M_PI / 4);
// 	while (ray.start <= ray.end)
// 	{
// 		ray.y = (config->hero.y + 0.5) * config->map.scale;
// 		ray.x = (config->hero.x + 0.5) * config->map.scale;
// 		cast_ray(config, ray);
// 		ray.start += (M_PI / 2) / 1920;
// 	}
// }