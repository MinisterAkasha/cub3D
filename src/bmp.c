/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akasha <akasha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/10 12:38:58 by user              #+#    #+#             */
/*   Updated: 2021/01/10 19:17:59 by akasha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void    reset_to_zero(unsigned char header[], int size)
{
    int i;

    i = 0;
    while (i < size)
        header[i++] = 0;
}

void    create_bmp_file_header(t_config *config)
{
    int file_size;

    reset_to_zero(config->bmp.file_header, 14);
    file_size = config->params.window_width * config->params.window_height * 3 + 54;
    config->bmp.file_header[0] = (unsigned char)('B');
    config->bmp.file_header[1] = (unsigned char)('M');

    config->bmp.file_header[2] = (unsigned char)(file_size);
    config->bmp.file_header[3] = (unsigned char)(file_size >> 8);
    config->bmp.file_header[4] = (unsigned char)(file_size >> 16);
    config->bmp.file_header[4] = (unsigned char)(file_size >> 24);

    config->bmp.file_header[10] = (unsigned char)(54);
}

void    create_bmp_info_header(t_config *config)
{
    int width;
    int height;

    width = config->params.window_width;
    height = config->params.window_height;
    reset_to_zero(config->bmp.file_header, 40);
    config->bmp.info_header[0] = (unsigned char)(40);

    config->bmp.info_header[4] = (unsigned char)(width);
    config->bmp.info_header[5] = (unsigned char)(width >> 8);
    config->bmp.info_header[6] = (unsigned char)(width >> 16);
    config->bmp.info_header[7] = (unsigned char)(width >> 24);

    config->bmp.info_header[8] = (unsigned char)(height);
    config->bmp.info_header[9] = (unsigned char)(height >> 8);
    config->bmp.info_header[10] = (unsigned char)(height >> 16);
    config->bmp.info_header[11] = (unsigned char)(height >> 24);

    config->bmp.info_header[12] = (unsigned char)(1);
    
    config->bmp.info_header[14] = (unsigned char)(3 * 8);
}