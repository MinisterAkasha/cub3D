# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    MAKEFILE                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akasha <akasha@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/16 18:20:59 by akasha            #+#    #+#              #
#    Updated: 2021/01/16 19:59:45 by akasha           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub.out

LIBFT_H = libft/includes
INCLUDES_H = -I Includes/

MINILIB_FLAGS = -framework OpenGL -framework AppKit
MINILIB = minilib/
MINILIB_A = libmlx.dylib

COMP = gcc -Wall -Wextra -Werror

CUB_SRC_DIR = src/
GNL_SRC_DIR = GNL/

LIBFT = libft/
LIBFT_A = libft.a

CUB_SRC = bmp.c exit_cub.c fill_lists.c fill_map.c free_everthing.c \
	get_hero_dir.c hooks.c init_img.c init.c load_image.c \
	move_hero.c parce_color.c parce_map.c parce_param.c \
	parce_tex.c parce_window.c rotate_hero.c run_window.c support.c \
	utils.c validation.c cast_ray/cast_ray.c \
	cast_ray/get_coordinate.c cast_ray/get_step.c cast_ray/get_useful_values.c \
	drow_sprites/get_coordinates.c drow_sprites/get_sprite_draw_range.c  \
	drow_sprites/get_useful_values.c drow_sprites/sort_sprites.c \
	drow_sprites/sprites.c check_input.c

GNL_SRC = get_next_line_utils.c get_next_line.c

MAIN = main.c

CFIND_CUB = $(CUB_SRC:%=$(CUB_SRC_DIR)%)
CFIND_GNL = $(GNL_SRC:%=$(GNL_SRC_DIR)%)

all: $(NAME)

$(NAME): $(LIBFT_A) $(MINILIB_A)
	$(COMP) $(INCLUDES_H) $(MAIN) $(LIBFT_A) $(MINILIB_A) $(MINILIB_FLAGS) $(CFIND_CUB) $(CFIND_GNL) -o $(NAME)

$(LIBFT_A):
	make bonus -C $(LIBFT)
	mv $(LIBFT)$(LIBFT_A) .

$(MINILIB_A):
	make -C $(MINILIB)
	mv $(MINILIB)$(MINILIB_A) .

clean:
	rm -rf $(OBJ_CUB) $(OBJ_GNL) *.out *.h.gch $(MINILIB_A) $(LIBFT_A)
	rm -f screenshot.bmp
	make clean -C $(LIBFT)
	make clean -C $(MINILIB)

fclean: clean
	rm -rf $(NAME)
	make fclean -C $(LIBFT)
	make clean -C $(MINILIB)

re: fclean all

.PHONY: all clean fclean re