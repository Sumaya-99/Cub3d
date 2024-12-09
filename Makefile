# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: suhelal <suhelal@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/25 11:09:27 by suhelal           #+#    #+#              #
#    Updated: 2024/10/16 17:06:19 by suhelal          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFILES 	   = main.c ./utils/ft_split.c ./utils/get_next_line.c ./utils/utils.c ./utils/get_next_line_utils.c \
./parsing/parsing.c ./parsing/direction_parse.c ./parsing/parse_line.c ./parsing/map_parsing.c ./utils/map_destroy.c\
./parsing/parse_color.c ./utils/ft_atoi.c ./parsing/copy_map.c ./parsing/utils.c ./parsing/check_map.c ./parsing/valid_direction.c ./utils/utils_2.c \
 ./movement/collision.c ./movement/init_direction.c ./movement/key.c ./movement/movement.c \
./raycasting/raycast.c ./raycasting/texture.c ./raycasting/drawing.c\

CC	= cc

CFLAGS	= -Wall -Wextra -Werror

MLXFLAGS = -L ./mlx -lmlx -Ilmlx -framework OpenGL -framework AppKit

MINILIBX_PATH = ./mlx

MINILIBX = $(MINILIBX_PATH)/libmlx.a

NAME	= cub3D

all: $(NAME)

$(NAME): $(CFILES)
	$(MAKE) -C $(MINILIBX_PATH)
	$(CC) $(CFLAGS) $(CFILES) $(MLXFLAGS) -o $(NAME)

clean: clean
	rm -f $(NAME)

fclean: clean
	rm -f $(NAME)

re: clean $(NAME)
