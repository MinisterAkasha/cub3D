#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	const char	*def_src;
	char		*def_dst;

	def_src = src;
	def_dst = dst;
	if (!dst && !src)
		return (0);
	if (dst > src)
	{
		def_src = src + len - 1;
		def_dst = dst + len - 1;
		while (len)
		{
			*def_dst-- = *def_src--;
			len--;
		}
	}
	while (len)
	{
		*def_dst++ = *def_src++;
		len--;
	}
	return (dst);
}
