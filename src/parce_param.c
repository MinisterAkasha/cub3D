/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parce_param.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akasha <akasha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/03 15:15:21 by akasha            #+#    #+#             */
/*   Updated: 2021/01/03 19:13:25 by akasha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
void	check_max_size(t_config *config)
{
	mlx_get_screen_size(config->win.mlx, &config->settings.max_width,
		&config->settings.max_height);
	if (config->settings.window_height > config->settings.max_height)
		config->settings.window_height = config->settings.max_height;
	if (config->settings.window_width > config->settings.max_width)
		config->settings.window_width = config->settings.max_width;
}

size_t	create_hex_from_rgb(int red, int green, int blue)
{
	return ((red << 16) + (green << 8) + (blue));
}

int		find_color_num(char **str, int *color)
{
	skip_not_digit(str);
	if (ft_isdigit(**str))
		*color = ft_atoi(*str);
	else if (**str == '\n')
		return (0);
	skip_digit(str);
	return (1);
}

int		parce_color(t_config *config, char *str)
{
	int	red;
	int	green;
	int	blue;
	int	is_floor;

	if (*str == 'F')
		is_floor = 1;
	else
		is_floor = 0;
	if (!(find_color_num(&str, &red)))
		return (0);
	if (!(find_color_num(&str, &green)))
		return (0);
	if (!(find_color_num(&str, &blue)))
		return (0);
	// find_color_num(&str, &green);
	// find_color_num(&str, &blue);

	if (is_floor)
		config->settings.floor_color = create_hex_from_rgb(red, green, blue);
	printf("R: %-5d G: %-5d B: %-5d\n", red, green, blue);
	// printf("%zu\n", config->settings.floor_color);
	return (1);
}

int		parce_window_param(t_config *config, char *str)
{
	skip_not_digit(&str);
	config->settings.window_width = ft_atoi(str);
	skip_digit(&str);
	skip_not_digit(&str);
	config->settings.window_height = ft_atoi(str);
	if (!config->settings.window_height || !config->settings.window_width
	|| config->settings.window_height < 0 || config->settings.window_width < 0)
		return (0);
	check_max_size(config);
	return (1);
}

int		parce_tex(t_config *config, char *str)
{
	char	**tex;

	if ((*str == 'N' && *(str + 1) == 'O'))
		tex = &config->settings.north_tex;
	else if ((*str == 'S' && *(str + 1) == 'O'))
		tex = &config->settings.south_tex;
	else if ((*str == 'W' && *(str + 1) == 'E'))
		tex = &config->settings.west_tex;
	else if ((*str == 'E' && *(str + 1) == 'A'))
		tex = &config->settings.east_tex;
	else
		tex = &config->settings.spraite_tex;
	while (*str != ' ')
		str++;
	str += skip_spaces(str);
	*tex = ft_strtrim(str, " "); //TODO free *tex
	return (1);
}

int		find_correct_param_and_parce(char *str, t_config *config)
{
	if (*str == 'R')
	{
		if (!(parce_window_param(config, ++str)))
		{
			write(1, "Not valid parametr for window size\n", 36); //TODO error message
			return (0);
		}
	}
	else if ((*str == 'N' && *(str + 1) == 'O')
			|| (*str == 'S')
			|| (*str == 'W' && *(str + 1) == 'E')
			|| (*str == 'E' && *(str + 1) == 'A'))
	{
		if (!(parce_tex(config, str)))
		{
			write(1, "Not valid parametr for texture\n", 38); //TODO error message
			return (0);
		}
	}
	else if (*str == 'F' || *str == 'C')
	{
		if (!(parce_color(config, str)))
		{
			write(1, "Not valid parametr for floor/celling color\n", 44); //TODO error message
			return (0);
		}
	}
	return (1);
}

int		parce_param(t_config *config)
{
	t_list	*tmp;
	char	*str;
	int		i;

	tmp = config->head_param;
	while (tmp)
	{
		str = tmp->content;
		i = skip_spaces(str);
		str += i;
		if (!(find_correct_param_and_parce(str, config)))
			return (0);
		tmp = tmp->next;
	}
	return (1);
}