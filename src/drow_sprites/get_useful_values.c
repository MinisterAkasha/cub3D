#include "cub.h"

double	get_invert_determ_value(t_config *config)
{
	t_hero *hero;

	hero = &config->hero;
	return (1.0 / (hero->plane_x * hero->dir_y - hero->plane_y * hero->dir_x));
}

void	get_sprite_transform(t_config *config, double invert_determ)
{
	t_hero		*hero;
	t_sprite	*sprite;

	hero = &config->hero;
	sprite = &config->sprite;
	sprite->transform_x = invert_determ *
			(hero->dir_y * sprite->sprite_x - hero->dir_x * sprite->sprite_y);
	sprite->transform_y = invert_determ *
		(hero->plane_x * sprite->sprite_y - hero->plane_y * sprite->sprite_x);
}

void	get_sprite_screen_x(t_config *config)
{
	config->sprite.sprite_screen_x = (int)((config->params.window_width / 2)
			* (1 + config->sprite.transform_x / config->sprite.transform_y));
}

void	get_sprite_height(t_config *config)
{
	config->sprite.sprite_height = abs((int)(config->params.window_height
											/ config->sprite.transform_y));
}

void	get_sprite_width(t_config *config)
{
	config->sprite.sprite_width = abs((int)(config->params.window_width
											/ (config->sprite.transform_y)));
}
