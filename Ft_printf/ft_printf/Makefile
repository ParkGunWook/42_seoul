CC = gcc
CFLAGS = -Wall -Werror -Wextra

NAME = libftprintf.a

LIBFT = ./libft/libft.a
LIBFTOBJS = ./libft/*.o
SRCS =  ft_printf.c	ft_common_print.c ft_printf_char.c ft_printf_format_spec.c ft_update_flag_option.c \
		ft_printf_string.c ft_printf_int.c ft_ntoa_flag.c ft_printf_pointer.c ft_printf_hexadecimal.c
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
	make clean -C ./libft

fclean :
	rm -f $(NAME) $(OBJS)
	make fclean -C ./libft

re :
	make fclean
	make all
