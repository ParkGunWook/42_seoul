# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gpark <gpark@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/06 15:56:09 by gpark             #+#    #+#              #
#    Updated: 2021/06/20 11:00:55 by gpark            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Werror -Wextra

NAME = pipex

SRCS_DIR = ./srcs
SRCS_NAME = main.c ft_perror.c redirect.c cmd.c \
			ft_strjoin.c ft_split.c ft_strjoin.c ft_substr.c ft_strlcpy.c ft_strlen.c
SRCS = $(addprefix $(SRCS_DIR)/, $(SRCS_NAME))
OBJS = $(SRCS:.c=.o)

INCLUDES = includes/

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) -I$(INCLUDES) $^ -o $@

$(SRCS_DIR)/%.o : $(SRCS_DIR)/%.c
	$(CC) $(CFLAGS) -I$(INCLUDES) -c $< -o $@

all : $(NAME)

clean :
	rm -rf $(OBJS)

fclean :
	rm -rf $(NAME) $(OBJS)

re : fclean all
