#include "cub.h"

void	check_param_line(char *str, t_config *config)
{
	if ((*str == 'S' && (*(str + 1) == 'O' || *(str + 1) == ' '))
		|| (*str == 'N' && *(str + 1) == 'O')
		|| (*str == 'E' && *(str + 1) == 'A')
		|| (*str == 'W' && *(str + 1) == 'E')
		|| (*str == 'R' && *(str + 1) == ' ')
		|| *str == '1' || *str == 'F' || *str == 'C')
		return ;
	if (*str == 0)
		return ;
	while (((*str != 'S' && (*(str + 1) != 'O' || *(str + 1) != ' '))
		|| (*str != 'N' && *(str + 1) != 'O')
		|| (*str != 'E' && *(str + 1) != 'A')
	|| (*str != 'W' && *(str + 1) != 'E') || (*str != 'R' && *(str + 1) != ' ')
	|| *str != '1' || *str != 'F' || *str != 'C') && *str)
	{
		if ((*str == 'S' && (*(str + 1) == 'O' || *(str + 1) == ' '))
		|| (*str == 'N' && *(str + 1) == 'O')
		|| (*str == 'E' && *(str + 1) == 'A')
		|| (*str == 'W' && *(str + 1) == 'E')
		|| (*str == 'R' && *(str + 1) == ' ')
		|| *str == '1' || *str == 'F' || *str == 'C')
			return ;
		str++;
	}
	exit_cub(14, config);
}

void	fill_param_list(t_config *config, int fd)
{
	char	*param_line;
	int		i;
	int		ret;

	ret = get_next_line(fd, &param_line);
	ft_lstadd_back(&config->head_param, ft_lstnew(param_line));
	i = skip_spaces(param_line);
	while (param_line[i] != '1' && ret > 0)
	{
		i = skip_spaces(param_line);
		ret = get_next_line(fd, &param_line);
		check_param_line(param_line, config);
		if (param_line[skip_spaces(param_line)] == '1')
		{
			ft_lstadd_back(&config->head_map, ft_lstnew(param_line));
			return ;
		}
		ft_lstadd_back(&config->head_param, ft_lstnew(param_line));
	}
	exit_cub(4, config);
}

void	fill_map_list(t_config *config, int fd)
{
	char	*map_line;

	config->map.width = 0;
	config->map.new_line = 0;
	ft_find_width(config->head_map->content, config);
	while (get_next_line(fd, &map_line))
	{
		ft_find_width(map_line, config);
		if (!*map_line)
			config->map.new_line++;
		ft_lstadd_back(&config->head_map, ft_lstnew(map_line));
	}
	ft_find_width(map_line, config);
	ft_lstadd_back(&config->head_map, ft_lstnew(map_line));
}
