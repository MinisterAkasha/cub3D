/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akasha <akasha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 18:48:04 by akasha            #+#    #+#             */
/*   Updated: 2021/01/07 19:01:18 by akasha           ###   ########.fr       */
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

int		partition(double *distanse, int left, int right, double *order)
{
	int i;
	int j;
	double pivot;

	i = left;
	j = left;
	pivot = distanse[right];
	while (j <= right)
	{
		if (distanse[j] > pivot)
		{
			swap_elems(&distanse[i], &distanse[j]);
			swap_elems((&order[i]), &order[j]);
			i++;
		}
		j++;
	}
	swap_elems(&distanse[i], &distanse[right]);
	swap_elems((&order[i]), &order[right]);
	return (i);
}

void 	sort_sprites(double distanse[], int left, int right, double order[])
{  
	int pivot;

    if (left < right)
    {
		pivot = partition(distanse, left, right, order);
        sort_sprites(distanse, left, pivot - 1, order);
        sort_sprites(distanse, pivot + 1, right, order);
    }
}