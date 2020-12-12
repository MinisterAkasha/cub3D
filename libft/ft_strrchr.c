/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akasha <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 17:48:37 by akasha            #+#    #+#             */
/*   Updated: 2020/10/29 17:48:39 by akasha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char const	*str;
	int			i;

	str = s;
	i = ft_strlen(str);
	while (ft_strlen(str))
	{
		str++;
	}
	if (*str == c)
		return (char *)str;
	while (i >= 0)
	{
		if (*str == c)
			return (char *)str;
		str--;
		i--;
	}
	return (0);
}
