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
