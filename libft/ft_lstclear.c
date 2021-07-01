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
