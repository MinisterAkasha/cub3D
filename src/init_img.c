/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akasha <akasha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/20 18:50:05 by akasha            #+#    #+#             */
/*   Updated: 2021/01/07 15:17:20 by akasha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	init_image(t_config *config)
{
	config->data.img = mlx_new_image(config->win.mlx,
						config->params.window_width,
						config->params.window_height);
	config->data.addr = mlx_get_data_addr(config->data.img,
						&config->data.bits_per_pixel,
						&config->data.line_length, &config->data.endian);
}
