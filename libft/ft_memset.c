#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	char		*p;
	const char	*v;

	p = b;
	v = b;
	while (len)
	{
		*p = c;
		p++;
		len--;
	}
	return (b);
}
