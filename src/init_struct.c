/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akasha <akasha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 15:30:40 by akasha            #+#    #+#             */
/*   Updated: 2021/01/07 15:50:53 by akasha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	init_struct(t_config *config)
{
	config->map.has_hero = 0;
	config->map.height = 0;
	config->map.map = fill_map(config, ft_lstsize(config->head_map));
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
