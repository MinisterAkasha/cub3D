/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akasha <akasha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 23:25:59 by user              #+#    #+#             */
/*   Updated: 2020/12/19 18:00:44 by akasha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void    load_img(t_config *config)
{
    config->img.img[0] = mlx_xpm_file_to_image(config->win.mlx, "pics/brick.xpm", &config->img.width[0], &config->img.height[0]);
    config->img.addr[0] = mlx_get_data_addr(config->img.img[0],
						&config->img.bits_per_pixel[0],
						&config->img.line_length[0], &config->img.endian[0]);
    

    config->img.img[1] = mlx_xpm_file_to_image(config->win.mlx, "pics/banner.xpm", &config->img.width[1], &config->img.height[1]);
    config->img.addr[1] = mlx_get_data_addr(config->img.img[1],
						&config->img.bits_per_pixel[1],
						&config->img.line_length[1], &config->img.endian[1]);
}