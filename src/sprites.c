/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akasha <akasha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 17:44:03 by akasha            #+#    #+#             */
/*   Updated: 2021/01/07 19:07:20 by akasha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	fill_sprites_arr(t_config *config, double sprite_order[], double sprite_distanse[])
{
	int i;
	
	i = 0;
	while (i < config->map.sprites_num)
	{
		sprite_order[i] = i;
		sprite_distanse[i] = (config->hero.x - config->sprite_pos[i].x) * (config->hero.x - config->sprite_pos[i].x) +
			(config->hero.y - config->sprite_pos[i].y) * (config->hero.y - config->sprite_pos[i].y);
		i++;
	}
}

void	sprite_cast(t_config *config, double z_buffer[(int)config->params.window_width])
{
	int 	i;
	double	sprite_order[config->map.sprites_num];
	double	sprite_distanse[config->map.sprites_num];

	double	sprite_x;
	double	sprite_y;
	double	invert_determ;
	double	transform_x;
	double	transform_y;
	int		sprite_screen_x;
	int		sprite_height;
	int		sprite_width;

	int		drow_start_y;
	int		drow_end_y;
	int		drow_start_x;
	int		drow_end_x;


	fill_sprites_arr(config, sprite_order, sprite_distanse);
	sort_sprites(sprite_distanse, 0, config->map.sprites_num - 1, sprite_order);
	drow_sprite()//TODO доделать
	i = 0;
	while (i < config->map.sprites_num)
	{
		sprite_x = config->sprite_pos[(int)sprite_order[i]].x - config->hero.x;
		sprite_y = config->sprite_pos[(int)sprite_order[i]].y - config->hero.y;

		invert_determ = 1.0 / (config->hero.plane_x * config->hero.dir_y - config->hero.plane_y * config->hero.dir_x);

		transform_x = invert_determ * (config->hero.dir_y * sprite_x - config->hero.dir_x * sprite_y);
		transform_y = invert_determ * (config->hero.plane_x * sprite_y - config->hero.plane_y * sprite_x);

		sprite_screen_x = (int)((config->params.window_width / 2) * (1 + transform_x / transform_y));

		sprite_height = abs((int)(config->params.window_height / transform_y));

		drow_start_y = -sprite_height / 2 + config->params.window_height / 2;
		if (drow_start_y < 0)
			drow_start_y = 0;
		drow_end_y = sprite_height / 2 + config->params.window_height / 2;
		if (drow_end_y >= config->params.window_height)
			drow_end_y = config->params.window_height - 1;

		sprite_width = abs((int)(config->params.window_height / (transform_y)));

		drow_start_x = -sprite_width / 2 + sprite_screen_x;
		if (drow_start_x < 0)
			drow_start_x = 0;
		drow_end_x = sprite_width / 2 + sprite_screen_x;
		if (drow_end_x > config->params.window_width)
			drow_end_x = config->params.window_width - 1;
		int x = drow_start_x;
		while (x < drow_end_x)
		{
			int y = drow_start_y;
			int tex_x = (int)(256 * (x - (-sprite_width / 2 + sprite_screen_x)) * config->img.width[4] / sprite_width) / 256;
			if (transform_y > 0 && x > 0 && x < (int)config->params.window_width && transform_y < z_buffer[x])
			{
				while (y < drow_end_y)
				{
					int d = y * 256 - config->params.window_height * 128 + sprite_height * 128;
					int tex_y = ((d * config->img.height[4]) / sprite_height) / 256;
					if ((config->img.texture[4][config->img.height[4] * tex_y + tex_x] & 0x00FFFFFF))
						fast_pixel_put(&config->data, x, y, config->img.texture[4][config->img.width[4] * tex_y + tex_x]);
					y++;
				}
			}
			x++;
		}
		i++;
	}
}
