/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akasha <akasha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 16:26:36 by akasha            #+#    #+#             */
/*   Updated: 2020/12/11 19:51:52 by akasha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	init_img(t_config *config)
{
	// config->data.img = mlx_new_image(config->win.mlx, config->map.scale, config->map.scale);
	config->data.img = mlx_new_image(config->win.mlx, 1920, 1080);
	config->data.addr = mlx_get_data_addr(config->data.img,
						&config->data.bits_per_pixel,
						&config->data.line_length, &config->data.endian);
}