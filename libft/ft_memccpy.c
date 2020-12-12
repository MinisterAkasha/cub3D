/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akasha <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 11:41:29 by akasha            #+#    #+#             */
/*   Updated: 2020/11/01 11:41:32 by akasha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	char			*def_dst;
	const char		*def_src;
	int				i;
	int				flag;

	def_dst = dst;
	def_src = src;
	i = 0;
	flag = 0;
	if (!dst && !src)
		return (0);
	while (n--)
	{
		if ((unsigned char)c == (unsigned char)*def_src)
		{
			flag = 1;
			*def_dst++ = *def_src;
			break ;
		}
		*def_dst++ = *def_src++;
		i++;
	}
	if (!flag)
		return (0);
	return (def_dst);
}
