/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akasha <akasha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 18:19:18 by akasha            #+#    #+#             */
/*   Updated: 2021/01/16 20:15:01 by akasha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	check_arguments(int argc, char *argv[], t_config *config)
{
	if (argc == 3 && ft_strlen(argv[2])
						&& ft_strncmp(argv[2], "--save", 7) == 0)
		config->params.screenshot = 1;
	else if (argc > 2)
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
