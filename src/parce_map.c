/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parce_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akasha <akasha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 15:29:33 by akasha            #+#    #+#             */
/*   Updated: 2021/01/03 15:06:37 by akasha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int		parce_map(t_config *config)
{
	int		y;
	int		x;

	y = 0;
	while (config->map.map[y])
	{
		x = 0;
		while (config->map.map[y][x])
		{
			if (!ft_validate_map(config, y, x))
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}
