/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akasha <akasha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 21:24:10 by akasha            #+#    #+#             */
/*   Updated: 2020/11/24 16:32:06 by akasha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long	ft_numlen(int num)
{
	int		ln;

	ln = 0;
	if (num <= 0)
		ln = 1;
	while (num)
	{
		num /= 10;
		ln++;
	}
	return (ln);
}

static int	ft_sign(int num)
{
	int		sign;

	sign = 1;
	if (num < 0)
		sign = -1;
	return (sign);
}

char		*ft_itoa(int n)
{
	int		ln;
	char	*str;
	int		sign;

	ln = ft_numlen(n);
	sign = ft_sign(n);
	if (!(str = (char *)malloc(sizeof(char) * ln + 1)))
		return (0);
	str += ln;
	*str-- = '\0';
	if (!n)
		*str = '0';
	while (n)
	{
		*str = sign * (n % 10) + 48;
		if (n < -9 || n > 9)
			str--;
		n /= 10;
	}
	if (sign == -1)
		*--str = '-';
	return (str);
}
