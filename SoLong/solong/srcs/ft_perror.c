/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_perror.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpark <gpark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 20:56:18 by gpark             #+#    #+#             */
/*   Updated: 2021/06/10 21:04:17 by gpark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "myloc.h"
#include "solong.h"

void		ft_perror(int errcase)
{
	if (errcase < 0)
	{
		if (errcase == NOT_RECT)
			write(1, "NOT_RECT ERROR\n", 16);
		else if (errcase == INVALID_TILE)
			write(1, "INVALID_TILE ERROR\n", 20);
		else if (errcase == NOT_CLOSED)
			write(1, "NOT_CLOSED ERROR\n", 18);
		else if (errcase == MIN_TILE)
			write(1, "MIN_TILE ERROR\n", 16);
		else if (errcase == WRONG_EXTENSIONS)
			write(1, "WRONG_EXTENSIONS ERROR\n", 24);
		else if (errcase == WRONG_ARGUMENTS)
			write(1, "WRONG_ARGUMENTS ERROR\n", 23);
		else
			write(1, "WRONG ERROR\n", 13);
	}
	else
		perror(strerror(errno));
}
