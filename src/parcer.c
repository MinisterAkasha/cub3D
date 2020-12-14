/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akasha <akasha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 15:29:33 by akasha            #+#    #+#             */
/*   Updated: 2020/12/14 21:11:45 by akasha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	ft_check_inner_elem(t_config *config, int y, int x)
{
	if (config->map.map[y][x] == ' ')
	{
		if (ft_strchr(config->map.space_set, config->map.map[y][x - 1]) &&
			ft_strchr(config->map.space_set, config->map.map[y][x + 1]) &&
			ft_strchr(config->map.space_set, config->map.map[y - 1][x]) &&
			ft_strchr(config->map.space_set, config->map.map[y + 1][x]))
			return (1);
	}
	else
	{
		if (ft_strchr(config->map.inner_set, config->map.map[y][x]))
			return (1);
	}
	return (0);
}

int	ft_check_unit(t_config *config, int y, int x)
{
	if (ft_strchr(config->map.space_set, config->map.map[y][x]))
		return (1);
	return (0);
}

int	ft_check_border(t_config *config, int y, int x)
{
	if (config->map.map[y][x] == ' ')
	{
		if (x != 0)
			if (!(ft_strchr(config->map.space_set, config->map.map[y][x - 1])))
				return (0);
		if (x != (int)(config->map.width - 1))
			if (!(ft_strchr(config->map.space_set, config->map.map[y][x + 1])))
				return (0);
		if (y != 0)
			if (!(ft_strchr(config->map.space_set, config->map.map[y - 1][x])))
				return (0);
		if (y != (int)(config->map.height - 1))
			if (!(ft_strchr(config->map.space_set, config->map.map[y + 1][x])))
				return (0);
	}
	else
		return (ft_check_unit(config, y, x));
	return (1);
}

int	ft_check_map(t_config *config, int y, int x)
{
	if (y == 0 || y == (int)(config->map.height - 1) ||
	x == (int)(config->map.width - 1) || x == 0)
	{
		if (!ft_check_border(config, y, x))
			return (0);
	}
	else
	{
		if (!ft_check_inner_elem(config, y, x))
			return (0);
	}
	return (1);
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

int		parcer(t_config *config)
{
	int		y;
	int		x;
	int		has_hero;

	y = -1;
	has_hero = 0;
	if (config->map.nl >= 1)
		return (0);
	while (config->map.map[++y])
	{
		x = 0;
		while (config->map.map[y][x])
		{
			if (!ft_check_map(config, y, x) ||
			(ft_strchr(config->map.hero_set, config->map.map[y][x])
			&& has_hero))
				return (0);
			if (ft_strchr(config->map.hero_set, config->map.map[y][x]))
			{
				config->hero.y = y;
				config->hero.x = x;
				get_hero_dir(config, y, x);
				has_hero = 1;
			}
			x++;
		}
	}
	if (!has_hero)
		return (0);
	return (1);
}
