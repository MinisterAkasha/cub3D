/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akasha <akasha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/20 18:50:05 by akasha            #+#    #+#             */
/*   Updated: 2021/01/03 16:32:41 by akasha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	init_image(t_config *config)
{
	config->data.img = mlx_new_image(config->win.mlx, WIDTH, HEIGHT);
	config->data.addr = mlx_get_data_addr(config->data.img,
						&config->data.bits_per_pixel,
						&config->data.line_length, &config->data.endian);
}