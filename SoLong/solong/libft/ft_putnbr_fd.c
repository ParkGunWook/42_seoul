/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpark <gpark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 04:26:23 by gpark             #+#    #+#             */
/*   Updated: 2021/05/05 04:35:34 by gpark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	void	ft_putnbr2_fd(int nb, int fd)
{
	int	remainder;

	remainder = nb % 10;
	nb /= 10;
	if (nb == 0)
	{
		ft_putchar_fd('0' + remainder, fd);
		return ;
	}
	ft_putnbr2_fd(nb, fd);
	ft_putchar_fd('0' + remainder, fd);
}

void			ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
		write(fd, "-2147483648", 11);
	else if (n >= 0)
		ft_putnbr2_fd(n, fd);
	else if (n < 0)
	{
		ft_putchar_fd('-', fd);
		ft_putnbr2_fd(-n, fd);
	}
}
