CC = gcc
CFLAGS = -Wall -Werror -Wextra

NAME = libft.a

INCLUDE = -Iincludes

SRCS = $(wildcard (.c))
OBJS = $(SRCS:.c=.o)
HDRS = libft.h

all : $(NAME)

$(NAME) : $(OBJS)
	ar rc $(NAME) $(OBJS)

%.o : %.c
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

clean :
	rm -f $(OBJS)

fclean :
	rm -f $(NAME) $(OBJS)

re :
	make fclean
	make all
