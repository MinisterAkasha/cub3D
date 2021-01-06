/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parce_tex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akasha <akasha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 16:01:07 by akasha            #+#    #+#             */
/*   Updated: 2021/01/06 16:01:38 by akasha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	parce_tex(t_config *config, char *str)
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
}