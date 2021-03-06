#include "cub.h"

int		ft_check_inner_elem(t_config *config, int y, int x)
{
	if (config->map.map[y][x] == ' ')
	{
		if (!ft_strchr(config->map.space_set, config->map.map[y][x - 1]) ||
			!ft_strchr(config->map.space_set, config->map.map[y][x + 1]) ||
			!ft_strchr(config->map.space_set, config->map.map[y - 1][x]) ||
			!ft_strchr(config->map.space_set, config->map.map[y + 1][x]))
			exit_cub(4, config);
	}
	else
	{
		if (!ft_strchr(config->map.inner_set, config->map.map[y][x]))
			exit_cub(4, config);
	}
	return (1);
}

int		ft_check_border(t_config *config, int y, int x)
{
	if (config->map.map[y][x] == ' ')
	{
		if (x != 0)
			if (!(ft_strchr(config->map.space_set, config->map.map[y][x - 1])))
				exit_cub(4, config);
		if (x != (int)(config->map.width - 1))
			if (!(ft_strchr(config->map.space_set, config->map.map[y][x + 1])))
				exit_cub(4, config);
		if (y != 0)
			if (!(ft_strchr(config->map.space_set, config->map.map[y - 1][x])))
				exit_cub(4, config);
		if (y != (int)(config->map.height - 1))
			if (!(ft_strchr(config->map.space_set, config->map.map[y + 1][x])))
				exit_cub(4, config);
	}
	else
	{
		if (!ft_strchr(config->map.space_set, config->map.map[y][x]))
			exit_cub(4, config);
	}
	return (1);
}

void	ft_check_hero(t_config *config, int y, int x)
{
	if (ft_strchr(config->map.hero_set, config->map.map[y][x]) &&
		config->map.has_hero)
		exit_cub(2, config);
	if (ft_strchr(config->map.hero_set, config->map.map[y][x]))
		config->map.has_hero = 1;
	if (y == (int)config->map.height - 1 &&
		x == (int)config->map.width - 1 &&
		!config->map.has_hero)
		exit_cub(3, config);
}

int		ft_validate_map(t_config *config, int y, int x)
{
	ft_check_hero(config, y, x);
	if (config->map.new_line >= 1)
		exit_cub(4, config);
	if (y == 0 || y == (int)(config->map.height - 1) ||
	x == (int)(config->map.width - 1) || x == 0)
		ft_check_border(config, y, x);
	else
		ft_check_inner_elem(config, y, x);
	return (1);
}
