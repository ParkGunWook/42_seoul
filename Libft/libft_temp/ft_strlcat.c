/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpark <gpark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 02:58:26 by gpark             #+#    #+#             */
/*   Updated: 2021/05/04 20:58:42 by gpark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;

	i = 0;
	while (*dest != 0)
	{
		dest++;
		i++;
	}
	if (i > size)
		i = size;
	while (i + 1 < size && *src != 0)
	{
		*dest++ = *src++;
		i++;
	}
	if (size != 0)
		*dest = 0;
	while (*src != 0)
	{
		src++;
		i++;
	}
	return (i);
}
