# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmaksymi <mmaksymi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/11 16:51:42 by mmaksymi          #+#    #+#              #
#    Updated: 2025/01/16 15:59:59 by mmaksymi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wall -Werror -Wextra

NAME = so_long

SRCS = main.c \
	srcs/map/map.c \
	srcs/map/walls_and_form_check.c \
	srcs/map/map_check.c \
	srcs/graphics/textures.c
	
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
