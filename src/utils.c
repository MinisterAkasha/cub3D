/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 19:17:27 by akasha            #+#    #+#             */
/*   Updated: 2021/01/03 22:13:18 by user             ###   ########.fr       */
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

size_t	transform_dec_to_hex(size_t dec)
{
	int res = 0;
	int i;

	i = 0;
	printf("DEC: %zu\n", dec);
	while (dec)
	{
		res += dec % 16 * pow(i, 16);
		printf("%x\n", (res));
		i++;
		dec /= 16;
	}
	return (res);
}