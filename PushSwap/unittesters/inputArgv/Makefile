CC = gcc
CFLAGS = -Wall -Werror -Wextra

NAME = push_swap

SRCS_DIR = ../../pushswap/srcs
SRCS_NAME = myloc.c \
			linkedListUtils1.c linkedListUtils2.c \
			stackUtils1.c stackUtils2.c stackUtils3.c \
			argvParser.c ft_atoll.c ft_strlcpy.c ft_strlen.c ft_substr.c
SRCS = $(addprefix $(SRCS_DIR)/, $(SRCS_NAME)) inputArgvMain.c

OBJS = $(SRCS:.c=.o)

INCLUDES = ../../pushswap/includes/

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
