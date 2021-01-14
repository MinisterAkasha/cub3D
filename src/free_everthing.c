/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_everthing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akasha <akasha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 19:54:31 by akasha            #+#    #+#             */
/*   Updated: 2021/01/14 18:44:18 by akasha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	free_texture_arr(t_config *config)
{
	int i;

	i = 0;
	while (i < 5)
	{
		free(config->img.texture[i]);
		i++;
	}
}

void	free_map(t_config *config)
{
	int i;

	i = ft_lstsize(config->head_map);
	while (i >= 0)
		free(config->map.map[i--]);
	free(config->map.map);
}

void	free_side_tex(t_config *config)
{
	if (config->params.north_tex)
		free(config->params.north_tex);
	if (config->params.south_tex)
		free(config->params.south_tex);
	if (config->params.west_tex)
		free(config->params.west_tex);
	if (config->params.east_tex)
		free(config->params.east_tex);
	if (config->params.spraite_tex)
		free(config->params.spraite_tex);
}

void	free_all(t_config *config)
{
	if (config->map.map)
		free_map(config);
	ft_lstclear(&config->head_map, free);
	ft_lstclear(&config->head_param, free);
	if (config->sprite_pos)
		free(config->sprite_pos);
	free_side_tex(config);
	free(config);
	free_texture_arr(config);
}