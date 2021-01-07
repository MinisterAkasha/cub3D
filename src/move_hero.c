/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_hero.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akasha <akasha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 15:38:05 by akasha            #+#    #+#             */
/*   Updated: 2021/01/07 15:38:52 by akasha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_move_forward(t_config *config)
{
	t_hero	*hero;
	t_map	*map;

	hero = &config->hero;
	map = &config->map;
	if (map->map[(int)(hero->y)]
		[(int)(hero->x + hero->dir_x * (hero->move_speed + 0.1))] != '1')
		hero->x += hero->dir_x * hero->move_speed;
	if (map->map[(int)(hero->y + hero->dir_y * (hero->move_speed + 0.1))]
		[(int)(hero->x)] != '1')
		hero->y += hero->dir_y * hero->move_speed;
}

void	ft_move_back(t_config *config)
{
	t_hero	*hero;
	t_map	*map;

	hero = &config->hero;
	map = &config->map;
	if (map->map[(int)(hero->y)]
		[(int)(hero->x - hero->dir_x * (hero->move_speed + 0.1))] != '1')
		hero->x -= hero->dir_x * hero->move_speed;
	if (map->map[(int)(hero->y - hero->dir_y * (hero->move_speed + 0.1))]
		[(int)(hero->x)] != '1')
		hero->y -= hero->dir_y * hero->move_speed;
}

void	ft_move_left(t_config *config)
{
	t_hero	*hero;
	t_map	*map;

	hero = &config->hero;
	map = &config->map;
	if (map->map[(int)(hero->y)]
		[(int)(hero->x - hero->plane_x * (hero->move_speed + 0.1))] != '1')
		hero->x -= hero->plane_x * hero->move_speed;
	if (map->map[(int)(hero->y - hero->plane_y * (hero->move_speed + 0.1))]
		[(int)(hero->x)] != '1')
		hero->y -= hero->plane_y * hero->move_speed;
}

void	ft_move_right(t_config *config)
{
	t_hero	*hero;
	t_map	*map;

	hero = &config->hero;
	map = &config->map;
	if (map->map[(int)(hero->y)]
		[(int)(hero->x + hero->plane_x * (hero->move_speed + 0.1))] != '1')
		hero->x += hero->plane_x * hero->move_speed;
	if (map->map[(int)(hero->y + hero->plane_y * (hero->move_speed + 0.1))]
		[(int)(hero->x)] != '1')
		hero->y += hero->plane_y * hero->move_speed;
}
