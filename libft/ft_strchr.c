#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char const	*str;
	int			i;

	str = s;
	i = 0;
	while (*str)
	{
		if (*str == c)
			return (char *)str;
		str++;
	}
	if (*str == c)
		return (char *)str;
	return (0);
}
