#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void *memory;

	memory = malloc(count * size);
	if (!memory)
		return (0);
	ft_memset(memory, 0, count * size);
	return (memory);
}
