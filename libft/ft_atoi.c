#include "libft.h"

int			ft_atoi(const char *str)
{
	int				i;
	int				sign;
	long int		sum;

	i = 0;
	sign = 1;
	sum = 0;
	while (str[i] == 0 || str[i] == ' ' || str[i] == '\n' || str[i] == '\t'
	|| str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
	{
		if (str[i] == '\0')
			return (0);
		i++;
	}
	if (str[i] == '-' || str[i] == '+')
		str[i++] == '-' ? sign = -1 : sign;
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (sum * 10 < sum && sign == 1)
			return (-1);
		if (sum * 10 < sum && sign == -1)
			return (0);
		sum = sum * 10 + (str[i++] - 48);
	}
	return (int)(sum * sign);
}
