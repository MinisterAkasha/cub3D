/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akasha <akasha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 23:25:59 by user              #+#    #+#             */
/*   Updated: 2020/12/19 17:03:21 by akasha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void    load_img(t_config *config)
{
    config->img.img = mlx_xpm_file_to_image(config->win.mlx, "pics/brick.xpm", &config->img.width, &config->img.height);
    config->img.addr = mlx_get_data_addr(config->img.img,
						&config->img.bits_per_pixel,
						&config->img.line_length, &config->img.endian);
    
}