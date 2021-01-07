/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akasha <akasha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 17:12:13 by akasha            #+#    #+#             */
/*   Updated: 2021/01/07 16:00:30 by akasha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_3D_H
#define CUB_3D_H

# include "../libft/includes/libft.h"
# include "../minilib/mlx.h"
# include "get_next_line.h"
# include <fcntl.h>
# include <math.h>
# include "stdio.h" //!DEL
# include <errno.h> //! DEL???

typedef struct	s_map
{
	int		new_line;
	char	**map;
	char	*hero_set;
	char	*space_set;
	char	*inner_set;
	size_t	width;
	size_t	height;
	int		sprites_num;
	int		has_hero;
}				t_map;

typedef struct s_sprite
{
	double 		x;
	double		y;
}				t_sprite;

typedef struct	s_texture
{
	void	*img[5];
	char	*addr[5];
	int		bits_per_pixel[5];
	int		line_length[5];
	int		endian[5];
	int		width[5];
	int		height[5];
	size_t	*texture[5];
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
	double camera_x;
	double move_speed;
	double rotate_speed;
}				t_hero;

typedef struct	s_ray
{
	double ray_dir_y;
	double ray_dir_x;
	double delta_x;
	double delta_y;
	double side_x;
	double side_y;
	double perp_wall_dist;
	double step_x;
	double step_y;
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
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
} 				t_data;

typedef struct	s_error
{
	char	*error[12];
}				t_error;

typedef struct	s_params
{
	int		max_width;
	int		max_height;
	double	window_width;
	double	window_height;
	char	*north_tex;
	char	*south_tex;
	char	*west_tex;
	char	*east_tex;
	char	*spraite_tex;
	int		floor_color;
	int		ceiling_color;
	int		has_param[9];
}				t_params;

typedef struct		s_config_struct
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
	t_params		params;
	t_error			error;
}					t_config;

void			parce_map(t_config *config);
void			init_struct(t_config *config);
void			ft_get_camera_coordinate(t_config *config, int x);

char			**fill_map(t_config *config, int size);
void			put_pixel_scale(int x, int y, t_config *config);
void			render(t_config *config);
void			free_texture(t_config *config);

/*
** parce_param
*/

void			parce_param(t_config *config);
int				parce_window_param(t_config *config, char *str);

/*
** validation
*/

int				ft_check_inner_elem(t_config *config, int y, int x);
int				ft_check_unit(t_config *config, int y, int x);
int				ft_check_border(t_config *config, int y, int x);
int				ft_validate_map(t_config *config, int y, int x);

/*
** move_hero
*/

void			ft_move_right(t_config *config);
void			ft_move_left(t_config *config);
void			ft_move_forward(t_config *config);
void			ft_move_back(t_config *config);

/*
** rotate_hero
*/

void	ft_rotate_left(t_config *config);
void	ft_rotate_right(t_config *config);

/*
** init_struct.c
*/

void			init_image(t_config *config);
void			init_error(t_config *config);

/*
** run_window
*/

void			run_window(t_config *config);

/*
**	cast_ray.c
*/

void			cast_rays(t_config *config, int x);
int				get_texture_number(t_config *config, int y, int x, int side);

/*
**	load_img.c
*/

void			load_img(t_config *config);
void			make_texture(t_config *config, int index);
char			*get_texture_path(int index, t_config *config);

/*
** sprites.c
*/

void			init_map_objects(t_config *config);
void			get_hero_dir(t_config *config, int y, int x);
void			init_sprites(t_config *config);
void			sprite_cast(t_config *config, double z_buffer[(int)config->params.window_width]);

int				partition(double *arr, int left, int right, double *order);
void			swap_elems(double *elem_1, double *elem_2);
void			sort_sprites(double distanse[], int left, int right, double *order);

/*
** exit_cub
*/

void			exit_cub(int error_code, t_config *config);

/*
** support
*/

int				get_spases_num(char *str);
int				get_numbers_num(char *str);
unsigned long	translate_to_hex(int red, int green, int blue);
int				get_commas_num(char *str);
void			fast_pixel_put(t_data *data, int x, int y, int color);

/*
**	utilc.c
*/

void			ft_find_width(char *str, t_config *config);
int				skip_spaces(char *str);
void			skip_number(char **str);
void			skip_not_number(char **str);

/*
** parce_color
*/

void			check_color_value(int color, t_config *config);
void			find_color_value(char **str, int *color);
void			validate_color_params(char *str, t_config *config);
char			*make_minimized_str(char *mini_str, char *str);
void			parce_color(t_config *config, char *str);
void			fill_and_check_rgb(t_config *config, int rgb[3], char *str);

/*
** parce_window
*/

void			check_max_size(t_config *config);
int				parce_window_param(t_config *config, char *str);

/*
** parce_window
*/

void			parce_tex(t_config *config, char *str);

/*
** hooks
*/
int				close_win(int keycode, t_config *config);
int				move_hero_hook(int keycode, t_config *config);
int				button(int key);

#endif
