/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akasha <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 13:53:07 by akasha            #+#    #+#             */
/*   Updated: 2020/11/03 13:53:08 by akasha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*cur;

	if (!lst || !del)
		return ;
	while (*lst)
	{
		cur = *lst;
		*lst = (*lst)->next;
		del(cur->content);
		free(cur);
	}
}
