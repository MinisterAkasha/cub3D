/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akasha <akasha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 14:17:06 by akasha            #+#    #+#             */
/*   Updated: 2021/01/07 14:17:18 by akasha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int		close_win(int keycode, t_config *config)
{
	if (keycode == 53)
	{
		mlx_destroy_image(config->win.mlx, config->data.img);
		mlx_destroy_window(config->win.mlx, config->win.window);
		// free(config->sprite);
		exit(0);
	}
	return (1);
}