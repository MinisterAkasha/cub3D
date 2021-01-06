/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_cub.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akasha <akasha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 13:18:54 by akasha            #+#    #+#             */
/*   Updated: 2021/01/06 18:40:40 by akasha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	exit_cub(int error_code, t_config *config)
{
	int error_message_len;

	if (error_code < 12)
	{
		error_message_len = ft_strlen(config->error.error_arr[error_code]);
		write(1, config->error.error_arr[error_code], error_message_len);
	}
	else
	{
		perror("");
	}
	exit(0);
}