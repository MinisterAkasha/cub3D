/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akasha <akasha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 19:17:27 by akasha            #+#    #+#             */
/*   Updated: 2020/12/11 19:17:35 by akasha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_find_max_len(char *str, t_config	*config)
{
	size_t	len;

	len = ft_strlen(str);
	if (config->map.max_len < len)
		config->map.max_len = len;
}