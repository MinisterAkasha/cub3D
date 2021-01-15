# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    MAKEFILE                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akasha <akasha@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/15 17:54:33 by akasha            #+#    #+#              #
#    Updated: 2021/01/15 18:13:47 by akasha           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub.out

LIBFT_H = -I libft/includes
INCLUDES_H = -I includes

COMP = gcc -Wall -Wextra -Werror $(LIBFT_H) $(INCLUDES_H) -o $(NAME)

OBJ_DIR = obj/
SRC_DIR = src/

LIBFT = libft/
LIBFT_A = libft.a

src = bmp.c exit_cub.c fill_lists.c fill_map.c free_everthing.c \
	get_hero_dir.c hooks.c init_img.c init_img.c init.c load_image.c \
	move_hero.c parce_color.c parce_map.c parce_param.c \
	parce_tex.c parce_window.c rotate_hero.c run_window.c support.c \
	utils.c validation.c cast ray/cast_ray.c \
	cast ray/get_coordinate.c cast ray/get_step.c cast ray/get_useful_values.c \
	drow sprites/get_coordinates.c drow sprites/get_sprite_draw_range.c  \
	drow sprites/get_useful_values.c drow sprites/sort_sprites.c \
	drow sprites/sprites.c

CFIND = $(SRC:%=$(SRC_DIR)%)

OFILE =	$(SRC:%.c=%.o)

OBJ = $(addprefix $(OBJ_DIR), $(OFILE))

all: $(OBJ_DIR) $(NAME)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)