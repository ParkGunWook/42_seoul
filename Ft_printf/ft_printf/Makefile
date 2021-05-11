CC = gcc
CFLAGS = -Wall -Werror -Wextra

NAME = libftprintf.a

LIBFT = ./libft/libft.a
LIBFTOBJS = ./libft/*.o
SRCS =  ft_printf.c	ft_common_print.c ft_printf_char.c ft_printf_format_spec.c ft_update_flag_option.c \
		ft_printf_string.c ft_printf_int.c ft_ntoa_flag.c
OBJS = $(SRCS:.c=.o)


all : $(NAME)

$(NAME) : $(OBJS) $(LIBFT)
	cp $(LIBFT) $(NAME)
	ar rcs $(NAME) $(OBJS)

%.o : %.c
	$(CC) $(CFLAGS) -c $^ -o $@

$(LIBFT) :
	make -C ./libft

clean :
	rm -f $(OBJS)

fclean :
	rm -f $(NAME) $(OBJS)

re :
	make fclean
	make all
