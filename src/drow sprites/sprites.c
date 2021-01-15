/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akasha <akasha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 17:44:03 by akasha            #+#    #+#             */
/*   Updated: 2021/01/15 17:38:25 by akasha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	fill_sprites_arr(t_config *config)
{
	int			i;
	t_sprite	*sprite;

	sprite = &config->sprite;
	if (!(sprite->sprite_order = (double *)malloc(sizeof(double)
										* config->map.sprites_num)))
		exit_cub(15, config);
	if (!(sprite->sprite_distanse = (double *)malloc(sizeof(double)
										* config->map.sprites_num)))
		exit_cub(15, config);
	i = 0;
	while (i < config->map.sprites_num)
	{
		sprite->sprite_order[i] = i;
		sprite->sprite_distanse[i] = (config->hero.x - config->sprite_pos[i].x)
								* (config->hero.x - config->sprite_pos[i].x)
								+ (config->hero.y - config->sprite_pos[i].y)
								* (config->hero.y - config->sprite_pos[i].y);
		i++;
	}
}

void	draw_horizontal_sprite_line(t_config *config, int x, int tex_x)
{
	int			y;
	int			tex_y;
	int			d;
	t_sprite	*sprite;

	sprite = &config->sprite;
	y = sprite->draw_start_y;
	while (y < sprite->draw_end_y)
	{
		d = y * 256 - config->params.window_height * 128
			+ sprite->sprite_height * 128;
		tex_y = get_tex_y_coordinate(config, d);
		if ((config->img.texture[4][config->img.height[4] * tex_y + tex_x]
			& 0x00FFFFFF))
			fast_pixel_put(&config->data, x, y,
				config->img.texture[4][config->img.width[4] * tex_y + tex_x]);
		y++;
	}
}

void	draw_sprite_loop(t_config *config)
{
	int x;
	int y;
	int tex_x;

	x = config->sprite.draw_start_x;
	while (x < config->sprite.draw_end_x)
	{
		tex_x = get_tex_x_coordinate(config, x);
		if (config->sprite.transform_y > 0
			&& x > 0
			&& x < (int)config->params.window_width
			&& config->sprite.transform_y < config->sprite.depth[x])
			draw_horizontal_sprite_line(config, x, tex_x);
		x++;
	}
}

void	draw_sprite(t_config *config)
{
	int		i;
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
		get_draw_sprite_y_range(config);
		get_draw_sprite_x_range(config);
		draw_sprite_loop(config);
		i++;
	}
}

void	sprite_cast(t_config *config)
{
	fill_sprites_arr(config);
	sort_sprites(config, 0, config->map.sprites_num - 1);
	draw_sprite(config);
	free(config->sprite.sprite_order);
	free(config->sprite.sprite_distanse);
}
