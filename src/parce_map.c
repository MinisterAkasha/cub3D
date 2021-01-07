/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parce_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akasha <akasha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 16:35:58 by akasha            #+#    #+#             */
/*   Updated: 2021/01/07 16:35:59 by akasha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	parce_map(t_config *config)
{
	int		y;
	int		x;

	y = 0;
	while (config->map.map[y])
	{
		x = 0;
		while (config->map.map[y][x])
		{
			ft_validate_map(config, y, x);
			x++;
		}
		y++;
	}
}
