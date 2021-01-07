/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parce_tex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akasha <akasha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 16:01:07 by akasha            #+#    #+#             */
/*   Updated: 2021/01/07 17:28:49 by akasha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	remember_presence_texture(t_config *config)
{
	if (config->params.north_tex)
		config->params.has_param[0] = 1;
	if (config->params.south_tex)
		config->params.has_param[1] = 1;
	if (config->params.west_tex)
		config->params.has_param[2] = 1;
	if (config->params.east_tex)
		config->params.has_param[3] = 1;
	if (config->params.spraite_tex)
		config->params.has_param[4] = 1;
}

void	parce_tex(t_config *config, char *str)
{
	char	**tex;

	if ((*str == 'N' && *(str + 1) == 'O'))
		tex = &config->params.north_tex;
	else if ((*str == 'S' && *(str + 1) == 'O'))
		tex = &config->params.south_tex;
	else if ((*str == 'W' && *(str + 1) == 'E'))
		tex = &config->params.west_tex;
	else if ((*str == 'E' && *(str + 1) == 'A'))
		tex = &config->params.east_tex;
	else if (*str == 'S')
		tex = &config->params.spraite_tex;
	while (*str != ' ')
		str++;
	str += skip_spaces(str);
	*tex = ft_strtrim(str, " ");
	remember_presence_texture(config);
}
