/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akasha <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 14:13:19 by akasha            #+#    #+#             */
/*   Updated: 2020/10/31 14:13:21 by akasha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_wordcount(char const *s, char c)
{
	int count;
	int	i;
	int	flag;

	count = 0;
	i = 0;
	flag = 1;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] != c || s[i + 1] != 0) && flag)
		{
			flag = 0;
			count++;
		}
		if (s[i] == c)
			flag = 1;
		i++;
	}
	return (count);
}

static int		ft_ltr(char const *s, char c)
{
	int	count;

	count = 0;
	while (*s != c && *s++)
		count++;
	return (count);
}

static char		*ft_write_word(char const **str, char c, char **arr, int j)
{
	char	*word;
	int		i;

	i = 0;
	word = (char *)malloc(sizeof(char) * (ft_ltr(*str, c) + 1));
	if (!word)
	{
		while (j >= 0)
			free(arr[j--]);
		free(arr);
		return (0);
	}
	while (**str != c && **str)
	{
		word[i] = **str;
		i++;
		*str += 1;
	}
	word[i] = 0;
	return (word);
}

char			**ft_split(char const *s, char c)
{
	int		j;
	int		words;
	char	**arr;

	if (!s)
		return (0);
	words = ft_wordcount(s, c);
	if (!(arr = (char **)malloc(sizeof(char *) * (words + 1))))
		return (0);
	j = 0;
	while (j < words)
	{
		while (*s == c && *s)
			s++;
		if (*s != c && *s)
		{
			arr[j] = ft_write_word(&s, c, arr, j);
			if (!arr)
				return (0);
			j++;
		}
	}
	arr[j] = 0;
	return (arr);
}
