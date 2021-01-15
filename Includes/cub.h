/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akasha <akasha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 16:05:22 by akasha            #+#    #+#             */
/*   Updated: 2021/01/15 17:24:55 by akasha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

# include "../libft/includes/libft.h"
# include "../minilib/mlx.h"
# include "get_next_line.h"
# include <fcntl.h>
# include <math.h>
# include "stdio.h" //!DEL
# include <errno.h>

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

typedef struct	s_ray_casting {
	int			map_x;
	int			map_y;
	size_t		tex_color;
	int			side;
	double		wall_x;
	int 		tex_x;
	int 		tex_y;
	int			line_height;
	double		step;
	double		tex_pos;
}				t_ray_casting;

typedef struct	s_sprite_position
{
	double		x;
	double		y;
}				t_sprite_position;

typedef struct	s_sprite
{
	double	*depth;
	double	*sprite_order;
	double	*sprite_distanse;
	double	sprite_x;
	double	sprite_y;
	double	transform_x;
	double	transform_y;
	int		sprite_screen_x;
	int		sprite_height;
	int		sprite_width;
	int		drow_start_y;
	int		drow_end_y;
	int		drow_start_x;
	int		drow_end_x;
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
}				t_data;

typedef struct	s_error
{
	char	*error[13];
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
	int		screenshot;
}				t_params;

typedef struct  s_bmp_header {
    unsigned char   file_header[14];
    unsigned char   info_header[40];
}               t_bmp_header;

typedef struct	s_config_struct
{
	t_map				map;
	t_win				win;
	t_data				data;
	t_ray				ray;
	t_hero				hero;
	t_texture			img;
	t_sprite_position	*sprite_pos;
	t_sprite			sprite;
	t_list				*head_map;
	t_list				*head_param;
	t_params			params;
	t_error				error;
	t_ray_casting		ray_casting;
	t_bmp_header		bmp;
}				t_config;

void			parce_map(t_config *config);
void			ft_get_camera_coordinate(t_config *config, int x);

int				render(t_config *config);
void			free_texture_arr(t_config *config);
// void			check_arguments(int argc, char *argv[], t_config *config);
void			fill_param_list(t_config *config, int fd);
void			fill_map_list(t_config *config, int fd);
void			check_file_name(char *file_name, t_config *config);

/*
** fill_lists
*/

void	fill_param_list(t_config *config, int fd);
void	fill_map_list(t_config *config, int fd);

/*
** fill_map
*/

void			fill_map(t_config *config, int size);

/*
** validation
*/

int				ft_check_inner_elem(t_config *config, int y, int x);
int				ft_check_unit(t_config *config, int y, int x);
int				ft_check_border(t_config *config, int y, int x);
int				ft_validate_map(t_config *config, int y, int x);

/*
** init_img
*/

void			init_image(t_config *config);

/*
** init
*/

void			init_struct(t_config *config);
void			init_error(t_config *config);
void			init_map_objects(t_config *config);
void			init_sprites(t_config *config);

/*
** get_hero_dir
*/

void			get_hero_dir(t_config *config, int y, int x);
void			set_north_dir(t_config *config);
void			set_west_dir(t_config *config);
void			set_south_dir(t_config *config);
void			set_east_dir(t_config *config);

/*
** run_window
*/

void			run_window(t_config *config);

/*
**	cast_ray
*/

void			cast_rays(t_config *config, int x);
int				get_texture_number(t_config *config, int y, int x);

/*
**	cast_ray -> get_coordinate
*/

void			ft_get_camera_coordinate(t_config *config, int x);
void			get_map_coordinates(t_config *config);
void			get_hit_coordinate(t_config *config);
void			get_x_tex_coordinate(t_config *config, int tex_num);
void			get_y_tex_coordinate(t_config *config, int tex_num);

/*
**	cast_ray -> get_step
*/

void			get_side_and_step_x(t_config *config);
void			get_side_and_step_y(t_config *config);
void			get_step_value(t_config *config, int tex_num);

/*
**	cast_ray -> get_useful_values
*/

void			get_ray_delta(t_config *config);
void			get_distance(t_config *config);
void			get_line_height(t_config *config);
void			get_drow_wall_range(t_config *config);
void			get_tex_pos(t_config *config);

/*
**	load_images
*/

void			load_images(t_config *config);
void			make_texture(t_config *config, int i);
char			*get_texture_path(int index, t_config *config);

/*
** sprites
*/

void			sprite_cast(t_config *config);

/*
** sort_sprites
*/
int				partition(t_config *config, int left, int right);
void			swap_elems(double *elem_1, double *elem_2);
void			sort_sprites(t_config *config, int left, int right);

/*
** parce_param
*/

void			parce_param(t_config *config);
void			check_all_params(t_config *config);
void			find_correct_param_and_parce(char *str, t_config *config);

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
** parce_tex
*/

void			remember_presence_texture(t_config *config);
void			parce_tex(t_config *config, char *str);

/*
** hooks
*/

int				close_win(t_config *config);
int				hooks(int keycode, t_config *config);
int				button(int key);
void			destroy_images(t_config *config);

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

void			ft_rotate_left(t_config *config);
void			ft_rotate_right(t_config *config);

/*
** support
*/

int				get_spases_num(char *str);
int				get_numbers_num(char *str);
int				get_commas_num(char *str);
void			fast_pixel_put(t_data *data, int x, int y, int color);

/*
**	utilc.c
*/

void			ft_find_width(char *str, t_config *config);
int				skip_spaces(char *str);
void			skip_number(char **str);
void			skip_not_number(char **str);
unsigned long	translate_to_hex(int red, int green, int blue);

/*
** free_everthing
*/

void			free_texture_arr(t_config *config);
void			free_all(t_config *config);

/*
** bmp
*/
void		    generate_bmp_image(t_config *config);
void    		create_bmp_file_header(t_config *config);
void		    create_bmp_info_header(t_config *config);
void		    reset_to_zero(unsigned char header[], int size);

/*
** exit_cub
*/

void			exit_cub(int error_code, t_config *config);

#endif
