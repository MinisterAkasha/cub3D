/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akasha <akasha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 17:44:03 by akasha            #+#    #+#             */
/*   Updated: 2020/12/22 18:54:46 by akasha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	init_sprites(t_config *config)
{
	int y;
	int x;
	int i;
	
	config->sprite = (t_sprite *)malloc(sizeof(t_sprite) * config->map.sprites_num);

	i = 0;
	y = 0;
	while (config->map.map[y])
	{
		x = 0;
		while (config->map.map[y][x])
		{
			if (config->map.map[y][x] == '2')
			{
				config->sprite[i].x = x;
				config->sprite[i].y = y;
				i++;
			}
			x++;
		}
		y++;
	}
}

void	init_map_objects(t_config *config)
{
	int	x;
	int	y;

	y = 0;
	while (config->map.map[y])
	{
		x = 0;
		while (config->map.map[y][x])
		{
			if (config->map.map[y][x] == '2')
				config->map.sprites_num++;
			if (ft_strchr(config->map.hero_set, config->map.map[y][x])) // Определяю позицию героя
			{
				config->hero.y = y + 0.5;
				config->hero.x = x + 0.5;
				get_hero_dir(config, y, x);
			}
			x++;
		}
		y++;
	}
	init_sprites(config);
}

void	sprite_cast(t_config *config)
{
	int 	i;
	int		sprite_order[config->map.sprites_num];
	double	sprite_distanse[config->map.sprites_num];

	double	sprite_x;
	double	sprite_y;
	double	invert_determ;
	double	transform_x;
	double	transform_y;
	int		sprite_screen_x;
	int		sprite_height;
	

	i = 0;
	while (i < config->map.sprites_num)
	{
		sprite_order[i] = i;
		sprite_distanse[i] = (config->hero.x - config->sprite[i].x) * (config->hero.x - config->sprite[i].x) +
			(config->hero.y - config->sprite[i].y) * (config->hero.y - config->sprite[i].y);
		i++;
	}
	// sort_sprites(config, sprite_order, sprite_distanse);
	i = 0;
	while (i < config->map.sprites_num)
	{
		
		i++;
	}
}

// void	sort_sprites(t_config *config, int *order, double *distanse)
// {
	
// }

void	get_hero_dir(t_config *config, int y, int x)
{
	if (config->map.map[y][x] == 'N')
	{
		config->hero.dir_x = 0;
		config->hero.dir_y = -1;
		config->hero.plane_x = -0.66;
		config->hero.plane_y = 0;
	}
	if (config->map.map[y][x] == 'W')
	{
		config->hero.dir_x = 1;
		config->hero.dir_y = 0;
		config->hero.plane_x = 0;
		config->hero.plane_y = -0.66;
	}
	if (config->map.map[y][x] == 'S')
	{
		config->hero.dir_x = 0;
		config->hero.dir_y = 1;
		config->hero.plane_x = 0.66;
		config->hero.plane_y = 0;
	}
	if (config->map.map[y][x] == 'E')
	{
		config->hero.dir_x = -1;
		config->hero.dir_y = 0;
		config->hero.plane_x = 0;
		config->hero.plane_y = 0.66;
	}
}
