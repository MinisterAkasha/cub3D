#include "cub.h"

int				get_spases_num(char *str)
{
	int spaces_len;

	spaces_len = 0;
	while (*str)
	{
		if (*str == ' ')
			spaces_len++;
		str++;
	}
	return (spaces_len);
}

int				get_numbers_num(char *str)
{
	int numbers;
	int	i;
	int len;

	numbers = 0;
	len = ft_strlen(str);
	i = 0;
	while (str[i])
	{
		if (ft_isdigit(str[i]))
		{
			numbers++;
			while (str[i] && ft_isdigit(str[i]))
				i++;
		}
		if (str[i] == 0)
			break ;
		i++;
	}
	return (numbers);
}

void			check_color_value(int color, t_config *config)
{
	if (color > 255 || color < 0)
		exit_cub(8, config);
}

int				get_commas_num(char *str)
{
	int commas;

	commas = 0;
	while (*str)
	{
		if (*str == ',')
			commas++;
		str++;
	}
	return (commas);
}

void			fast_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length +
						x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}
