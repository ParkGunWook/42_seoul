# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gpark <gpark@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/06 15:56:09 by gpark             #+#    #+#              #
#    Updated: 2021/06/10 16:47:25 by gpark            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Werror -Wextra

NAME = so_long

SRCS_DIR = ./srcs
SRCS_NAME = main.c myloc.c map.c map_utils.c mlx.c mlx_image.c mlx_hook.c key_event.c
SRCS = $(addprefix $(SRCS_DIR)/, $(SRCS_NAME))
OBJS = $(SRCS:.c=.o)

LIB_NAME = ft
LIB_DIR = ./libft
LIB = $(addprefix $(LIB_DIR)/, libft.a)

MLX_NAME = mlx
MLX_DIR = ./mlx
MLX = $(addprefix $(MLX_DIR)/, libmlx.dylib)

INCLUDES = includes/

$(NAME) : $(OBJS)
	make -C $(LIB_DIR) all
	make -C $(MLX_DIR) all
	$(CC) $(CFLAGS) -I$(INCLUDES) -L$(LIB_DIR) -l$(LIB_NAME) -L$(MLX_DIR) -l$(MLX_NAME) \
		$^ -o $@
	@install_name_tool -change libmlx.dylib ./mlx/libmlx.dylib $(NAME)

$(SRCS_DIR)/%.o : $(SRCS_DIR)/%.c
	$(CC) $(CFLAGS) -I$(INCLUDES) -I$(MLX_DIR) -I$(LIB_DIR) -c $< -o $@

all : $(NAME)

clean :
	$(MAKE) -C $(LIB_DIR) clean
	$(MAKE) -C $(MLX_DIR) clean
	rm -rf $(OBJS)

fclean :
	$(MAKE) -C $(LIB_DIR) fclean
	$(MAKE) -C $(MLX_DIR) clean
	rm -rf $(NAME) $(OBJS)

re : fclean all

bonus : all
