/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_perror.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpark <gpark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 20:56:18 by gpark             #+#    #+#             */
/*   Updated: 2021/06/13 18:50:30 by gpark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void		ft_perror(int errcase)
{
	if (errcase < 0)
	{
		if (errcase == WRONG_ARGUMENTS)
			write(1, "WRONG_ARGUMENTS ERROR\n", 23);
		else
			write(1, "WRONG ERROR\n", 13);
	}
	else
		perror(strerror(errno));
}
