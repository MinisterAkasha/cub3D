/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akasha <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 15:12:20 by akasha            #+#    #+#             */
/*   Updated: 2020/10/29 15:12:21 by akasha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
