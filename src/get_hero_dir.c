#include "cub.h"

void	get_hero_dir(t_config *config, int y, int x)
{
	if (config->map.map[y][x] == 'N')
		set_north_dir(config);
	if (config->map.map[y][x] == 'W')
		set_west_dir(config);
	if (config->map.map[y][x] == 'S')
		set_south_dir(config);
	if (config->map.map[y][x] == 'E')
		set_east_dir(config);
}

void	set_north_dir(t_config *config)
{
	config->hero.dir_x = 0;
	config->hero.dir_y = -1;
	config->hero.plane_x = -0.66;
	config->hero.plane_y = 0;
}

void	set_west_dir(t_config *config)
{
	config->hero.dir_x = 1;
	config->hero.dir_y = 0;
	config->hero.plane_x = 0;
	config->hero.plane_y = -0.66;
}

void	set_south_dir(t_config *config)
{
	config->hero.dir_x = 0;
	config->hero.dir_y = 1;
	config->hero.plane_x = 0.66;
	config->hero.plane_y = 0;
}

void	set_east_dir(t_config *config)
{
	config->hero.dir_x = -1;
	config->hero.dir_y = 0;
	config->hero.plane_x = 0;
	config->hero.plane_y = 0.66;
}
