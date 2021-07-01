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
