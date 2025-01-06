# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmaksymi <mmaksymi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/11 16:51:42 by mmaksymi          #+#    #+#              #
#    Updated: 2025/01/03 15:56:00 by mmaksymi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wall -Werror -Wextra

NAME = so_long

SRCS = main.c \
	srcs/map/map.c \
	srcs/map/walls_and_form_check.c \
	srcs/map/map_check.c
	
OFILES = $(SRCS:.c=.o)

LIBFT_NAME = libft.a
LIBFT_DIR = libs/libft
LIBFT = $(LIBFT_DIR)/$(LIBFT_NAME)

CC = cc

all: $(NAME)

$(LIBFT): $(LIBFT_DIR)
	make -C $(LIBFT_DIR) $(LIBFT_NAME)

$(NAME): $(OFILES) $(LIBFT)
	$(CC) $(CFLAGS) $(OFILES) $(LIBFT) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	make clean -C $(LIBFT_DIR)
	rm -rf $(OFILES)

fclean: clean
	make fclean -C $(LIBFT_DIR)
	rm -rf $(NAME) $(OFILES)

re: fclean $(NAME)
