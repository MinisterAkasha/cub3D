/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akasha <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 12:12:01 by akasha            #+#    #+#             */
/*   Updated: 2020/11/03 12:12:03 by akasha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*cur;

	cur = *lst;
	if (!lst || !new)
		return ;
	if (!*lst)
		*lst = new;
	else if (lst && *lst && new)
	{
		while (cur->next)
			cur = cur->next;
		cur->next = new;
	}
}
