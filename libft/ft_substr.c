#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;
	size_t	j;

	if (!s && !start)
		return (0);
	if (start > ft_strlen(s))
	{
		str = ft_strdup("");
		return (str);
	}
	i = 0;
	j = len < ft_strlen(&s[start]) ? len : ft_strlen(&s[start]);
	if (!(str = (char *)malloc(sizeof(char) * j + 1)))
		return (0);
	while (i < len && s[start])
		str[i++] = s[start++];
	str[i] = '\0';
	return (str);
}
