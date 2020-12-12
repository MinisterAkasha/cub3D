/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akasha <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 11:18:12 by akasha            #+#    #+#             */
/*   Updated: 2020/10/30 11:18:13 by akasha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	const char	*def_src;
	char		*def_dst;

	def_src = src;
	def_dst = dst;
	if (!dst && !src)
		return (dst);
	while (n)
	{
		*def_dst++ = *def_src++;
		n--;
	}
	return (dst);
}
