/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libprint.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpark <gpark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 14:21:43 by gpark             #+#    #+#             */
/*   Updated: 2021/05/13 21:23:20 by gpark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBPRINT_H
# define LIBPRINT_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include "./libft/libft.h"

# include <stdio.h>
# include <string.h>

# define		CHAR 1
# define		STRING 2
# define		INT 3
# define		POINTER 4
# define		UNSIGNED_INT 5
# define		S_HEXADECIMAL 6
# define		L_HEXADECIMAL 7
# define		PERCENT 8
# define		COUNTER 9
# define		FLOAT 10
# define		GRANULATED_FLOAT 11
# define		EXPONENTIAL 12
# define		FLAG 13
# define		WIDTH 14
# define		PRECISION 15
# define		LENGTH 16

# define 		ZERO_FLAG 0
# define 		MINUS_FLAG 1
# define 		SHARP_FLAG 2
# define 		SPACE_FLAG 3
# define 		PLUS_FLAG 4
# define 		PZERO_FLAG 5

# define		L_FLAG 0
# define		H_FLAG 1
# define		LL_FLAG 2
# define		HH_FLAG 3

# define		BUFFER 0
# define		STR 1

typedef struct	s_format
{
	int		type;
	int		flags[6];
	int		width;
	int		precision;
	int		length;
	size_t	spec_size;
	size_t	size[2];
}				t_format;

int				ft_printf(const char *str, ...);
int				ft_printf_format_spec(const char *str,
				t_format *format_spec, va_list ap);
size_t			ft_update_options(const char *str, t_format *format_spec, int spec, va_list ap);
void			fill_print_buffer(t_format *format_spec, char *print_buffer,
				const char *str);
char			*alloc_print_buffer(size_t size);
int				ft_printf_char(t_format *format_spec, va_list ap);
int				ft_printf_string(t_format *format_spec, va_list ap);
int				ft_printf_int(t_format *t_format_spec, va_list ap);
int				ft_printf_pointer(t_format *format_spec, va_list ap);
int				ft_printf_unsigned_int(t_format *format_spec, va_list ap);
int				ft_printf_hexadecimal(t_format *format_spec, va_list ap);
int				ft_printf_percent(t_format *format_spec);
char			*ft_ntoa_flag(long long n, long long base, t_format *format_spec);
char			*ft_ptoa_flag(unsigned long long n, unsigned long long base,
				t_format *format_spec);
char			base_to_base(long long idx, t_format *format_spec);
size_t			zero_counter(const char *str);
void			put_pointer(unsigned long long pos_n, unsigned long long base,
				char *new, t_format *format_spec);
size_t			ptr_base_len(unsigned long long n, unsigned long long base,
				t_format *format_spec);

#endif
