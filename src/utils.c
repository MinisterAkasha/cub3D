/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akasha <akasha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 19:17:27 by akasha            #+#    #+#             */
/*   Updated: 2021/01/03 19:12:18 by akasha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_find_width(char *str, t_config	*config)
{
	size_t	len;

	len = ft_strlen(str);
	if (config->map.width < len)
		config->map.width = len;
}

int		skip_spaces(char *str)
{
	int i;

	i = 0;
	while (str[i] == ' ')
		i++;
	return (i);
}

void	skip_digit(char **str)
{
	while (ft_isdigit(**str))
		*str += 1;
}
void	skip_not_digit(char **str)
{
	while (!(ft_isdigit(**str)))
	{
		if (**str == '\n')
			break ;
		*str += 1;
	}
}