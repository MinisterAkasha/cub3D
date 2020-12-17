/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 23:25:59 by user              #+#    #+#             */
/*   Updated: 2020/12/17 23:40:02 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void    load_img(t_config *config)
{
    config->img.width = 64;
    config->img.height = 64;
    mlx_xpm_file_to_image(config->win.mlx, "../pics/brick.xpm", &config->img.width, &config->img.height);
    
}