/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parce_window.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akasha <akasha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 15:59:14 by akasha            #+#    #+#             */
/*   Updated: 2021/01/06 15:59:54 by akasha           ###   ########.fr       */
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