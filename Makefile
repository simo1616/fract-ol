# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbendidi <mbendidi@student.42lausanne.c    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/04 15:38:51 by mbendidi          #+#    #+#              #
#    Updated: 2024/12/04 16:46:32 by mbendidi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

CC = gcc
CFLAGS = -Wall -Wextra -Werror

MLX_DIR = minilibx-linux
MLX_LIB = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm
MLX_INC = -I$(MLX_DIR)

SRC_DIR = src
SRC = $(SRC_DIR)/main.c \
      $(SRC_DIR)/init.c \
      $(SRC_DIR)/init_fractals.c \
      $(SRC_DIR)/events_key.c \
      $(SRC_DIR)/events_mouse.c \
      $(SRC_DIR)/render.c \
      $(SRC_DIR)/render_utils.c \
      $(SRC_DIR)/utils.c \
      $(SRC_DIR)/math_complex.c \
      $(SRC_DIR)/math_colors.c \
      $(SRC_DIR)/graphics.c

INCLUDE = -I include

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(MLX_LIB)

%.o: %.c
	$(CC) $(CFLAGS) $(MLX_INC) $(INCLUDE) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
