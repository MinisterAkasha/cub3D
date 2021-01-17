/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akasha <akasha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 20:07:27 by akasha            #+#    #+#             */
/*   Updated: 2021/01/16 20:26:39 by akasha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	load_images(t_config *config)
{
	int		index;
	char	*path;

	index = 0;
	while (index < 5)
	{
		path = get_texture_path(index, config);
		config->img.img[index] = mlx_xpm_file_to_image(config->win.mlx, path,
							&config->img.width[index],
							&config->img.height[index]);
		config->img.addr[index] = mlx_get_data_addr(config->img.img[index],
						&config->img.bits_per_pixel[index],
						&config->img.line_length[index],
						&config->img.endian[index]);
		make_texture(config, index);
		index++;
	}
}

char	*get_texture_path(int index, t_config *config)
{
	if (index == 0)
		return (config->params.south_tex);
	if (index == 1)
		return (config->params.north_tex);
	if (index == 2)
		return (config->params.east_tex);
	if (index == 3)
		return (config->params.west_tex);
	if (index == 4)
		return (config->params.spraite_tex);
	return (NULL);
}

void	make_texture(t_config *config, int i)
{
	int			x;
	int			y;
	t_texture	*img;
	int			pixel;

	x = 0;
	img = &config->img;
	if (!(img->texture[i] = (size_t *)malloc(sizeof(size_t) *
							(img->width[i] * img->height[i]))))
		exit_cub(15, config);
	while (x < img->width[i])
	{
		y = 0;
		while (y < img->height[i])
		{
			pixel = img->width[i] * y + x;
			img->texture[i][pixel] = *(unsigned int*)(img->addr[i] +
									(y * img->line_length[i] +
									x * (img->bits_per_pixel[i] / 8)));
			y++;
		}
		x++;
	}
}
