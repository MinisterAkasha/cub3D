/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 17:44:03 by akasha            #+#    #+#             */
/*   Updated: 2020/12/24 17:19:52 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	init_sprites(t_config *config)
{
	int y;
	int x;
	int i;
	
	config->sprite = (t_sprite *)malloc(sizeof(t_sprite) * config->map.sprites_num);

	i = 0;
	y = 0;
	while (config->map.map[y])
	{
		x = 0;
		while (config->map.map[y][x])
		{
			if (config->map.map[y][x] == '2')
			{
				config->sprite[i].y = y + 0.5;
				config->sprite[i].x = x + 0.5;
				i++;
			}
			x++;
		}
		y++;
	}
}

void	init_map_objects(t_config *config)
{
	int	x;
	int	y;

	y = 0;
	while (config->map.map[y])
	{
		x = 0;
		while (config->map.map[y][x])
		{
			if (config->map.map[y][x] == '2')
				config->map.sprites_num++;
			if (ft_strchr(config->map.hero_set, config->map.map[y][x])) // Определяю позицию героя
			{
				config->hero.y = y + 0.5;
				config->hero.x = x + 0.5;
				get_hero_dir(config, y, x);
			}
			x++;
		}
		y++;
	}
	init_sprites(config);
}

void	sprite_cast(t_config *config, double z_buffer[WIDTH])
{
	int 	i;
	double	*sprite_order;
	double	sprite_distanse[config->map.sprites_num];

	double	sprite_x;
	double	sprite_y;
	double	invert_determ;
	double	transform_x;
	double	transform_y;
	int		sprite_screen_x;
	int		sprite_height;
	int		sprite_width;

	int		drow_start_y;
	int		drow_end_y;
	int		drow_start_x;
	int		drow_end_x;

	i = 0;
	sprite_order = (double *)malloc(sizeof(double) * config->map.sprites_num);
	while (i < config->map.sprites_num)
	{
		sprite_order[i] = i;
		sprite_distanse[i] = (config->hero.x - config->sprite[i].x) * (config->hero.x - config->sprite[i].x) +
			(config->hero.y - config->sprite[i].y) * (config->hero.y - config->sprite[i].y);
		i++;
	}
	sprite_order = sort_sprites(config, sprite_order, sprite_distanse);
	i = 0;
	while (i < config->map.sprites_num){
		sprite_order[i] = i;
		printf("ORDER: %-5f DISTANSE: %-5f INDEX: %d\n", sprite_order[i], sprite_distanse[i], i);
		// printf("DISTANSE: %-5f, INDEX: %d\n", distanse[i], i);
		i++;
	}
	i = 0;
	while (i < config->map.sprites_num)
	{
		sprite_x = config->sprite[(int)sprite_order[i]].x - config->hero.x;
		sprite_y = config->sprite[(int)sprite_order[i]].y - config->hero.y;

		invert_determ = 1.0 / (config->hero.plane_x * config->hero.dir_y - config->hero.plane_y * config->hero.dir_x);

		transform_x = invert_determ * (config->hero.dir_y * sprite_x - config->hero.dir_x * sprite_y);
		transform_y = invert_determ * (config->hero.plane_x * sprite_y - config->hero.plane_y * sprite_x);

		sprite_screen_x = (int)((WIDTH / 2) * (1 + transform_x / transform_y));

		sprite_height = abs((int)(HEIGHT / transform_y));

		drow_start_y = -sprite_height / 2 + HEIGHT / 2;
		if (drow_start_y < 0)
			drow_start_y = 0;
		drow_end_y = sprite_height / 2 + HEIGHT / 2;
		if (drow_end_y >= HEIGHT)
			drow_end_y = HEIGHT - 1;

		sprite_width = abs((int)(HEIGHT / (transform_y)));

		drow_start_x = -sprite_width / 2 + sprite_screen_x;
		if (drow_start_x < 0)
			drow_start_x = 0;
		drow_end_x = sprite_width / 2 + sprite_screen_x;
		if (drow_end_x > WIDTH)
			drow_end_x = WIDTH - 1;
		int x = drow_start_x;
		while (x < drow_end_x)
		{
			int y = drow_start_y;
			int tex_x = (int)(256 * (x - (-sprite_width / 2 + sprite_screen_x)) * config->img.width[4] / sprite_width) / 256;
			if (transform_y > 0 && x > 0 && x < (int)WIDTH && transform_y < z_buffer[x])
			{
				while (y < drow_end_y)
				{
					int d = y * 256 - HEIGHT * 128 + sprite_height * 128;
					int tex_y = ((d * config->img.height[4]) / sprite_height) / 256;
					if ((config->img.texture[4][config->img.height[4] * tex_y + tex_x] & 0x00FFFFFF))
						my_mlx_pixel_put(&config->data, x, y, config->img.texture[4][config->img.width[4] * tex_y + tex_x]);
					y++;
				}
			}
			x++;
		}
		i++;
	}
	free(sprite_order);
}

void	swap(double *elem_1, double *elem_2)
{
	int swap;

	swap = *elem_1;
	*elem_1 = *elem_2;
	*elem_2 = swap;
}

int partition(double *arr, int low, int hight, double *order)
{
	int i;
	int j;
	int pivot;

	i = low - 1;
	j = low;
	pivot = arr[hight];
	while (j <= hight)
	{
		if (arr[j] < pivot)
		{
			i++;
			swap(&arr[i], &arr[j]);
			// swap((&order[j]), &order[i]);`
		}
		j++;
	}
	swap(&arr[i + 1], &arr[hight]);
	// swap((&order[hight]), &order[i + 1]);
	return (i + 1);
}

void quickSort(double arr[], int low, int high, double *order)
{  
	int pi;
    if (low < high)
    {
		pi = partition(arr, low, high, order);
        quickSort(arr, low, pi - 1, order);
        quickSort(arr, pi + 1, high, order);
    }
}

double	*sort_sprites(t_config *config, double *order, double *distanse)
{
	int i;
	// printf("BEFORE: %-10f", order[0]);
	quickSort(distanse, 0, config->map.sprites_num - 1, order);
	i = 0;
	// while (i < config->map.sprites_num){
	// 	order[i] = i;
	// 	printf("ORDER: %-5f DISTANSE: %-5f INDEX: %d\n", order[i], distanse[i], i);
	// 	// printf("DISTANSE: %-5f, INDEX: %d\n", distanse[i], i);
	// 	i++;
	// }
	// printf("AFTER: %f\n", order[0]);
	
	
	return (order);
}

void	get_hero_dir(t_config *config, int y, int x)
{
	if (config->map.map[y][x] == 'N')
	{
		config->hero.dir_x = 0;
		config->hero.dir_y = -1;
		config->hero.plane_x = -0.66;
		config->hero.plane_y = 0;
	}
	if (config->map.map[y][x] == 'W')
	{
		config->hero.dir_x = 1;
		config->hero.dir_y = 0;
		config->hero.plane_x = 0;
		config->hero.plane_y = -0.66;
	}
	if (config->map.map[y][x] == 'S')
	{
		config->hero.dir_x = 0;
		config->hero.dir_y = 1;
		config->hero.plane_x = 0.66;
		config->hero.plane_y = 0;
	}
	if (config->map.map[y][x] == 'E')
	{
		config->hero.dir_x = -1;
		config->hero.dir_y = 0;
		config->hero.plane_x = 0;
		config->hero.plane_y = 0.66;
	}
}
