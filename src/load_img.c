/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akasha <akasha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 23:25:59 by user              #+#    #+#             */
/*   Updated: 2021/01/03 13:39:51 by akasha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void    load_img(t_config *config)
{
	int		i;
	char	*path;

	i = 0;
	while (i < 5)
	{
		path = get_texture_path(i);
		config->img.img[i] = mlx_xpm_file_to_image(config->win.mlx, path, &config->img.width[i], &config->img.height[i]);
		config->img.addr[i] = mlx_get_data_addr(config->img.img[i],
						&config->img.bits_per_pixel[i],
						&config->img.line_length[i], &config->img.endian[i]);
		make_texture(config, i);
		i++;
	}
}

char	*get_texture_path(int index)
{
	if (index == 0)
		return ("pics/stone.xpm");
	if (index == 1)
		return ("pics/hexagone.xpm");
	if (index == 2)
		return ("pics/redbrick.xpm");
	if (index == 3)
		return ("pics/wood.xpm");
	if (index == 4)
		return ("pics/barrel.xpm");
	return (NULL);
}

void	make_texture(t_config *config, int index)
{
	int x;
	int	y;

	x = 0;
	config->img.texture[index] = (size_t *)malloc(sizeof(size_t) * config->img.width[index] * config->img.height[index]);
	while (x < config->img.width[index])
	{
		y = 0;
		while (y < config->img.height[index])
		{
			config->img.texture[index][config->img.width[index] * y + x] = *(unsigned int*)(config->img.addr[index] + (y * config->img.line_length[index] + x * (config->img.bits_per_pixel[index] / 8)));
			y++;
		}
		x++;
	}
	//TODO free tucture arr
}