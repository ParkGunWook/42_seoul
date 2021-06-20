/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_perror.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpark <gpark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 20:56:18 by gpark             #+#    #+#             */
/*   Updated: 2021/06/20 11:05:40 by gpark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void		ft_perror(int errcase)
{
	if (errcase < 0)
	{
		if (errcase == WRONG_ARGUMENTS)
			write(2, "WRONG_ARGUMENTS ERROR\n", 23);
		else if (errcase == SPLIT_ERROR)
			write(2, "SPLIT_ERROR ERROR\n", 19);
		else if (errcase == NOT_VALID_EXE)
			write(2, "NOT_VALID_EXE ERROR\n", 21);
		else
			write(2, "WRONG ERROR\n", 13);
	}
	else
		perror(strerror(errno));
}
