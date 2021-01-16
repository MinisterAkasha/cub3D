# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    MAKEFILE                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akasha <akasha@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/15 17:54:33 by akasha            #+#    #+#              #
#    Updated: 2021/01/16 15:40:21 by akasha           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub.out

LIBFT_H = -I libft/includes
INCLUDES_H = -I Includes

MINILIB_FLAGS = -framework OpenGL -framework AppKit
MINILIB = minilib/libmlx.dylib

COMP = gcc -Wall -Wextra -Werror $(LIBFT_H) $(INCLUDES_H) -c

OBJ_DIR = obj/
CUB_SRC_DIR = src/
GNL_SRC_DIR = GNL/

LIBFT = libft/
LIBFT_A = libft.a

CUB_SRC = bmp.c exit_cub.c fill_lists.c fill_map.c free_everthing.c \
	get_hero_dir.c hooks.c init_img.c init_img.c init.c load_image.c \
	move_hero.c parce_color.c parce_map.c parce_param.c \
	parce_tex.c parce_window.c rotate_hero.c run_window.c support.c \
	utils.c validation.c cast ray/cast_ray.c \
	cast ray/get_coordinate.c cast ray/get_step.c cast ray/get_useful_values.c \
	drow sprites/get_coordinates.c drow sprites/get_sprite_draw_range.c  \
	drow sprites/get_useful_values.c drow sprites/sort_sprites.c \
	drow sprites/sprites.c

GNL_SRC = get_next_line_utils.c get_next_line.c

MAIN = main.c

CFIND_CUB = $(CUB_SRC:%=$(CUB_SRC_DIR)%)
CFIND_GNL = $(GNL_SRC:%=$(GNL_SRC_DIR)%)

OBJ_CUB =	$(CUB_SRC:.c=.o)
OBJ_GNL =	$(GNL_SRC:.c=.o)


all: $(NAME)

$(NAME): 
	make -C $(LIBFT)
	make -C $(MINILIB)
	
	

$(OBJ): $(CFIND_CUB) $(CFIND_GNL)
	make $(OFILE_CUB) $(OFILE_GNL)

$(OFILE_CUB):
	@$(COMP) $(OBJ_DIR)$@ $(CUB_SRC_DIR)$(@:%.o=%.c)

$(OFILE_GNL):
	@$(COMP) $(OBJ_DIR)$@ $(GNL_SRC_DIR)$(@:%.o=%.c)

clean:
	rm -rf $(OBJ) *.out *.h.gch $(OBJ_DIR)
	make clean -C $(LIBFT)
	make clean -C $(MINILIB)

fclean: clean
	rm -rf $(NAME)
	make fclean -C $(LIBFT)
	make flean -C $(MINILIB)

re: fclean all

.PHONY: all clean fclean re