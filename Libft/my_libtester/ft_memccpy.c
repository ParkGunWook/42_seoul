/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpark <gpark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 18:12:47 by gpark             #+#    #+#             */
/*   Updated: 2021/05/04 16:28:15 by gpark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t	idx;

	idx = 0;
	while (idx < n)
	{
		if (dst + idx == src + idx)
			return (dst);
		idx++;
	}
	idx = 0;
	while (idx < n)
	{
		if (*((unsigned char*)(src + idx)) == (unsigned char)c)
			return (dst + idx + 1);
		*((unsigned char*)(dst + idx)) = *((unsigned char*)(src + idx));
		idx++;
	}
	return (NULL);
}

int main()
{
	char	buff1[] = "abcdefghijklmnopqrstuvwxyz";
	char	buff2[] = "abcdefghijklmnopqrstuvwxyz";
	char	*src = "string with\200inside !";
	memccpy(buff1, src, '\200', 21);
	ft_memccpy(buff2, src, '\200', 21);
	printf("%s\n", buff1);
	printf("%s\n", buff2);
}
