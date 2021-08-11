CC = gcc
CFLAGS = -Wall -Werror -Wextra

NAME = push_swap

SRCS_DIR = ./srcs
SRCS_NAME = main.c myloc.c \
			linkedListUtils1.c linkedListUtils2.c \
			stackUtils1.c stackUtils2.c stackUtils3.c \
			argvParser.c ft_atoll.c ft_strlcpy.c ft_strlen.c ft_substr.c \
			listToArray.c ft_memset.c \
			recoverStack.c sortA.c sortAThree.c sortB.c sortBThree.c \
			sortFive.c sortMain.c sortThree.c getPivots.c
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
