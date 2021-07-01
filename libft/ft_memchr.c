#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*def_s;

	def_s = (unsigned char *)s;
	while (n--)
	{
		if (*def_s++ == (unsigned char)c)
			return ((void *)--def_s);
	}
	return (void *)0;
}
