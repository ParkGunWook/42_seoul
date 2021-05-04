/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpark <gpark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 18:46:17 by gpark             #+#    #+#             */
/*   Updated: 2021/05/04 20:24:54 by gpark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	idx;

	idx = 0;
	while (idx < n)
	{
		if (*(unsigned char*)(s1 + idx) != *(unsigned char*)(s2 + idx))
			return (*(unsigned char*)(s1 + idx) - *(unsigned char*)(s2 + idx));
		idx++;
	}
	return (0);
}
