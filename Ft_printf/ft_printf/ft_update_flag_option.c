/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_update_flag_option.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpark <gpark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 22:01:57 by gpark             #+#    #+#             */
/*   Updated: 2021/05/10 17:25:57 by gpark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libprint.h"

static size_t	ft_update_flag_option(const char *str, t_format *format_spec)
{
	if (*str == '0' && !format_spec->flags[MINUS_FLAG])
		format_spec->flags[ZERO_FLAG] = 1;
	else if (*str == '-' && !format_spec->flags[ZERO_FLAG])
		format_spec->flags[MINUS_FLAG] = 1;
	else if (*str == '#')
		format_spec->flags[SHARP_FLAG] = 1;
	else if (*str == ' ' && !format_spec->flags[PLUS_FLAG])
		format_spec->flags[SPACE_FLAG] = 1;
	else if (*str == '+' && !format_spec->flags[SPACE_FLAG])
		format_spec->flags[PLUS_FLAG] = 1;
	else
		return (0);
	return (1);
}

static size_t	ft_update_width_option(const char *str, t_format *format_spec)
{
	size_t	len;
	int		n;
	char	*new;

	n = ft_atoi(str);
	format_spec->width = n;
	new = ft_itoa(n);
	len = ft_strlen(new);
	free(new);
	return (len);
}

static size_t	ft_update_precision_option(const char *str,
				t_format *format_spec)
{
	size_t	len;
	int		n;
	char	*new;

	n = ft_atoi(str + 1);
	new = ft_itoa(n);
	len = ft_strlen(new);
	format_spec->precision_count += (len + 1);
	free(new);
	return (len + 1);
}

static size_t	ft_update_length_option(const char *str, t_format *format_spec)
{
	if (*str == 'l' && *(str + 1) == 'l')
		format_spec->length = LL_FLAG;
	else if (*str == 'h' && *(str + 1) == 'h')
		format_spec->length = HH_FLAG;
	else if (*str == 'l')
		format_spec->length = L_FLAG;
	else if (*str == 'h')
		format_spec->length = H_FLAG;
	if (format_spec->length <= 1)
		return (1);
	else
		return (2);
}

size_t			ft_update_options(const char *str,
				t_format *format_spec, int spec)
{
	size_t	n;

	n = 0;
	if (spec == FLAG)
		n = ft_update_flag_option(str, format_spec);
	else if (spec == WIDTH)
		n = ft_update_width_option(str, format_spec);
	else if (spec == PRECISION)
		n = ft_update_precision_option(str, format_spec);
	else if (spec == LENGTH)
		n = ft_update_length_option(str, format_spec);
	return (n);
}
