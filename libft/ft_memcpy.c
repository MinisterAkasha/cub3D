#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	const char	*def_src;
	char		*def_dst;

	def_src = src;
	def_dst = dst;
	if (!dst && !src)
		return (dst);
	while (n)
	{
		*def_dst++ = *def_src++;
		n--;
	}
	return (dst);
}
