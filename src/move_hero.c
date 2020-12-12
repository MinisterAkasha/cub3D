/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_hero.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akasha <akasha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 14:41:17 by akasha            #+#    #+#             */
/*   Updated: 2020/12/12 15:36:15 by akasha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

#include "stdio.h" //!DEL

int	move_hero(int keycode, t_config *config)
{
	if (button(keycode))
	{
		mlx_destroy_image(config->win.mlx, config->data.img);
		if (keycode == 13)
			// config->hero.y = config->map.map[(int)config->hero.y - 1][(int)config->hero.x];
			config->hero.y -= 0.5;
		if (keycode == 0)
			config->hero.x -= 0.5;
		if (keycode == 1)
			config->hero.y += 0.5;
		if (keycode == 2)
			config->hero.x += 0.5;
		if (keycode == 123)
			config->hero.dir -= M_PI / 60;
		if (keycode == 124)
			config->hero.dir += M_PI / 60;
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