/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akasha <akasha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 14:17:06 by akasha            #+#    #+#             */
/*   Updated: 2021/01/08 20:56:29 by akasha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	close_win(int keycode, t_config *config)
{
	if (keycode == 53)
	{
		mlx_destroy_image(config->win.mlx, config->data.img);
		mlx_destroy_window(config->win.mlx, config->win.window);
		exit(0);
	}
	return (1);
}

void	destroy_tex_images(t_config *config)
{
	int i;

	i = 0;
	while (i < 5)
		mlx_destroy_image(config->win.mlx, config->img.img[i++]);
}

int	move_hero_hook(int keycode, t_config *config)
{
	if (button(keycode))
	{
		destroy_tex_images(config);
		mlx_destroy_image(config->win.mlx, config->data.img);
		if (keycode == 13)
			ft_move_forward(config);
		if (keycode == 0)
			ft_move_left(config);
		if (keycode == 1)
			ft_move_back(config);
		if (keycode == 2)
			ft_move_right(config);
		if (keycode == 123)
			ft_rotate_left(config);
		if (keycode == 124)
			ft_rotate_right(config);
		render(config);
	}
	return (1);
}

int	button(int key)
{
	if (key == 13 || key == 0 || key == 1 || key == 2)
		return (1);
	if (key == 123 || key == 124)
		return (1);
	return (0);
}
