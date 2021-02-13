/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_cub.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 13:18:54 by akasha            #+#    #+#             */
/*   Updated: 2021/02/13 19:40:47 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	exit_cub(int error_code, t_config *config)
{
	int error_message_len;

	if (error_code < 15)
	{
		error_message_len = ft_strlen(config->error.error[error_code]);
		write(1, config->error.error[error_code], error_message_len);
		free_all(config);
	}
	else
		perror("Error");
	exit(0);
}
