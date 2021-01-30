/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parce_tex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akasha <akasha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 16:01:07 by akasha            #+#    #+#             */
/*   Updated: 2021/01/30 21:05:45 by akasha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	remember_presence_texture(t_config *config)
{
	if (config->params.north_tex)
		config->params.has_param[0]++;
	if (config->params.south_tex)
		config->params.has_param[1]++;
	if (config->params.west_tex)
		config->params.has_param[2]++;
	if (config->params.east_tex)
		config->params.has_param[3]++;
	if (config->params.spraite_tex)
		config->params.has_param[4]++;
}

void	validate_tex_params(t_config *config, char *str)
{
	if ((*str == 'S' && *(str + 1) != 'O'))
	{
		if (*(str + 1) != ' ')
			exit_cub(12, config);
	}
	else
	{
		if (*(str + 2) != ' ')
			exit_cub(12, config);
	}
}

void	check_valid_path(t_config *config, char **path)
{
	int fd;
	int len;
	char *copy;
	char buf;

	fd = open(*path, O_RDONLY);
	if (read(fd, &buf, 1) < 0)
		exit_cub(12, config);
	if (fd == -1)
		exit_cub(12, config);
	close(fd);
	len = ft_strlen(*path);
	copy = ft_strdup(*path);
	if (copy[len - 1] != 'm' && copy[len - 2] != 'p' && copy[len - 3] != 'x')
	{
		free(copy);
		exit_cub(12, config);
	}
	free(copy);
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
	validate_tex_params(config, str);
	while (*str != ' ')
		str++;
	str += skip_spaces(str);
	*tex = ft_strtrim(str, " ");
	check_valid_path(config, tex);
	remember_presence_texture(config);
}
