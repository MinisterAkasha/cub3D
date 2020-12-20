/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akasha <akasha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 17:14:04 by akasha            #+#    #+#             */
/*   Updated: 2020/12/20 18:00:54 by akasha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

#include "stdio.h" //!DEL


void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char    *dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}


void	render(t_config *config)
{
	int	x;

	init_image(config);
	load_img(config);
	x = 0;
	while (x < WIDTH)
	{
		config->hero.cameraX = 2 * (x / (double)WIDTH) - 1;
		config->ray.ray_dir_y = config->hero.dir_y + config->hero.plane_y * config->hero.cameraX;
		config->ray.ray_dir_x = config->hero.dir_x + config->hero.plane_x * config->hero.cameraX;
		cast_rays(config, x);
		x++;
	}
	mlx_put_image_to_window(config->win.mlx, config->win.window, config->data.img, 0, 0);
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
	close(fd);

	ft_find_width(map_line,config);

	ft_lstadd_back(&head, ft_lstnew(map_line));
	init_struct(config, head);

	run_window(config);

	//! Free LIST
	return (0);
}
