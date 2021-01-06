/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parce_param.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akasha <akasha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/03 15:15:21 by akasha            #+#    #+#             */
/*   Updated: 2021/01/06 15:55:44 by akasha           ###   ########.fr       */
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

int		parce_window_param(t_config *config, char *str)
{
	if (get_numbers_num(str) != 2)
		exit_cub(5, config);
	skip_not_number(&str);
	config->settings.window_width = ft_atoi(str);
	config->settings.has_param[7] = 1;
	skip_number(&str);
	skip_not_number(&str);
	config->settings.window_height = ft_atoi(str);
	config->settings.has_param[8] = 1;
	if (!config->settings.window_height || !config->settings.window_width
	|| config->settings.window_height < 0 || config->settings.window_width < 0)
		exit_cub(5, config);
	check_max_size(config);
	return (1);
}

int		parce_tex(t_config *config, char *str)
{
	char	**tex;

	if ((*str == 'N' && *(str + 1) == 'O'))
	{
		config->settings.has_param[0] = 1;
		tex = &config->settings.north_tex;
	}
	else if ((*str == 'S' && *(str + 1) == 'O'))
	{
		config->settings.has_param[1] = 1;
		tex = &config->settings.south_tex;
	}
	else if ((*str == 'W' && *(str + 1) == 'E'))
	{
		config->settings.has_param[2] = 1;
		tex = &config->settings.west_tex;
	}
	else if ((*str == 'E' && *(str + 1) == 'A'))
	{
		config->settings.has_param[3] = 1;
		tex = &config->settings.east_tex;
	}
	else
	{
		config->settings.has_param[4] = 1;
		tex = &config->settings.spraite_tex;
	}
	while (*str != ' ')
		str++;
	str += skip_spaces(str);
	*tex = ft_strtrim(str, " "); //TODO free *tex
	return (1);
}

void		find_correct_param_and_parce(char *str, t_config *config)
{
	if (*str == 'R')
		parce_window_param(config, ++str);
	else if ((*str == 'N' && *(str + 1) == 'O')
			|| (*str == 'S')
			|| (*str == 'W' && *(str + 1) == 'E')
			|| (*str == 'E' && *(str + 1) == 'A'))
		parce_tex(config, str);
	else if (*str == 'F' || *str == 'C')
		parce_color(config, str);
}

void	check_all_params(t_config *config)
{
	int i;

	i = 0;
	while (i < 9)
	{
		if (!(config->settings.has_param[i]))
			exit_cub(8, config);
		i++;
	}
}

int		parce_param(t_config *config)
{
	t_list	*tmp;
	char	*str;

	tmp = config->head_param;
	while (tmp)
	{
		str = tmp->content;
		str += skip_spaces(str);
		find_correct_param_and_parce(str, config);
		tmp = tmp->next;
	}
	check_all_params(config);
	return (1);
}