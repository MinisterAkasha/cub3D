/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_lists.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akasha <akasha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 23:32:46 by akasha            #+#    #+#             */
/*   Updated: 2021/01/08 23:33:10 by akasha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	fill_param_list(t_config *config, int fd)
{
	char	*param_line;
	int		i;

	i = skip_spaces(param_line);
	while (param_line[i] != '1')
	{
		i = skip_spaces(param_line);
		get_next_line(fd, &param_line);
		if (param_line[i] == '1')
		{
			ft_lstadd_back(&config->head_map, ft_lstnew(param_line));
			return ;
		}
		ft_lstadd_back(&config->head_param, ft_lstnew(param_line));
	}
}

void	fill_map_list(t_config *config, int fd)
{
	t_list	*tmp;
	char	*map_line;

	config->map.width = 0;
	config->map.new_line = 0;
	ft_find_width(config->head_map->content, config);
	while (get_next_line(fd, &map_line))
	{
		ft_find_width(map_line, config);
		if (!*map_line)
			config->map.new_line++;
		ft_lstadd_back(&config->head_map, ft_lstnew(map_line));
	}
	ft_find_width(map_line, config);
	ft_lstadd_back(&config->head_map, ft_lstnew(map_line));
}