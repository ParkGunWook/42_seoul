/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libprint.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpark <gpark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 14:21:43 by gpark             #+#    #+#             */
/*   Updated: 2021/05/09 22:39:14 by gpark            ###   ########.fr       */
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

# define		L_FLAG 0
# define		H_FLAG 1
# define		LL_FLAG 2
# define		HH_FLAG 3

typedef struct	s_format
{
	int		type;
	int		flags[5];
	int		width;
	int		precision_count;
	int		length;
	size_t	spec_size;
	size_t	total_len;
}				t_format;

int				ft_printf(const char *str, ...);
void			ft_printf_format_spec(const char *str,
				t_format *format_spec, va_list ap);
size_t			ft_update_options(const char *str, t_format *format_spec, int spec);
void			fill_print_buffer(t_format *t_format, char *print_buffer,
				const char *str, size_t buffer_size);
char			*alloc_print_buffer(size_t size);
int				ft_print_char(t_format *format_spec, va_list ap);

#endif
