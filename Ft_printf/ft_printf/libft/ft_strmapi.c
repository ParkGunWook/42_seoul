/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpark <gpark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 03:48:06 by gpark             #+#    #+#             */
/*   Updated: 2021/05/05 03:55:57 by gpark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	s_len;
	size_t	idx;
	char	*new;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (!(new = (char*)malloc(sizeof(char) * (s_len + 1))))
		return (NULL);
	idx = 0;
	while (idx < s_len)
	{
		*(new + idx) = f(idx, *(s + idx));
		idx++;
	}
	new[idx] = 0;
	return (new);
}
