/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akasha <akasha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 19:16:25 by akasha            #+#    #+#             */
/*   Updated: 2021/01/03 14:17:45 by akasha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

char	**fill_map(t_config *config, int size)
{
	char		**map;
	t_list		*tmp;
	size_t		len_dif;
	int			i;
	char		*str;

	if (!(map = ft_calloc((size + 1), sizeof(char **))))
		return (0);
	tmp = config->head_map;
	i = 0;
	while (tmp)
	{
		len_dif = config->map.width - ft_strlen(tmp->content);
		str = (char *)malloc(sizeof(char) * (len_dif + 1));
		str[len_dif] = 0;
		ft_memset(str, ' ', len_dif);
		map[i++] = ft_strjoin(tmp->content, str);
		free(str);
		config->map.height++;
		tmp = tmp->next;
	}
	return (map);
}