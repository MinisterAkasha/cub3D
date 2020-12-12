/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akasha <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 19:03:32 by akasha            #+#    #+#             */
/*   Updated: 2020/11/04 13:49:47 by akasha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	int		j;

	i = 0;
	if (!ft_strlen(needle))
		return (char *)haystack;
	while (haystack[i] && i < len)
	{
		j = 0;
		while (haystack[i] == needle[j] && i < len)
		{
			i++;
			j++;
			if (needle[j] == '\0')
				return (char *)&haystack[i - j];
			if (haystack[i] != needle[j])
			{
				i -= j;
				break ;
			}
		}
		i++;
	}
	return (char *)0;
}
