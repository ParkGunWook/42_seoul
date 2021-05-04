/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpark <gpark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 02:58:26 by gpark             #+#    #+#             */
/*   Updated: 2021/05/04 21:07:11 by gpark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

#define		STRING_1	"the cake is a lie !\0I'm hidden lol\r\n"
#define		STRING_4	"phrase differente pour le test"
#define		STRING_2	"there is no stars in the sky"
#define		STRING_3	"test basic !"

int main(void)
{
	char	*str = STRING_1;
	char	buff1[0xF00] = STRING_2;
	char	buff2[0xF00] = STRING_2;
	size_t	max = strlen(STRING_1) + 4;
	printf("max : %zu\n", max);
	size_t	r1 = strlcat(buff1, str, max);
	size_t	r2 = ft_strlcat(buff2, str, max);
	printf("%zu %zu \n", r1, r2);
	printf("%s\n", buff1);
	printf("%s\n", buff2);
}
