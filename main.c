/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akasha <akasha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 17:14:04 by akasha            #+#    #+#             */
/*   Updated: 2021/01/10 17:46:58 by akasha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

#include "stdio.h" //!DEL

//TODO проверить напровление игрока и стороны текстур

void	fill_z_buffer(t_config *config, int x)
{
	config->sprite.z_buffer[x] = config->ray.perp_wall_dist;
}

int		render(t_config *config)
{
	int	x;

	init_image(config);
	if (!(config->sprite.z_buffer = (double *)malloc(sizeof(double) * config->params.window_width)))
		exit_cub(15, config);
	x = 0;
	while (x < config->params.window_width)
	{
		cast_rays(config, x);
		fill_z_buffer(config, x);
		x++;
	}
	sprite_cast(config);
	
	free(config->sprite.z_buffer);
	mlx_put_image_to_window(config->win.mlx, config->win.window, config->data.img, 0, 0);
	return (1);
}

void	check_arguments_number(int argc, t_config *config)
{
	if (argc > 2)
		exit_cub(0, config);
	else if (argc < 2)
		exit_cub(1, config);
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
	free_all(config);
	return (0);
}
