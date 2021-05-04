CC = gcc
CFLAGS = -Wall -Werror -Wextra

NAME = libft.a

INCLUDE = -Iincludes

BONUSSRCS = $(wildcard *lst*.c)
SRCS = $(filter-out $(BONUSSRCS), $(wildcard *.c))
OBJS = $(SRCS:.c=.o)
BONUSOBJS = $(BONUSSRCS:.c=.o)
HDRS = libft.h

all : $(NAME)

$(NAME) : $(OBJS)
	ar rc $(NAME) $(OBJS)

bonus : $(BONUSOBJS)
	ar rc $(NAME) $(BONUSOBJS)

%.o : %.c
	$(CC) $(CFLAGS) $(INCLUDE) -c $^ -o $@

clean :
	rm -f $(OBJS)

fclean :
	rm -f $(NAME) $(OBJS)

re :
	make fclean
	make all
