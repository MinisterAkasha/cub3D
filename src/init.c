/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 16:19:03 by akasha            #+#    #+#             */
/*   Updated: 2021/02/11 20:26:52 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	init_struct(t_config *config)
{
	int i;

	i = 0;
	while (i < 9)
		config->params.has_param[i++] = 0;
	config->map.has_hero = 0;
	config->map.height = 0;
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
	errors->error[0] = "Error\nPassed too many arguments\n";
	errors->error[1] = "Error\nPassed not enough arguments\n";
	errors->error[2] = "Error\nToo many heros on the map\n";
	errors->error[3] = "Error\nMissing hero on the map\n";
	errors->error[4] = "Error\nNot valid map\n";
	errors->error[5] = "Error\nNot valid parametr for window size\n";
	errors->error[6] = "Error\nNot valid parametr for texture\n";
	errors->error[7] = "Error\nNot valid parametr for floor/celling color\n";
	errors->error[8] = "Error\n\
The color value must be in the range from 0 to 255\n";
	errors->error[9] = "Error\nNot enough parametrs\n";
	errors->error[10] = "Error\nRGB must contains only 3 parameters\n";
	errors->error[11] = "Error\nInvalid file name\n";
	errors->error[12] = "Error\nNot valid parametr for texture\n";
	errors->error[13] = "Error\nDouble key is invalid\n";
}

void	init_sprites(t_config *config)
{
	int y;
	int x;
	int i;

	if (!(config->sprite_pos = (t_sprite_position *)
			malloc(sizeof(t_sprite_position) * config->map.sprites_num)))
		exit_cub(15, config);
	i = 0;
	y = 0;
	while (config->map.map[y])
	{
		x = 0;
		while (config->map.map[y][x])
		{
			if (config->map.map[y][x] == '2')
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
			if (config->map.map[y][x] == '2')
				config->map.sprites_num++;
			if (ft_strchr(config->map.hero_set, config->map.map[y][x]))
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
