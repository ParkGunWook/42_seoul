/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpark <gpark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 23:30:09 by gpark             #+#    #+#             */
/*   Updated: 2021/05/04 21:19:14 by gpark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	while (*(src + i) != 0 && i + 1 < dstsize)
	{
		*(dst + i) = *(src + i);
		i++;
	}
	if (dstsize != 0)
		*(dst + i) = 0;
	while (*(src + i) != 0)
	{
		i++;
	}
	return (i);
}

int main(void)
{
	char	*str = "BBBB";
	char	buff1[0xF00];
	char	buff2[0xF00];

	memset(buff1, 'A', 20);
	memset(buff2, 'A', 20);
	buff1[20] = 0;
	buff2[20] = 0;
	size_t r1 = strlcpy(buff1, str, 0);
	size_t r2 = ft_strlcpy(buff2, str, 0);
	printf("%d\n", memcmp(buff1, buff2, 20));
	printf("%zu %zu\n", r1, r2);
	printf("%s\n", buff1);
	printf("%s\n", buff2);
}
