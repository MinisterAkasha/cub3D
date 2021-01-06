/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parce_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akasha <akasha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 15:53:49 by akasha            #+#    #+#             */
/*   Updated: 2021/01/06 15:56:08 by akasha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	check_color_value(int color, t_config *config)
{
	if (color > 255 || color < 0)
		exit_cub(7, config);
}

int		find_color_num(char **str, int *color)
{
	skip_not_number(str);
	if (ft_isdigit(**str) || **str == '-')
		*color = ft_atoi(*str);
	skip_number(str);
	return (1);
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

int		parce_color(t_config *config, char *str)
{
	int i;
	int	rgb_color[3];
	int	is_floor;

	validate_color_params(str, config);
	if (*str == 'F')
		is_floor = 1;
	else
		is_floor = 0;
	i = 0;
	while (i < 3)
	{
		find_color_num(&str, &rgb_color[i]);
		check_color_value(rgb_color[i], config);
		i++;
	}
	if (is_floor)
	{
		config->settings.has_param[5] = 1;
		config->settings.floor_color = create_hex_from_rgb(rgb_color[0], rgb_color[1], rgb_color[2]);
	}
	else
	{
		config->settings.has_param[6] = 1;
		config->settings.celling_color = create_hex_from_rgb(rgb_color[0], rgb_color[1], rgb_color[2]);
	}
	return (1);
}