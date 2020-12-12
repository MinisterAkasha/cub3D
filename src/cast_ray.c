/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akasha <akasha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 21:09:14 by akasha            #+#    #+#             */
/*   Updated: 2020/12/12 15:24:48 by akasha           ###   ########.fr       */
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
	t_hero	ray;

	ray = config->hero;
	ray.y = (config->hero.y + 0.5) * config->map.scale;
	ray.x = (config->hero.x + 0.5) * config->map.scale;
	ray.start = config->hero.dir - (M_PI / 4);
	ray.end = config->hero.dir + (M_PI / 4);
	while (ray.start <= ray.end)
	{
		ray.y = (config->hero.y + 0.5) * config->map.scale;
		ray.x = (config->hero.x + 0.5) * config->map.scale;
		cast_ray(config, ray);
		ray.start += (M_PI / 2) / 1920;
	}
}