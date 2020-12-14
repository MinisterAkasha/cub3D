/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_hero.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akasha <akasha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 14:41:17 by akasha            #+#    #+#             */
/*   Updated: 2020/12/14 19:30:12 by akasha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

#include "stdio.h" //!DEL

int	move_hero(int keycode, t_config *config)
{
	double oldDirX;
	double oldplane_x;
	
	if (button(keycode))
	{
		mlx_destroy_image(config->win.mlx, config->data.img);
		if (keycode == 13) //go forward
		{
			if (config->map.map[(int)(config->hero.y)][(int)(config->hero.x + config->hero.dir_x * config->hero.move_speed)] != '1')
				config->hero.x += config->hero.dir_x * config->hero.move_speed;
			if (config->map.map[(int)(config->hero.y + config->hero.dir_y * config->hero.move_speed)][(int)(config->hero.x)] != '1')
				config->hero.y += config->hero.dir_y * config->hero.move_speed;
			// config->hero.y -= 0.5;
		}
		if (keycode == 0) //go left
		{
			if (config->map.map[(int)(config->hero.y)][(int)(config->hero.x - config->hero.dir_x * config->hero.move_speed)] == '0')
				config->hero.x -= config->hero.dir_x * config->hero.move_speed;
			// if (config->map.map[(int)(config->hero.y - config->hero.dir_y * config->hero.move_speed)][(int)(config->hero.x)] == '0')
			// 	config->hero.y -= config->hero.dir_y * config->hero.move_speed;
			// config->hero.x -= 0.5;
		}
		if (keycode == 1) // go back
		{
			if (config->map.map[(int)(config->hero.y)][(int)(config->hero.x - config->hero.dir_x * config->hero.move_speed)] == '0')
				config->hero.x -= config->hero.dir_x * config->hero.move_speed;
			if (config->map.map[(int)(config->hero.y - config->hero.dir_y * config->hero.move_speed)][(int)(config->hero.x)] == '0')
				config->hero.y -= config->hero.dir_y * config->hero.move_speed;
			// config->hero.y += 0.5;
		}
		if (keycode == 2) // go right
		{

			// config->hero.x += 0.5;
		}
		if (keycode == 123) //rotate left
		{
			oldDirX = config->hero.dir_x;
      		config->hero.dir_x = config->hero.dir_x * cos(config->hero.rotate_speed) - config->hero.dir_y * sin(config->hero.rotate_speed);
      		config->hero.dir_y = oldDirX * sin(config->hero.rotate_speed) + config->hero.dir_y * cos(config->hero.rotate_speed);
      		oldplane_x = config->hero.plane_x;
      		config->hero.plane_x = config->hero.plane_x * cos(config->hero.rotate_speed) - config->hero.plane_y * sin(config->hero.rotate_speed);
      		config->hero.plane_y = oldplane_x * sin(config->hero.rotate_speed) + config->hero.plane_y * cos(config->hero.rotate_speed);
		}
		if (keycode == 124) //rotate right
		{
			oldDirX = config->hero.dir_x;
      		config->hero.dir_x = config->hero.dir_x * cos(-config->hero.rotate_speed) - config->hero.dir_y * sin(-config->hero.rotate_speed);
      		config->hero.dir_y = oldDirX * sin(-config->hero.rotate_speed) + config->hero.dir_y * cos(-config->hero.rotate_speed);
      		oldplane_x = config->hero.plane_x;
      		config->hero.plane_x = config->hero.plane_x * cos(-config->hero.rotate_speed) - config->hero.plane_y * sin(-config->hero.rotate_speed);
      		config->hero.plane_y = oldplane_x * sin(-config->hero.rotate_speed) + config->hero.plane_y * cos(-config->hero.rotate_speed);
		}
		write_2d_map(config);
	}
	return (1);
}

// int	rotate_hero(int keycode, t_config *config)
// {
// 	if (button(keycode))
// 	{
// 		mlx_destroy_image(config->win.mlx, config->data.img);
// 		if (keycode == 123)
// 			config->hero.dir -= 1 / 360;
// 		if (keycode == 124)
// 			config->hero.dir += 1 / 360;
// 		write_2d_map(config);
// 	}
// 	return (1);
// }

int	button(int key)
{
	if (key == 13 || key == 0 || key == 1 || key == 2)
		return (1);
	if (key == 123 || key == 124)
		return (1);
	return (0);
}