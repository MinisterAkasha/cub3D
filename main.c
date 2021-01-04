/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akasha <akasha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 17:14:04 by akasha            #+#    #+#             */
/*   Updated: 2021/01/04 18:34:46 by akasha           ###   ########.fr       */
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
	int		x;
	double	z_buffer[(int)config->settings.window_width];

	init_image(config);
	load_img(config);
	x = 0;
	while (x < config->settings.window_width)
	{
		ft_get_camera_coordinate(config, x);
		cast_rays(config, x);
		z_buffer[x] = config->ray.perp_wall_dist;
		x++;
	}
	sprite_cast(config, z_buffer);
	free_texture(config);
	mlx_put_image_to_window(config->win.mlx, config->win.window, config->data.img, 0, 0);
}
void	ft_get_camera_coordinate(t_config *config, int x)
{
	config->hero.cameraX = 2 * (x / (double)config->settings.window_width) - 1;
	config->ray.ray_dir_y = config->hero.dir_y + config->hero.plane_y * config->hero.cameraX;
	config->ray.ray_dir_x = config->hero.dir_x + config->hero.plane_x * config->hero.cameraX;
}
void	free_texture(t_config *config)
{
	int i;

	i = 0;
	while (i < 5)
	{
		free(config->img.texture[i]);
		i++;
	}
}
int main(int argc, char *argv[])
{
	int			fd;
	char		*map_line;
	t_config	*config;
	int			i;


	if (argc != 2)
	{
		write(1, "Passed too many arguments\n", 27);
		return (-1);//TODO return error message
	}

	map_line = NULL;

	fd = open(argv[1], O_RDONLY);

	if (!(config = (t_config *)malloc(sizeof(t_config))))
		return (-1);//TODO return error message

	// config->head_map = NULL;
	config->map.width = 0;
	config->map.new_line = 0;
	while(get_next_line(fd, &map_line))
	{
		i = skip_spaces(map_line);
		if (map_line[i] == '1')
		{
			ft_find_width(map_line,config);
			if (!*map_line)
				config->map.new_line++;
			ft_lstadd_back(&config->head_map, ft_lstnew(map_line));
		}
		else
			ft_lstadd_back(&config->head_param, ft_lstnew(map_line));
	}
	ft_find_width(map_line,config);
	ft_lstadd_back(&config->head_map, ft_lstnew(map_line));
	
	close(fd);

	init_struct(config);

	run_window(config);
	
	free(config->sprite);
	free(config);
	//! Free LIST
	return (0);
}
