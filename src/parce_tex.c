/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parce_tex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akasha <akasha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 16:01:07 by akasha            #+#    #+#             */
/*   Updated: 2021/01/07 15:17:20 by akasha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	parce_tex(t_config *config, char *str)
{
	char	**tex;

	if ((*str == 'N' && *(str + 1) == 'O'))
	{
		config->params.has_param[0] = 1;
		tex = &config->params.north_tex;
	}
	else if ((*str == 'S' && *(str + 1) == 'O'))
	{
		config->params.has_param[1] = 1;
		tex = &config->params.south_tex;
	}
	else if ((*str == 'W' && *(str + 1) == 'E'))
	{
		config->params.has_param[2] = 1;
		tex = &config->params.west_tex;
	}
	else if ((*str == 'E' && *(str + 1) == 'A'))
	{
		config->params.has_param[3] = 1;
		tex = &config->params.east_tex;
	}
	else
	{
		config->params.has_param[4] = 1;
		tex = &config->params.spraite_tex;
	}
	while (*str != ' ')
		str++;
	str += skip_spaces(str);
	*tex = ft_strtrim(str, " "); //TODO free *tex
}