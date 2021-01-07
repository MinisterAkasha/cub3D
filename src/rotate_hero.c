/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_hero.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akasha <akasha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 15:33:11 by akasha            #+#    #+#             */
/*   Updated: 2021/01/07 16:05:41 by akasha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	ft_rotate_left(t_config *config)
{
	double old_dir_x;
	double old_plane_x;
	t_hero *hero;

	hero = &config->hero;
	old_dir_x = hero->dir_x;
	old_plane_x = hero->plane_x;
	hero->dir_x = hero->dir_x * cos(hero->rotate_speed) -
					hero->dir_y * sin(hero->rotate_speed);
	hero->dir_y = old_dir_x * sin(hero->rotate_speed) +
					hero->dir_y * cos(hero->rotate_speed);
	hero->plane_x = hero->plane_x * cos(hero->rotate_speed) -
					hero->plane_y * sin(hero->rotate_speed);
	hero->plane_y = old_plane_x * sin(hero->rotate_speed) +
					hero->plane_y * cos(hero->rotate_speed);
}

void	ft_rotate_right(t_config *config)
{
	double old_dir_x;
	double old_plane_x;
	t_hero *hero;

	hero = &config->hero;
	old_dir_x = hero->dir_x;
	old_plane_x = hero->plane_x;
	hero->dir_x = hero->dir_x * cos(-hero->rotate_speed) -
					hero->dir_y * sin(-hero->rotate_speed);
	hero->dir_y = old_dir_x * sin(-hero->rotate_speed) +
					hero->dir_y * cos(-hero->rotate_speed);
	hero->plane_x = hero->plane_x * cos(-hero->rotate_speed) -
					hero->plane_y * sin(-hero->rotate_speed);
	hero->plane_y = old_plane_x * sin(-hero->rotate_speed) +
					hero->plane_y * cos(-hero->rotate_speed);
}
