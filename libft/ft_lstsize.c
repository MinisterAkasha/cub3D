/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akasha <akasha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 11:39:45 by akasha            #+#    #+#             */
/*   Updated: 2020/12/06 19:24:39 by akasha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		count;
	t_list	*cur;

	count = 0;
	cur = lst;
	if (!cur)
		return (count);
	while (cur)
	{
		cur = cur->next;
		count++;
	}
	return (count);
}
