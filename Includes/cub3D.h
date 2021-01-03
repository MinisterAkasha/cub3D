/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akasha <akasha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 17:12:13 by akasha            #+#    #+#             */
/*   Updated: 2021/01/03 16:30:31 by akasha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_3D_H
#define CUB_3D_H

#include "../libft/includes/libft.h"
#include "../minilib/mlx.h"
#include "get_next_line.h"
#include <fcntl.h>
#include <math.h>

#include "stdio.h" //!DEL

#define HEIGHT 1080
#define WIDTH 1920

typedef struct	s_map
{
	int new_line;
	char **map;
	char *hero_set;
	char *space_set;
	char *inner_set;
	size_t width;
	size_t height;
	int	sprites_num;
	int	has_hero;
}				t_map;

typedef struct s_sprite
{
	double 		x;
	double		y;
}				t_sprite;

typedef struct	s_texture
{
	void *img[5];
	char *addr[5];
	int bits_per_pixel[5];
	int line_length[5];
	int endian[5];
	int width[5];
	int height[5];
	size_t *texture[5];
}				t_texture;

typedef struct	s_hero
{
	double y;
	double x;
	double dir_x;
	double dir_y;
	double dir;
	double plane_x;
	double plane_y;
	double start;
	double end;
	double cameraX;
	double move_speed;
	double rotate_speed;
}				t_hero;

typedef struct	s_ray
{
	double ray_dir_y;
	double ray_dir_x;
	double deltaX;
	double deltaY;
	double sideX;
	double sideY;
	double perp_wall_dist;
	double stepX;
	double stepY;
	double start;
	double end;
}				t_ray;

typedef struct	s_win
{
	void	*mlx;
	void	*window;
}				t_win;

typedef struct	s_data
{
	void *img;
	char *addr;
	int bits_per_pixel;
	int line_length;
	int endian;
} 				t_data;
typedef struct s_settings
{
	char		**source;
	int			max_width;
	int			window_width;
	int			max_height;
	int			window_height;
	char		*no_tex;
	char		*so_tex;
	char		*we_tex;
	char		*ea_tex;
	char		*sparite_tex;
	char		*floor_color;
	char		*ceiling_color;
}				t_settings;

typedef struct s_config_struct
{
	t_map			map;
	t_win			win;
	t_data			data;
	t_ray			ray;
	t_hero			hero;
	t_texture		img;
	t_sprite		*sprite;
	t_list			*head_map;
	t_list			*head_param;
	t_settings		settings;
} 				t_config;

int		parce_map(t_config *config);
void	init_struct(t_config *config);
void	ft_get_camera_coordinate(t_config *config, int x);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);

char	**fill_map(t_config *config, int size);
void	put_pixel_scale(int x, int y, t_config *config);
void	render(t_config *config);
void	free_texture(t_config *config);

/*
** parce_param
*/

int		parce_param(t_config *config);
int		parce_window_param(t_config *config, char *str);

/*
** validation
*/

int		ft_check_inner_elem(t_config *config, int y, int x);
int		ft_check_unit(t_config *config, int y, int x);
int		ft_check_border(t_config *config, int y, int x);
int		ft_validate_map(t_config *config, int y, int x);

/*
** move_hero
*/

int		move_hero(int keycode, t_config *config);
int		button(int key);
int		rotate_hero(int keycode, t_config *config);

/*
** init_struct.c
*/
void	init_image(t_config *config);
void	run_window(t_config *config);

/*
**	utilc.c
*/

void 	ft_find_width(char *str, t_config *config);
int		skip_spaces_index(char *str);
void	skip_spaces(char **str);

/*
**	cast_ray.c
*/
void 	cast_rays(t_config *config, int x);
int 	get_texture_number(t_config *config, int y, int x, int side);

/*
**	load_img.c
*/
void	load_img(t_config *config);
void	make_texture(t_config *config, int index);
char	*get_texture_path(int index);

/*
** sprites.c
*/
void	init_map_objects(t_config *config);
void	get_hero_dir(t_config *config, int y, int x);
void	init_sprites(t_config *config);
void	sprite_cast(t_config *config, double z_buffer[WIDTH]);


int		partition(double *arr, int left, int right, double *order);
void	swap_elems(double *elem_1, double *elem_2);
void 	sort_sprites(double distanse[], int left, int right, double *order);
#endif