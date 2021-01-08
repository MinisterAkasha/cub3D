/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akasha <akasha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 17:14:04 by akasha            #+#    #+#             */
/*   Updated: 2021/01/08 20:34:44 by akasha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

#include "stdio.h" //!DEL

int		render(t_config *config)
{
	int		x;
	// double	z_buffer[(int)config->params.window_width];

	init_image(config);
	load_img(config);
	if (!(config->sprite.z_buffer = (double *)malloc(sizeof(double) * config->params.window_width)))
		exit_cub(15, config);
	x = 0;
	while (x < config->params.window_width)
	{
		ft_get_camera_coordinate(config, x);
		cast_rays(config, x);
		config->sprite.z_buffer[x] = config->ray.perp_wall_dist;
		x++;
	}
	sprite_cast(config);
	free_texture_arr(config);
	free(config->sprite.z_buffer);
	mlx_put_image_to_window(config->win.mlx, config->win.window, config->data.img, 0, 0);
	return (1);
}

void	ft_get_camera_coordinate(t_config *config, int x)
{
	config->hero.camera_x = 2 * (x / (double)config->params.window_width) - 1;
	config->ray.ray_dir_y = config->hero.dir_y + config->hero.plane_y * config->hero.camera_x;
	config->ray.ray_dir_x = config->hero.dir_x + config->hero.plane_x * config->hero.camera_x;
}

void	check_arguments_number(int argc, t_config *config)
{
	if (argc > 2)
		exit_cub(0, config);
	else if (argc < 2)
		exit_cub(1, config);
}

void	fill_param_list(t_config *config, int fd)
{
	char	*param_line;
	int		i;

	i = skip_spaces(param_line);
	while (param_line[i] != '1')
	{
		i = skip_spaces(param_line);
		get_next_line(fd, &param_line);
		if (param_line[i] == '1')
		{
			ft_lstadd_back(&config->head_map, ft_lstnew(param_line));
			return ;
		}
		ft_lstadd_back(&config->head_param, ft_lstnew(param_line));
	}
}

void	fill_map_list(t_config *config, int fd)
{
	t_list	*tmp;
	char	*map_line;

	config->map.width = 0;
	config->map.new_line = 0;
	ft_find_width(config->head_map->content, config);
	while (get_next_line(fd, &map_line))
	{
		ft_find_width(map_line, config);
		if (!*map_line)
			config->map.new_line++;
		ft_lstadd_back(&config->head_map, ft_lstnew(map_line));
	}
	ft_find_width(map_line, config);
	ft_lstadd_back(&config->head_map, ft_lstnew(map_line));
}

void	check_file_name(char *file_name, t_config *config)
{
	while (*file_name)
		file_name++;
	file_name--;
	if (*file_name == 'b' && *(file_name - 1) == 'u'
	&& *(file_name - 2) == 'c' && *(file_name - 3) == '.')
		return ;
	exit_cub(11, config);
}

int main(int argc, char *argv[])
{
	int			fd;
	char		*map_line;
	t_config	*config;
	int			i;

	if (!(config = (t_config *)malloc(sizeof(t_config))))
		exit_cub(15, config);
	init_error(config);
	check_arguments_number(argc, config);
	if ((fd = open(argv[1], O_RDONLY)) == -1)
		exit_cub(15, config);
	check_file_name(argv[1], config);
	fill_param_list(config, fd);
	fill_map_list(config, fd);
	close(fd);
	init_struct(config);
	run_window(config);
	exit_free(config);
	while(1) {}
	return (0);
}
