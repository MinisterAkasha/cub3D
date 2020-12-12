/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akasha <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 15:11:36 by akasha            #+#    #+#             */
/*   Updated: 2020/10/30 15:11:37 by akasha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*def_s1;
	unsigned char	*def_s2;
	int				i;

	def_s1 = (unsigned char *)s1;
	def_s2 = (unsigned char *)s2;
	i = 0;
	while (n--)
	{
		if (def_s1[i] != def_s2[i])
			return (def_s1[i] - def_s2[i]);
		i++;
	}
	return (0);
}
