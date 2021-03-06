#include "cub.h"

void	find_color_value(char **str, int *color)
{
	skip_not_number(str);
	if (ft_isdigit(**str) || **str == '-')
		*color = ft_atoi(*str);
	skip_number(str);
}

char	*make_minimized_str(char *mini_str, char *str)
{
	int i;
	int j;
	int	minimized_str_len;

	i = 0;
	j = 0;
	minimized_str_len = ft_strlen(str + 1) - get_spases_num(str + 1);
	if (!(mini_str = (char *)malloc(sizeof(char) * (minimized_str_len + 1))))
		return (NULL);
	mini_str[minimized_str_len] = 0;
	while (str[j])
	{
		if (str[j] != ' ')
		{
			mini_str[i] = str[j];
			i++;
		}
		j++;
	}
	return (mini_str);
}

void	validate_color_params(char *str, t_config *config)
{
	int		commas;
	int		numbers;
	char	*minimized_str;
	int		i;

	numbers = get_numbers_num(str);
	commas = get_commas_num(str);
	if (!(minimized_str = make_minimized_str(NULL, str + 1)))
		exit_cub(15, config);
	if (*(str + 1) != ' ' || commas != 2)
		exit_cub(7, config);
	i = -1;
	while (minimized_str[++i])
	{
		if (minimized_str[i] == ',')
		{
			if (!(ft_isdigit(minimized_str[i - 1]))
				|| !(ft_isdigit(minimized_str[i + 1])))
				exit_cub(7, config);
		}
	}
	if (numbers != 3)
		exit_cub(10, config);
	free(minimized_str);
}

void	fill_and_check_rgb(t_config *config, int rgb[3], char *str)
{
	int i;

	i = 0;
	while (i < 3)
	{
		find_color_value(&str, &rgb[i]);
		check_color_value(rgb[i], config);
		i++;
	}
}

void	parce_color(t_config *config, char *str)
{
	int	rgb[3];

	validate_color_params(str, config);
	fill_and_check_rgb(config, rgb, str);
	if (*str == 'F')
	{
		config->params.has_param[5]++;
		config->params.floor_color = translate_to_hex(rgb[0], rgb[1], rgb[2]);
	}
	else
	{
		config->params.has_param[6]++;
		config->params.ceiling_color = translate_to_hex(rgb[0], rgb[1], rgb[2]);
	}
}
