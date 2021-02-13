/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parce_window.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 15:59:14 by akasha            #+#    #+#             */
/*   Updated: 2021/02/13 19:10:05 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	check_max_size(t_config *config)
{
	mlx_get_screen_size(config->win.mlx, &config->params.max_width,
		&config->params.max_height);
	if (config->params.window_height > config->params.max_height)
		config->params.window_height = config->params.max_height;
	if (config->params.window_width > config->params.max_width)
		config->params.window_width = config->params.max_width;
}

void	validate_window_param(t_config *config, char *str)
{
	int i;

	i = 0;
	if (get_numbers_num(str) != 2)
		exit_cub(5, config);
	if (*str != ' ')
		exit_cub(5, config);
	while (str[i])
	{
		if (!(ft_isdigit(str[i])) && str[i] != ' ')
			exit_cub(5, config);
		i++;
	}
}

int		get_number_len(char *str)
{
	int i;

	i = 0;
	while (ft_isdigit(str[i]))
		i++;
	return (i);
}

int		parce_window_param(t_config *config, char *str)
{
	validate_window_param(config, str);
	mlx_get_screen_size(config->win.mlx, &config->params.max_width,
		&config->params.max_height);
	skip_not_number(&str);
	config->params.window_width = ft_atoi(str);
	if (get_number_len(str) > 6 && ft_atoi(str) < 0)
		config->params.window_width = config->params.max_width;
	config->params.has_param[7]++;
	skip_number(&str);
	skip_not_number(&str);
	if (get_number_len(str) > 6 && ft_atoi(str) < 0)
		config->params.window_height = config->params.max_height;
	else
		config->params.window_height = ft_atoi(str);
	config->params.has_param[8]++;
	if (!config->params.window_height || !config->params.window_width
	|| config->params.window_height < 0 || config->params.window_width < 0)
		exit_cub(5, config);
	check_max_size(config);
	return (1);
}
