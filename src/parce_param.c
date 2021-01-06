/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parce_param.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akasha <akasha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/03 15:15:21 by akasha            #+#    #+#             */
/*   Updated: 2021/01/06 15:04:09 by akasha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

unsigned long	create_hex_from_rgb(int red, int green, int blue, int trans)
{
	return (trans << 24 | red  << 16 | green << 8 | blue);
}

void	check_max_size(t_config *config)
{
	mlx_get_screen_size(config->win.mlx, &config->settings.max_width,
		&config->settings.max_height);
	if (config->settings.window_height > config->settings.max_height)
		config->settings.window_height = config->settings.max_height;
	if (config->settings.window_width > config->settings.max_width)
		config->settings.window_width = config->settings.max_width;
}

int		check_color_value(int *color)
{
	if (*color > 255 || *color < 0)
		return (0);
	return (1);
}

int		get_spases_num(char *str)
{
	int spaces_len;

	spaces_len = 0;
	while (*str)
	{
		if (*str == ' ')
			spaces_len++;
		str++;
	}
	return (spaces_len);
}

char	*make_minimized_str(char *mini_str, char *str)
{
	int i;
	int j;
	int	minimized_str_len;

	i = 0;
	j = 0;
	minimized_str_len = ft_strlen(str + 1) - get_spases_num(str + 1);
	mini_str = (char *)malloc(sizeof(char) * (minimized_str_len + 1));
	mini_str[minimized_str_len] = 0;
	while (str[j])
	{
		if (str[j] != ' ')
		{
			mini_str[i] = str[j];
			i++;
		}
		j++;
	}
	return (mini_str);
}

int		get_commas_num(char *str)
{
	int commas;

	commas = 0;
	while (*str)
	{
		if (*str == ',')
			commas++;
		str++;
	}
	return (commas);
}

int		get_numbers_num(char *str)
{
	int numbers;
	int	i;

	numbers = 0;
	i = 0;
	while (str[i])
	{
		if (ft_isdigit(str[i]))
		{
			numbers++;
			while (str[i] && ft_isdigit(str[i]))
				i++;
		}
		i++;
	}
	return (numbers);
}

void 	validate_color_params(char *str, t_config *config)
{
	int		commas;
	int		numbers;
	char	*minimized_str;
	int		i;

	numbers = get_numbers_num(str);
	commas = get_commas_num(str);
	minimized_str = make_minimized_str(minimized_str, str + 1);
	i = 0;
	while(minimized_str[i])
	{
		if (minimized_str[i] == ',')
		{
			if (!(ft_isdigit(minimized_str[i - 1])) || !(ft_isdigit(minimized_str[i + 1])))
				exit_cub(7, config);
		}
		i++;
	}
	if (commas != 2 || numbers != 3)
		exit_cub(7, config);
	free(minimized_str);
}


int		find_color_num(char **str, int *color)
{
	skip_not_number(str);
	if (ft_isdigit(**str) || **str == '-')
	{
		*color = ft_atoi(*str);
		if (!(check_color_value(color)))
			return (0);
	}
	skip_number(str);
	return (1);
}

int		parce_color(t_config *config, char *str)
{
	int	red;
	int	green;
	int	blue;
	int	is_floor;

	validate_color_params(str, config);

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
	if (is_floor)
	{
		config->settings.has_param[5] = 1;
		config->settings.floor_color = create_hex_from_rgb(red, green, blue, 0);
	}
	else
	{
		config->settings.has_param[6] = 1;
		config->settings.celling_color = create_hex_from_rgb(red, green, blue, 0);
	}
	return (1);
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

int		find_correct_param_and_parce(char *str, t_config *config)
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
			// exit_cub(EINVAL, "Not valid parametr for floor/celling color");
	return (1);
}

int		check_all_params(t_config *config)
{
	int i;

	i = 0;
	while (i < 9)
	{
		if (!(config->settings.has_param[i]))
			return (0);
		i++;
	}
	return (1);
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
		if (!(find_correct_param_and_parce(str, config)))
			return (0);
		tmp = tmp->next;
	}
	if (!(check_all_params(config))) {}
		// exit_cub(EINVAL, "Not enough parameters");
	return (1);
}