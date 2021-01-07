/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akasha <akasha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 17:14:04 by akasha            #+#    #+#             */
/*   Updated: 2021/01/07 15:44:50 by akasha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

#include "stdio.h" //!DEL

void	render(t_config *config)
{
	int		x;
	double	z_buffer[(int)config->params.window_width];

	init_image(config);
	load_img(config);
	x = 0;
	while (x < config->params.window_width)
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
	config->hero.cameraX = 2 * (x / (double)config->params.window_width) - 1;
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
		ft_lstadd_back(&config->head_param, ft_lstnew(param_line));
	}
}

void	fill_map_list(t_config *config, int fd)
{
	t_list	*tmp;
	char *map_line;

	tmp = config->head_param;
	while (tmp->next)
		tmp = tmp->next;
	config->map.width = 0;
	config->map.new_line = 0;
	ft_find_width(tmp->content, config);
	ft_lstadd_back(&config->head_map, ft_lstnew(tmp->content));
	while(get_next_line(fd, &map_line))
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
	free(config->sprite);
	free(config);
	//! Free LISTS
	//! Free TEXTURES
	return (0);
}
