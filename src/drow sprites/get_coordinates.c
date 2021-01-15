/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_coordinates.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akasha <akasha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 17:30:48 by akasha            #+#    #+#             */
/*   Updated: 2021/01/15 17:39:55 by akasha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	get_sprite_coordinates(t_config *config, int i)
{
	t_sprite	*sprite;
	int			index;

	sprite = &config->sprite;
	index = sprite->sprite_order[i];
	sprite->sprite_x = config->sprite_pos[index].x - config->hero.x;
	sprite->sprite_y = config->sprite_pos[index].y - config->hero.y;
}

int		get_tex_x_coordinate(t_config *config, int x)
{
	int			tex_x;
	t_sprite	*sprite;

	sprite = &config->sprite;
	return ((256 * (x - (-sprite->sprite_width / 2 + sprite->sprite_screen_x))
						* config->img.width[4] / sprite->sprite_width) / 256);
}

int		get_tex_y_coordinate(t_config *config, int d)
{
	int			tex_y;
	t_sprite	*sprite;

	sprite = &config->sprite;
	tex_y = ((d * config->img.height[4]) / sprite->sprite_height) / 256;
	return (tex_y);
}
