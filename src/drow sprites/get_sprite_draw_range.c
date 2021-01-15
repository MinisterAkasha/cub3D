/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_sprite_draw_range.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akasha <akasha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 17:29:36 by akasha            #+#    #+#             */
/*   Updated: 2021/01/15 17:39:56 by akasha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	get_draw_sprite_y_range(t_config *config)
{
	t_sprite *sprite;

	sprite = &config->sprite;
	sprite->draw_start_y = (-sprite->sprite_height / 2)
									+ config->params.window_height / 2;
	if (sprite->draw_start_y < 0)
		sprite->draw_start_y = 0;
	sprite->draw_end_y = (sprite->sprite_height / 2)
									+ config->params.window_height / 2;
	if (sprite->draw_end_y >= config->params.window_height)
		sprite->draw_end_y = config->params.window_height - 1;
}

void	get_draw_sprite_x_range(t_config *config)
{
	t_sprite *sprite;

	sprite = &config->sprite;
	sprite->draw_start_x = (-sprite->sprite_width / 2)
									+ config->sprite.sprite_screen_x;
	if (sprite->draw_start_x < 0)
		sprite->draw_start_x = 0;
	sprite->draw_end_x = (sprite->sprite_width / 2)
									+ config->sprite.sprite_screen_x;
	if (sprite->draw_end_x > config->params.window_width)
		sprite->draw_end_x = config->params.window_width - 1;
}
