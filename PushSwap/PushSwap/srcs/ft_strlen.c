/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpark <gpark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 23:03:09 by gpark             #+#    #+#             */
/*   Updated: 2021/06/14 15:53:45 by gpark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "myloc.h"
#include "utils.h"

int	ft_strlen(const char *str)
{
	int	str_size;

	str_size = 0;
	while (*str != 0)
	{
		str_size++;
		str++;
	}
	return (str_size);
}
