/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akasha <akasha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 18:48:04 by akasha            #+#    #+#             */
/*   Updated: 2021/01/08 19:11:38 by akasha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	swap_elems(double *elem_1, double *elem_2)
{
	int swap;

	swap = *elem_1;
	*elem_1 = *elem_2;
	*elem_2 = swap;
}

int		partition(t_config *config ,int left, int right)
{
	int i;
	int j;
	double pivot;

	i = left;
	j = left;
	pivot = config->sprite.sprite_distanse[right];
	while (j <= right)
	{
		if (config->sprite.sprite_distanse[j] > pivot)
		{
			swap_elems(&config->sprite.sprite_distanse[i], &config->sprite.sprite_distanse[j]);
			swap_elems((&config->sprite.sprite_order[i]), &config->sprite.sprite_order[j]);
			i++;
		}
		j++;
	}
	swap_elems(&config->sprite.sprite_distanse[i], &config->sprite.sprite_distanse[right]);
	swap_elems((&config->sprite.sprite_order[i]), &config->sprite.sprite_order[right]);
	return (i);
}

void 	sort_sprites(t_config *config, int left, int right)
{  
	int pivot;

    if (left < right)
    {
		pivot = partition(config, left, right);
        sort_sprites(config, left, pivot - 1);
        sort_sprites(config, pivot + 1, right);
    }
}