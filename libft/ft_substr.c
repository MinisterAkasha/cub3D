/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akasha <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 18:39:38 by akasha            #+#    #+#             */
/*   Updated: 2020/11/06 14:10:44 by akasha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
