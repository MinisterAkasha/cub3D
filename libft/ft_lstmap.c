#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*elem;

	if (!lst || !f)
		return (NULL);
	if (!(elem = ft_lstnew(f(lst->content))))
		return (NULL);
	new = elem;
	lst = lst->next;
	while (lst)
	{
		if (!(elem = ft_lstnew(f(lst->content))))
		{
			ft_lstclear(&new, del);
			return (NULL);
		}
		lst = lst->next;
		ft_lstadd_back(&new, elem);
	}
	return (new);
}
