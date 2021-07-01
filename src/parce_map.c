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
