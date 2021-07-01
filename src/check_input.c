#include "cub.h"

void	check_arguments(int argc, char *argv[], t_config *config)
{
	if (argc == 3 && ft_strlen(argv[2]) == 6
						&& ft_strcmp(argv[2], "--save") == 0)
		config->params.screenshot = 1;
	else if (argc > 2)
		exit_cub(0, config);
	else if (argc < 2)
		exit_cub(1, config);
}

void	check_file_name(char *file_name, t_config *config)
{
	while (*file_name)
		file_name++;
	file_name--;
	if (*file_name == 'b' && *(file_name - 1) == 'u'
	&& *(file_name - 2) == 'c' && *(file_name - 3) == '.')
		return ;
	exit_cub(11, config);
}
