/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akasha <akasha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 17:14:04 by akasha            #+#    #+#             */
/*   Updated: 2020/12/19 17:03:43 by akasha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

#include "stdio.h" //!DEL


void            my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
    char    *dst;

    dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
    *(unsigned int*)dst = color;
}

void	put_pixel_scale(int x, int y, t_config *config)
{
	int y_start;
	int x_start;
	int y_orig;
	int x_orig;

	y_start = y;
	x_start = x;
	y_orig = (y / config->map.scale);
	x_orig = (x / config->map.scale);
	while (y < y_start + config->map.scale)
	{
		x = x_start;
		while (x < x_start + config->map.scale)
		{
			if (config->map.map[y_orig][x_orig] == '1')
				my_mlx_pixel_put(&config->data, x, y, 0xFFFFFF);
			if (config->map.map[y_orig][x_orig] == '2')
				my_mlx_pixel_put(&config->data, x, y, 0xD2EB34);
			if (ft_strchr(config->map.hero_set, config->map.map[y_orig][x_orig]))
				my_mlx_pixel_put(&config->data, ((config->hero.x) * config->map.scale) + x - x_start,
					((config->hero.y) * config->map.scale) + y - y_start , 0xEB3434);
			x++;
		}
		y++;
	}
}

void	write_2d_map(t_config *config)
{
	int	x;
	int y;

	int			texture[2][TEX_HEIGHT * TEX_WIDTH];

	init_img(config);
	load_img(config);
	x = 0;
	while (x < TEX_WIDTH)
	{
		y = 0;
		while (y < TEX_HEIGHT)
		{
			int xycolor = y * 128 / HEIGHT + x * 128 / WIDTH;
			// texture[0][TEX_WIDTH * y + x] = 65536 * ycolor;
			texture[0][TEX_WIDTH * y + x] = 65536 * 192 * (x % 16 && y % 16);
			texture[0][TEX_WIDTH * y + x] = 65536 * 254 * (x != y && x != TEX_WIDTH - y);
			texture[1][TEX_WIDTH * y + x] = xycolor + 256 * xycolor + 65536 * xycolor; //sloped greyscale
			// texture[2][WIDTH * y + x] = 256 * xycolor + 65536 * xycolor; //sloped yellow gradient
			// texture[2][WIDTH * y + x] = 65536 * ycolor;
			y++;
		}
		load_img(config);
		x++;
	}
	x = 0;
	while (x < WIDTH)
	{
		config->hero.cameraX = 2 * (x / (double)WIDTH) - 1;
		config->ray.ray_dir_y = config->hero.dir_y + config->hero.plane_y * config->hero.cameraX;
		config->ray.ray_dir_x = config->hero.dir_x + config->hero.plane_x * config->hero.cameraX;
		cast_rays(config, x, texture);
		x++;
	}
	mlx_put_image_to_window(config->win.mlx, config->win.window, config->data.img, 0, 0);
	mlx_put_image_to_window(config->win.mlx, config->win.window, config->img.img, 0, 0);
}

int main(int argc, char *argv[])
{
	int			fd;
	char		*map_line;
	t_list		*head;
	t_config	*config;


	if (argc == 1)
		return (-1);//TODO return error message

	map_line = NULL;
	head = NULL;

	fd = open(argv[1], O_RDONLY);

	if (!(config = (t_config *)malloc(sizeof(t_config))))
		return (-1);//TODO return error message


	config->map.width = 0;
	config->map.nl = 0;
	while(get_next_line(fd, &map_line))
	{
		ft_find_width(map_line,config);
		if (!*map_line)
			config->map.nl++;
		ft_lstadd_back(&head, ft_lstnew(map_line));
	}

	ft_find_width(map_line,config);

	ft_lstadd_back(&head, ft_lstnew(map_line));
	init_struct(config, head);

	run_window(config);

	close(fd);
	//! Free LIST
	return (0);
}
