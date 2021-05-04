/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpark <gpark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 23:30:09 by gpark             #+#    #+#             */
/*   Updated: 2021/05/04 20:45:53 by gpark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	i;

	i = 0;
	while (*src != 0 && i + 1 < size)
	{
		*dest = *src;
		src++;
		dest++;
		i++;
	}
	if (size != 0)
		*dest = 0;
	while (*src != 0)
	{
		i++;
		src++;
	}
	return (i);
}
