/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akasha <akasha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/10 12:38:58 by user              #+#    #+#             */
/*   Updated: 2021/01/10 18:41:33 by akasha           ###   ########.fr       */
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
    reset_to_zero(config->bmp.file_header, 40);
    
}