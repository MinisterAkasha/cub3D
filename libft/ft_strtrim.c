#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	end;

	if (!s1 || !set)
		return (0);
	if (!*s1 || !*set)
		return (ft_strdup(s1));
	while (ft_strchr(set, *s1) && *s1)
		s1++;
	if (!*s1)
		return (ft_strdup(s1));
	end = ft_strlen(s1) - 1;
	while (ft_strrchr(set, s1[end]) && end)
		end--;
	return (ft_substr(s1, 0, end + 1));
}
