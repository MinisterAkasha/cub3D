/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akasha <akasha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 17:44:03 by akasha            #+#    #+#             */
/*   Updated: 2021/01/08 19:18:36 by akasha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	fill_sprites_arr(t_config *config)
{
	int i;

	if (!(config->sprite.sprite_order = (double *)malloc(sizeof(double) * config->map.sprites_num)))
		exit_cub(15, config);
	if (!(config->sprite.sprite_distanse = (double *)malloc(sizeof(double) * config->map.sprites_num)))
		exit_cub(15, config);
	i = 0;
	while (i < config->map.sprites_num)
	{
		config->sprite.sprite_order[i] = i;
		config->sprite.sprite_distanse[i] = (config->hero.x - config->sprite_pos[i].x) * (config->hero.x - config->sprite_pos[i].x) +
			(config->hero.y - config->sprite_pos[i].y) * (config->hero.y - config->sprite_pos[i].y);
		i++;
	}
}

void	get_sprite_coordinates(t_config *config, int i)
{
	t_sprite *sprite;

	sprite = &config->sprite;
	sprite->sprite_x = config->sprite_pos[(int)sprite->sprite_order[i]].x - config->hero.x;
	sprite->sprite_y = config->sprite_pos[(int)sprite->sprite_order[i]].y - config->hero.y;
}

double	get_invert_determ_value(t_config *config)
{
	t_hero *hero;

	hero = &config->hero;
	return (1.0 / (hero->plane_x * hero->dir_y - hero->plane_y * hero->dir_x));
}

void	drow_sprite(t_config *config)
{
	int i;

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

	i = 0;
	while (i < config->map.sprites_num)
	{
		get_sprite_coordinates(config, i);
		invert_determ = get_invert_determ_value(config);
		


		transform_x = invert_determ * (config->hero.dir_y * config->sprite.sprite_x - config->hero.dir_x * config->sprite.sprite_y);
		transform_y = invert_determ * (config->hero.plane_x * config->sprite.sprite_y - config->hero.plane_y * config->sprite.sprite_x);

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
			if (transform_y > 0 && x > 0 && x < (int)config->params.window_width && transform_y < config->sprite.z_buffer[x])
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

void	sprite_cast(t_config *config)
{
	fill_sprites_arr(config);
	sort_sprites(config, 0, config->map.sprites_num - 1);
	drow_sprite(config);
	free(config->sprite.sprite_order);
	free(config->sprite.sprite_distanse);
}
