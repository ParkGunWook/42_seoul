/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpark <gpark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 02:58:26 by gpark             #+#    #+#             */
/*   Updated: 2021/05/04 22:14:59 by gpark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	idx;

	i = 0;
	while (*(dst + i) != 0)
	{
		i++;
	}
	if (i > dstsize)
		i = dstsize;
	idx = 0;
	while (i + 1 < dstsize && *(src + idx) != 0)
	{
		*(dst + i) = *(src + idx);
		i++;
		idx++;
	}
	if (i != dstsize)
		*(dst + i) = 0;
	while (*(src + idx) != 0)
	{
		idx++;
		i++;
	}
	return (i);
}

int main(void)
{
	char	*dest;
	dest = (char *)malloc(sizeof(*dest) * 15);
	memset(dest, 'r', 15);
	size_t a = ft_strlcat(dest, "lorem ipsum dolor sit amet", 5);
	printf("%zu\n", a);
	write(1, dest, 15);
	write(1, "\n", 1);
}
