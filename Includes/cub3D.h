/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akasha <akasha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 17:12:13 by akasha            #+#    #+#             */
/*   Updated: 2020/12/12 15:06:53 by akasha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_3D_H
# define CUB_3D_H

# include "../libft/includes/libft.h"
# include "../minilb/mlx.h"
# include "get_next_line.h"
# include <fcntl.h>
# include <math.h>


#include "stdio.h" //!DEL

typedef struct	s_map {
	int			nl;
	int			scale;
	char		**map;
	char		*hero_set;
	char		*space_set;
	char		*inner_set;
	size_t		max_len;
	size_t		height;
}				t_map;

typedef struct	s_hero {
	double		y;
	double		x;
	double		dir;
	double		start;
	double		end;
}				t_hero;

typedef struct	s_win {
	void		*mlx;
	void		*window;
}				t_win;

typedef struct  s_data {
    void        *img;
    char        *addr;
    int         bits_per_pixel;
    int         line_length;
    int         endian;
}               t_data;

typedef struct	s_config_struct
{
	t_map		map;
	t_win		win;
	t_data		data;
	t_hero		hero;
}				t_config;

int		parcer(t_config *config);
void	init_struct(t_config *config, t_list *head);


void	my_mlx_pixel_put(t_data *data, int x, int y, int color);

char	**fill_map(t_list *head, int size, t_config *config);
void	put_pixel_scale(int x, int y, t_config *config);
void	write_2d_map(t_config *config);

/*
** move_hero
*/

int		move_hero(int keycode, t_config *config);
int		button(int key);
int		rotate_hero(int keycode, t_config *config);



/*
** init_struct.c
*/
void	init_img(t_config *config);
void	run_window(t_config *config);

/*
**	utilc.c
*/

void	ft_find_max_len(char *str, t_config	*config);

/*
**	cast_ray.c
*/
void	cast_ray(t_config *config, t_hero ray);
void	cast_rays(t_config *config);

#endif