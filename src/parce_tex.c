#include "cub.h"

void	validate_tex_params(t_config *config, char *str)
{
	if ((*str == 'S' && *(str + 1) != 'O'))
	{
		if (*(str + 1) != ' ')
			exit_cub(12, config);
	}
	else
	{
		if (*(str + 2) != ' ')
			exit_cub(12, config);
	}
}

void	check_valid_path(t_config *config, char **path)
{
	int		fd;
	int		len;
	char	*copy;
	char	buf;

	fd = open(*path, O_RDONLY);
	if (read(fd, &buf, 1) < 0)
		exit_cub(12, config);
	if (fd == -1)
		exit_cub(12, config);
	close(fd);
	len = ft_strlen(*path);
	copy = ft_strdup(*path);
	if (copy[len - 1] != 'm' && copy[len - 2] != 'p' && copy[len - 3] != 'x')
	{
		free(copy);
		exit_cub(12, config);
	}
	free(copy);
}

void	find_correct_tex(t_config *config, char *str)
{
	if ((*str == 'N' && *(str + 1) == 'O'))
	{
		config->params.has_param[0]++;
		paste_correct_text_path(config, str, &config->params.north_tex);
	}
	else if ((*str == 'S' && *(str + 1) == 'O'))
	{
		config->params.has_param[1]++;
		paste_correct_text_path(config, str, &config->params.south_tex);
	}
	else if ((*str == 'W' && *(str + 1) == 'E'))
	{
		config->params.has_param[2]++;
		paste_correct_text_path(config, str, &config->params.west_tex);
	}
	else if ((*str == 'E' && *(str + 1) == 'A'))
	{
		config->params.has_param[3]++;
		paste_correct_text_path(config, str, &config->params.east_tex);
	}
	else if (*str == 'S')
	{
		config->params.has_param[4]++;
		paste_correct_text_path(config, str, &config->params.spraite_tex);
	}
}

void	paste_correct_text_path(t_config *config, char *str, char **tex)
{
	while (*str != ' ')
		str++;
	str += skip_spaces(str);
	*tex = ft_strtrim(str, " ");
	check_valid_path(config, tex);
}

void	parce_tex(t_config *config, char *str)
{
	find_correct_tex(config, str);
	validate_tex_params(config, str);
}
