/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akasha <akasha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 17:44:03 by akasha            #+#    #+#             */
/*   Updated: 2021/01/08 19:48:12 by akasha           ###   ########.fr       */
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
	t_sprite	*sprite;
	int			index;

	sprite = &config->sprite;
	index = sprite->sprite_order[i];
	sprite->sprite_x = config->sprite_pos[index].x - config->hero.x;
	sprite->sprite_y = config->sprite_pos[index].y - config->hero.y;
}

double	get_invert_determ_value(t_config *config)
{
	t_hero *hero;

	hero = &config->hero;
	return (1.0 / (hero->plane_x * hero->dir_y - hero->plane_y * hero->dir_x));
}

void	get_sprite_transform(t_config *config, double	invert_determ)
{
	t_hero		*hero;
	t_sprite	*sprite;

	hero = &config->hero;
	sprite = &config->sprite;
	sprite->transform_x = invert_determ * (hero->dir_y * sprite->sprite_x - hero->dir_x * sprite->sprite_y);
	sprite->transform_y = invert_determ * (hero->plane_x * sprite->sprite_y - hero->plane_y * sprite->sprite_x);
}

void	get_sprite_screen_x(t_config *config)
{
	config->sprite.sprite_screen_x = (int)((config->params.window_width / 2) * (1 + config->sprite.transform_x / config->sprite.transform_y));
}

void	get_sprite_height(t_config *config)
{
	config->sprite.sprite_height = abs((int)(config->params.window_height / config->sprite.transform_y));
}

void	get_sprite_width(t_config *config)
{
	config->sprite.sprite_width = abs((int)(config->params.window_height / (config->sprite.transform_y)));
}

void	get_drow_sprite_y_range(t_config *config)
{
	t_sprite *sprite;

	sprite = &config->sprite;
	sprite->drow_start_y = -sprite->sprite_height / 2 + config->params.window_height / 2;
	if (sprite->drow_start_y < 0)
		sprite->drow_start_y = 0;
	sprite->drow_end_y = sprite->sprite_height / 2 + config->params.window_height / 2;
	if (sprite->drow_end_y >= config->params.window_height)
		sprite->drow_end_y = config->params.window_height - 1;
}

void	get_drow_sprite_x_range(t_config *config)
{
	t_sprite *sprite;

	sprite = &config->sprite;
	sprite->drow_start_x = -sprite->sprite_width / 2 + config->sprite.sprite_screen_x;
	if (sprite->drow_start_x < 0)
		sprite->drow_start_x = 0;
	sprite->drow_end_x = sprite->sprite_width / 2 + config->sprite.sprite_screen_x;
	if (sprite->drow_end_x > config->params.window_width)
		sprite->drow_end_x = config->params.window_width - 1;
}

void	drow_sprite(t_config *config)
{
	int 	i;
	double	invert_determ;

	i = 0;
	while (i < config->map.sprites_num)
	{
		get_sprite_coordinates(config, i);
		invert_determ = get_invert_determ_value(config);
		get_sprite_transform(config, invert_determ);
		get_sprite_screen_x(config);
		get_sprite_height(config);
		get_sprite_width(config);
		get_drow_sprite_y_range(config);
		get_drow_sprite_x_range(config);
		int x = config->sprite.drow_start_x;
		while (x < config->sprite.drow_end_x)
		{
			int y = config->sprite.drow_start_y;
			int tex_x = (int)(256 * (x - (-config->sprite.sprite_width / 2 + config->sprite.sprite_screen_x)) * config->img.width[4] / config->sprite.sprite_width) / 256;
			if (config->sprite.transform_y > 0 && x > 0 && x < (int)config->params.window_width && config->sprite.transform_y < config->sprite.z_buffer[x])
			{
				while (y < config->sprite.drow_end_y)
				{
					int d = y * 256 - config->params.window_height * 128 + config->sprite.sprite_height * 128;
					int tex_y = ((d * config->img.height[4]) / config->sprite.sprite_height) / 256;
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
