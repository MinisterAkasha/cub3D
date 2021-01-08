/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akasha <akasha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 16:19:03 by akasha            #+#    #+#             */
/*   Updated: 2021/01/08 20:10:15 by akasha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	init_struct(t_config *config)
{
	config->map.has_hero = 0;
	config->map.height = 0;
	// config->map.map = fill_map(config, ft_lstsize(config->head_map));
	fill_map(config, ft_lstsize(config->head_map));
	config->map.hero_set = "NSEW";
	config->map.inner_set = "012 NSEW";
	config->map.space_set = "1 ";
	config->map.sprites_num = 0;
	config->hero.move_speed = 0.2;
	config->hero.rotate_speed = M_PI / 30;
}

void	init_error(t_config *config)
{
	t_error *errors;

	errors = &config->error;
	errors->error[0] = "Passed too many arguments\n";
	errors->error[1] = "Passed not enough arguments\n";
	errors->error[2] = "Too many heros on the map\n";
	errors->error[3] = "Missing hero on the map\n";
	errors->error[4] = "Not valid map\n";
	errors->error[5] = "Not valid parametr for window size\n";
	errors->error[6] = "Not valid parametr for texture\n";
	errors->error[7] = "Not valid parametr for floor/celling color\n";
	errors->error[8] = "The color value must be in the range from 0 to 255\n";
	errors->error[9] = "Not not enough parametrs\n";
	errors->error[10] = "RGB must contains only 3 parameters\n";
	errors->error[11] = "Invalid file name\n";
}

void	init_sprites(t_config *config)
{
	int y;
	int x;
	int i;
	
	config->sprite_pos = (t_sprite_position *)malloc(sizeof(t_sprite_position) * config->map.sprites_num);

	i = 0;
	y = 0;
	while (config->map.map[y])
	{
		x = 0;
		while (config->map.map[y][x])
		{
			if (config->map.map[y][x] == '2') // Определяет позицию каждого спрайта
			{
				config->sprite_pos[i].y = y + 0.5;
				config->sprite_pos[i].x = x + 0.5;
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
			if (config->map.map[y][x] == '2') // Считаю кол-во спрайтов
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