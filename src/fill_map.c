/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akasha <akasha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 19:16:25 by akasha            #+#    #+#             */
/*   Updated: 2020/12/13 16:30:29 by akasha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

char	**fill_map(t_list *head, int size, t_config *config)
{
	char		**map;
	t_list		*tmp;
	size_t		len_dif;
	int			i;
	char		*str;

	if (!(map = ft_calloc((size + 1), sizeof(char **))))
		return (0);
	tmp = head;
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
	i = 0;
	while (map[i])
	{
		ft_putendl_fd(map[i], 1);
		i++;
	}
	return (map);
}