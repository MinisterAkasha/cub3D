/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   support.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akasha <akasha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 15:51:51 by akasha            #+#    #+#             */
/*   Updated: 2021/01/07 14:21:27 by akasha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int				get_spases_num(char *str)
{
	int spaces_len;

	spaces_len = 0;
	while (*str)
	{
		if (*str == ' ')
			spaces_len++;
		str++;
	}
	return (spaces_len);
}

int				get_numbers_num(char *str)
{
	int numbers;
	int	i;

	numbers = 0;
	i = 0;
	while (str[i])
	{
		if (ft_isdigit(str[i]))
		{
			numbers++;
			while (str[i] && ft_isdigit(str[i]))
				i++;
		}
		i++;
	}
	return (numbers);
}

unsigned long	translat_to_hex(int red, int green, int blue)
{
	return (red << 16 | green << 8 | blue);
}

int				get_commas_num(char *str)
{
	int commas;

	commas = 0;
	while (*str)
	{
		if (*str == ',')
			commas++;
		str++;
	}
	return (commas);
}

void			fast_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length +
						x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}
