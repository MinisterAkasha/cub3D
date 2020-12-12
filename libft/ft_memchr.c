/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akasha <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 14:36:06 by akasha            #+#    #+#             */
/*   Updated: 2020/10/30 14:36:07 by akasha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*def_s;

	def_s = (unsigned char *)s;
	while (n--)
	{
		if (*def_s++ == (unsigned char)c)
			return ((void *)--def_s);
	}
	return (void *)0;
}
