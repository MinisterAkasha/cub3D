/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akasha <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 11:08:59 by akasha            #+#    #+#             */
/*   Updated: 2020/10/29 11:09:00 by akasha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	int		i;
	size_t	len;

	if (!dst && !src)
		return (0);
	i = 0;
	len = ft_strlen(src);
	if (dstsize == 0)
		return (len);
	while (dstsize != 1 && src[i])
	{
		dst[i] = src[i];
		i++;
		dstsize--;
	}
	dst[i] = 0;
	return (len);
}
