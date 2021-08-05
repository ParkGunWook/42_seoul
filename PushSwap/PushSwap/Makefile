CC = gcc
CFLAGS = -Wall -Werror -Wextra

NAME = push_swap

SRCS_DIR = ./srcs
SRCS_NAME = main.c myloc.c \
			linkedListUtils1.c linkedListUtils2.c
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

bonus : all
