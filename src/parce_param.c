/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parce_param.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akasha <akasha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/03 15:15:21 by akasha            #+#    #+#             */
/*   Updated: 2021/01/30 21:09:34 by akasha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	find_correct_param_and_parce(char *str, t_config *config)
{
	if (*str == 'R')
		parce_window_param(config, ++str);
	else if ((*str == 'N' && *(str + 1) == 'O')
			|| (*str == 'S')
			|| (*str == 'W' && *(str + 1) == 'E')
			|| (*str == 'E' && *(str + 1) == 'A'))
		parce_tex(config, str);
	else if (*str == 'F' || *str == 'C')
		parce_color(config, str);
}

void	check_all_params(t_config *config)
{
	int i;

	i = 0;
	while (i < 9)
	{
		if ((config->params.has_param[i]) == 0)
			exit_cub(9, config);
		if ((config->params.has_param[i]) > 1)
			exit_cub(13, config);
		i++;
	}
}

void	parce_param(t_config *config)
{
	t_list	*tmp;
	char	*str;

	tmp = config->head_param;
	while (tmp)
	{
		str = tmp->content;
		str += skip_spaces(str);
		find_correct_param_and_parce(str, config);
		tmp = tmp->next;
	}
	check_all_params(config);
}
