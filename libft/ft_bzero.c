#include "libft.h"

void	*ft_bzero(void *b, size_t n)
{
	unsigned char	*p;
	const char		*v;

	p = b;
	v = b;
	while (n)
	{
		*p = (unsigned char)'\0';
		p++;
		n--;
	}
	return (b);
}
