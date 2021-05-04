/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpark <gpark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 14:12:57 by gpark             #+#    #+#             */
/*   Updated: 2021/05/04 15:49:37 by gpark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strdup(const char *s1)
{
	size_t		str_size;
	size_t		idx;
	char		*new;

	str_size = ft_strlen(s1);
	idx = 0;
	new = (char*)malloc(sizeof(char) * (str_size + 1));
	if (!new)
		return (NULL);
	while (idx < str_size)
	{
		*(new + idx) = *(s1 + idx);
		idx++;
	}
	*(new + idx) = 0;
	return (new);
}
