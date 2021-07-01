#include "cub.h"

void	fill_map(t_config *config, int size)
{
	t_list		*tmp;
	size_t		len_dif;
	int			i;
	char		*str;

	if (!(config->map.map = ft_calloc((size + 1), sizeof(char **))))
		exit_cub(15, config);
	tmp = config->head_map;
	i = 0;
	while (tmp)
	{
		len_dif = config->map.width - ft_strlen(tmp->content);
		if (!(str = (char *)malloc(sizeof(char) * (len_dif + 1))))
			exit_cub(15, config);
		str[len_dif] = 0;
		ft_memset(str, ' ', len_dif);
		config->map.map[i++] = ft_strjoin(tmp->content, str);
		free(str);
		config->map.height++;
		tmp = tmp->next;
	}
}
