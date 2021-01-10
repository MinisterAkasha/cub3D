/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akasha <akasha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 14:17:06 by akasha            #+#    #+#             */
/*   Updated: 2021/01/09 17:53:43 by akasha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	close_win(t_config *config)
{
	mlx_destroy_window(config->win.mlx, config->win.window);
	free_all(config);
	exit(0);
	return (1);
}

void	destroy_images(t_config *config)
{
	int i;

	i = 0;
	while (i < 5)
		mlx_destroy_image(config->win.mlx, config->img.img[i++]);
	mlx_destroy_image(config->win.mlx, config->data.img);
}

int	hooks(int keycode, t_config *config)
{
	if (button(keycode))
	{
		mlx_destroy_image(config->win.mlx, config->data.img);
		if (keycode == 53)
			close_win(config);
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
	if (key == 53)
		return (1);
	return (0);
}
