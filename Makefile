# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmaksymi <mmaksymi@student.42nice.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/11 16:51:42 by mmaksymi          #+#    #+#              #
#    Updated: 2025/01/19 13:49:04 by mmaksymi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wall -Werror -Wextra -Wno-unused-but-set-variable

NAME = so_long

SRCS = main.c \
	srcs/map/map.c \
	srcs/map/walls_and_form_check.c \
	srcs/map/map_obj_check.c \
	srcs/map/map_path_check.c \
	srcs/graphics/image.c \
	srcs/graphics/textures.c \
	srcs/graphics/player.c \
	srcs/player/jsp.c \
	srcs/player/controls.c
	
OFILES = $(SRCS:.c=.o)

LIBFT_NAME = libft.a
LIBFT_DIR = libs/libft
LIBFT = $(LIBFT_DIR)/$(LIBFT_NAME)

MLX_NAME = libmlx.a
MLX_DIR = libs/mlx
MLX = $(MLX_DIR)/$(MLX_NAME)

LIBS = -lXext -lX11 -lm

CC = cc

all: $(NAME)

$(MLX): $(MLX_DIR)
	make -C $(MLX_DIR)

$(LIBFT): $(LIBFT_DIR)
	make -C $(LIBFT_DIR) $(LIBFT_NAME)

$(NAME): $(OFILES) $(LIBFT) $(MLX)
	$(CC) $(CFLAGS) $(OFILES) $(MLX) $(LIBFT) $(LIBS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	make clean -C $(LIBFT_DIR)
	rm -rf $(OFILES)

fclean: clean
	make fclean -C $(LIBFT_DIR)
	rm -rf $(NAME) $(OFILES)

re: fclean $(NAME)

run: re
	./$(NAME)
