/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_cub.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akasha <akasha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 13:18:54 by akasha            #+#    #+#             */
/*   Updated: 2021/01/30 20:42:12 by akasha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	exit_cub(int error_code, t_config *config)
{
	int error_message_len;

	if (error_code < 14)
	{
		error_message_len = ft_strlen(config->error.error[error_code]);
		write(1, config->error.error[error_code], error_message_len);
		free_all(config);
	}
	else
		perror("Error");
	exit(0);
}
